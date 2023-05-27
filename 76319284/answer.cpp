
#include <Rcpp/Rcpp>
#include <mlpack.h>

// Two include directories adjusted for my use of mlpack 3.4.2 on Ubuntu
#include <mlpack/core.hpp>
#include <mlpack/methods/kmeans/kmeans.hpp>
#include <mlpack/methods/kmeans/random_partition.hpp>
#include <mlpack/methods/neighbor_search/neighbor_search.hpp>

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::depends(mlpack)]]

// This is 'borrowed' from mlpack's own src/mlpack/tests/kmeans_test.cpp
// and src/mlpack/tests/kmeans_test.cpp. We borrow the data set, and the
// code from the first test function. Passing data from R in easy thanks
// to RcppArmadillo, 'and left as an exercise'.

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

    mlpack::kmeans::KMeans<mlpack::metric::EuclideanDistance, mlpack::kmeans::RandomPartition> kmeans;

    arma::Row<size_t> assignments;
    kmeans.Cluster((arma::mat) trans(kMeansData), 3, assignments);

    return assignments;
}

/*** R
kmeansDemo()
*/
