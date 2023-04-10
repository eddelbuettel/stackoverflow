
#include <Rcpp.h>
#include <algorithm>

//using namespace Rcpp;
//using namespace std;


/*
    Find ordered nearest neighbors based on a correlation Matrix.
    Assuming the absolute value of the correlation is monotonically
    decreasing with distance.
    Returns an n X (m + 1) matrix similar to `GpGp::find_ordered_nn`.
*/
// [[Rcpp::export]]
Rcpp::IntegerMatrix find_nn_corr(const Rcpp::NumericMatrix &corrMat, int m){
    int n = corrMat.rows();
    Rcpp::IntegerMatrix NN(n, m + 1);
    NN.fill(NA_INTEGER);
    NN(0, 0) = 0;
    for(int i = 1; i < n; i++){
        int *order = new int[i + 1];
        std::iota(order, order + i + 1, 0);
        std::sort(order, order + i + 1, [&corrMat, &i](int &j, int &k){
            return corrMat(j, i)>=corrMat(k, i); });
        for(int j = 0; j < std::min(m + 1, i + 1); j++)
            NN(i, j) = order[j];
        delete[] order;
    }
    return NN;
}

/*** R
#Rcpp::sourceCpp("find_nn_corr.cpp")
set.seed(123)
n <- 100
some_matrix <- matrix(runif(n * n), n , n)
cov_mat <- some_matrix %*% t(some_matrix)
sd_vec <- sqrt(diag(cov_mat))
corr_mat <- t(t(some_matrix / sd_vec) / sd_vec)
m <- 10
NNarray <- find_nn_corr(cov_mat, m)
print(NNarray)
*/
