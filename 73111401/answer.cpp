// [[Rcpp::depends(RcppArmadillo, RcppParallel)]]
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <RcppArmadillo.h>
#include <RcppParallel.h>
using namespace RcppParallel;

// [[Rcpp::export]]
std::vector<double> allwhich_ts(std::vector<double> vector, double value){
    int length = vector.size();
    std::vector<double> values(length);
    int matches = 0;
    for(int i = 0; i < length; i++){
        bool match = vector[i] == value;
        if(match){values[matches] = i;
            matches++;
        }
    }
    std::vector<double> op(values.begin(), values.begin() + matches);
    return(op);
}

struct vector_double_worker : public Worker {
    // Defining worker arguments
    const RVector<double> vector1;
    const RVector<double> vector_indices;
    const RVector<double> unique_indices;
    const int vector_length;
    RVector<double> output_vec;

    // Initialising function argument values
    vector_double_worker(const Rcpp::NumericVector& vector1,
                         const Rcpp::NumericVector& vector_indices,
                         const Rcpp::NumericVector& unique_indices,
                         const int& vector_length,
                         Rcpp::NumericVector& output_vec) :
        vector1(vector1),
        vector_indices(vector_indices),
        unique_indices(unique_indices),
        vector_length(vector_length),
        output_vec(output_vec) {}

    // Setting up conversion function so that UDFs can deal in std:: types
    std::vector<double> convert_input_vec(RVector<double> input_vector, int vec_length){
        std::vector<double> input_vector_ts(input_vector.begin(), input_vector.end());
        return(input_vector_ts);
    }
    // Defining operator ranges which will breakdown the task into partitions
    void operator()(std::size_t begin, std::size_t end){
        // Converting input vectors to std types
        std::vector<double> vector1_ts = convert_input_vec(vector1, vector_length);
        std::vector<double> vector_indices_ts = convert_input_vec(vector_indices, vector_length);
        // For loop to perform calculations for each element in a given partition
        for(unsigned int i = begin; i < end; i++){
            int index_value = unique_indices[i]; // begin and end now used to index the vector of input indices defined outside of the function
            std::vector<double> indices = allwhich_ts(vector_indices_ts, index_value); // identifying sub-vector indices
            int values_begin = indices.at(0);
            int values_end = indices.at(std::distance(indices.begin(), indices.end()) - 1); // - 1 was added to avoid dimension error
            std::vector<double> values1(vector1_ts.begin() + values_begin, vector1_ts.begin() + values_end + 1); // + 1 was added to avoid dimension error
            int op_size = values1.size();
            for(int n = 0; n < op_size; n++){
                output_vec[i*op_size + n] = values1[n] * 2;
            } // Trivial example calculation
        }
    }
};

// [[Rcpp::export]]
Rcpp::NumericVector vector_double_parallel(Rcpp::NumericVector vec1, Rcpp::NumericVector vec_ind){
    int vec_length = vec1.size(); // Setting up output vector
    Rcpp::NumericVector op_vec(vec_length);
    double n_indices = *std::max_element(vec_ind.begin(), vec_ind.end()); // Identifying unique index values
    double min_indices = *std::min_element(vec_ind.begin(), vec_ind.end());
    Rcpp::NumericVector unique_indices(n_indices);
    std::iota(unique_indices.begin(), unique_indices.end(), min_indices);
    vector_double_worker vec_2_worker(vec1,vec_ind,unique_indices,vec_length,op_vec); // Setting up parallel worker
    parallelFor(0, n_indices, vec_2_worker); // Populating output vector with results
    return(op_vec);
}
