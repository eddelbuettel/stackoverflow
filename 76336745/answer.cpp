#include <Rcpp/Rcpp>
#include <mlpack.h>

#include <mlpack/methods/kmeans.hpp>

// -- use C++17
// [[Rcpp::plugins(cpp17)]]
// -- use Armadillo, Ensmallen and mlpack headers
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::depends(RcppEnsmallen)]]
// [[Rcpp::depends(mlpack)]]

// This is 'borrowed' from mlpack's own src/mlpack/tests/kmeans_test.cpp

// Generate dataset; written transposed because it's easier to read.
arma::mat kMeansData("  0.0   0.0;" // Class 1.
                     "  0.3   0.4;"
                     "  0.1   0.0;"
                     "  0.1   0.3;"
                     " -0.2  -0.2;"
                     " -0.1   0.3;"
                     " -0.4   0.1;"
                     "  0.2  -0.1;"
                     "  0.3   0.0;"
                     " -0.3  -0.3;"
                     "  0.1  -0.1;"
                     "  0.2  -0.3;"
                     " -0.3   0.2;"
                     " 10.0  10.0;" // Class 2.
                     " 10.1   9.9;"
                     "  9.9  10.0;"
                     " 10.2   9.7;"
                     " 10.2   9.8;"
                     "  9.7  10.3;"
                     "  9.9  10.1;"
                     "-10.0   5.0;" // Class 3.
                     " -9.8   5.1;"
                     " -9.9   4.9;"
                     "-10.0   4.9;"
                     "-10.2   5.2;"
                     "-10.1   5.1;"
                     "-10.3   5.3;"
                     "-10.0   4.8;"
                     " -9.6   5.0;"
                     " -9.8   5.1;");


// [[Rcpp::export]]
arma::Row<size_t> kmeansDemo() {

    // Originally written to use RandomPartition, and is left that
    // way because RandomPartition gives better initializations here.
    mlpack::KMeans<mlpack::EuclideanDistance, mlpack::RandomPartition> kmeans;

    // mlpack::KMeans<> kmeans;    // default arguments as an alternative

    arma::Row<size_t> assignments;
    kmeans.Cluster((arma::mat) trans(kMeansData), 3, assignments);

    return assignments;
}

/*** R
kmeansDemo()
*/
