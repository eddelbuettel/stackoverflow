#include <RcppEnsmallen.h>
// [[Rcpp::depends(RcppEnsmallen)]]

// [[Rcpp::export]]
void demofunc() {
    ens::test::RosenbrockFunction f;
    arma::mat coordinates = f.GetInitialPoint();

    ens::Adam optimizer(0.001, 32, 0.9, 0.999, 1e-8, 100000, 1e-5, true);
    optimizer.Optimize(f, coordinates);

    coordinates.print("Coordinates");
    Rcpp::Rcout << "Done\n";
}
