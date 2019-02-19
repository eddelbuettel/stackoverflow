#include <RInside.h>

int main(int argc, char *argv[]) {
    // define two vectors in C++
    std::vector<double> x({1.23, 2.34, 3.45});
    std::vector<double> y({2.34, 3.45, 1.23});
    // start R
    RInside R(argc, argv);
    // define a function in R
    R.parseEvalQ("rtest <- function(x, y) {x + y}");
    // transfer the vectors to R
    R["x"] = x;
    R["y"] = y;
    // call the function in R and return the result
    std::vector<double> z = R.parseEval("rtest(x, y)");
    std::cout << z[0] << std::endl;

    // move R function to C++
    Rcpp::Function rtest((SEXP) R.parseEval("rtest"));
    // call the R function from C++
    z = Rcpp::as<std::vector<double>>(rtest(x, y));
    std::cout << z[0] << std::endl;
    exit(0);
}
