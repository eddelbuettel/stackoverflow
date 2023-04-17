
#include <Rcpp/Light>

// [[Rcpp::export]]
bool checkAnswer() {
    Rcpp::Function f("theAnswer");
    int val = Rcpp::as<int>(f());
    return val == 42;
}
