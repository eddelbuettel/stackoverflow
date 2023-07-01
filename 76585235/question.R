p <- 100
M <- matrix(rnorm(p^2), nrow = p)

Rcpp::cppFunction(depends = "RcppEigen", '
    double eigen_det_cpp_cppfunction(const Eigen::Map<Eigen::MatrixXd> X, int n_cores) {
        Eigen::setNbThreads(n_cores);
        return X.determinant();
    }
')

.libPaths("lib")
library(testPkg)
library(microbenchmark)

res <- microbenchmark(within_package =  eigen_det_cpp(M, 1),
                      on_the_fly =      eigen_det_cpp_cppfunction(M, 1),
                      times = 10)
print(res)
