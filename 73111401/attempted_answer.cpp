// [[Rcpp::depends(RcppArmadillo, RcppParallel)]]
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <RcppArmadillo.h>
#include <RcppParallel.h>
using namespace RcppParallel;

//[[Rcpp::export]]

std::vector<double> allwhich_ts(std::vector<double> vector, double value) {
    int length = vector.size();
    std::vector<double> values(0);
    for(int i = 0; i < length; i++){
        bool match = vector[i] == value;
        if (match) {
            values.push_back(i);
        }
    }
    return(values);
}

//[[Rcpp::export]]
std::vector<double> vector_addition(std::vector<double> vector1,
                                    std::vector<double> vector2) {
    int n_elements = vector1.size();
    std::vector<double> output_vec = std::vector<double>(n_elements);
    for (int i = 0; i < n_elements; i++) {
        output_vec[i] = vector1[i] + vector2[i];
    }
    return(output_vec);
}

struct vector_addition_worker : public Worker {
    const RVector<double> vector1;
    const RVector<double> vector2;
    const RVector<double> vector_indices;
    const int vector_length;

    RVector<double> output_vec;

    vector_addition_worker(const Rcpp::NumericVector& vector1,
                           const Rcpp::NumericVector& vector2,
                           const Rcpp::NumericVector& vector_indices,
                           const int& vector_length,
                           Rcpp::NumericVector& output_vec)
                           : vector1(vector1),
                             vector2(vector2),
                             vector_indices(vector_indices),
                             vector_length(vector_length),
                             output_vec(output_vec) {}

    std::vector<double> convert_input_vec(RVector<double> input_vector, int vec_length){
        RVector<double> tmp_vector = input_vector;
        std::vector<double> input_vector_ts(tmp_vector.begin(), tmp_vector.end());
        return(input_vector_ts);
    }

    void operator()(std::size_t begin, std::size_t end){
        std::vector<double> vector1_ts = convert_input_vec(vector1, vector_length);
        std::vector<double> vector2_ts = convert_input_vec(vector2, vector_length);
        std::vector<double> vector_indices_ts = convert_input_vec(vector_indices, vector_length);

        for(unsigned int i = begin; i < end; i++){
            std::vector<double> indices = allwhich_ts(vector_indices_ts, i);
            int values_begin = indices.at(1);
            int values_end = indices.at(std::distance(indices.begin(), indices.end()));

            std::vector<double> values1(vector1_ts.begin() + values_begin, vector1_ts.begin() + values_end);
            std::vector<double> values2(vector2_ts.begin() + values_begin, vector2_ts.begin() + values_end);

            std::vector<double> interim_op = vector_addition(values1, values2);
            int op_size = interim_op.size();
            for(int n = 0; n < op_size; n++){
                output_vec[i*op_size + n] = interim_op[n];
            }
        }
    }
};

//[[Rcpp::export]]
Rcpp::NumericVector vector_addition_parallel(Rcpp::NumericVector vec1,
                                             Rcpp::NumericVector vec2,
                                             Rcpp::NumericVector vec_ind){

    int vec_length = vec1.size();
    Rcpp::Rcout << vec_length << std::endl;
    double n_indices = *std::max_element(vec_ind.begin(), vec_ind.end());
    Rcpp::Rcout << n_indices << std::endl;
    Rcpp::NumericVector op_vec(vec_length);

    vector_addition_worker vec_add_worker(vec1, vec2, vec_ind, vec_length, op_vec);
    parallelFor(0, n_indices, vec_add_worker);
    return(op_vec);
}
