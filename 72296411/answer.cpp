
#include <Rcpp.h>
#include <random>
#include <algorithm>

// [[Rcpp::export]]
Rcpp::IntegerVector shuffle_cpp(Rcpp::IntegerVector x)  {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(x.begin(), x.end(), g);
    return x;
}

// [[Rcpp::export]]
Rcpp::IntegerVector sample_rcpp(Rcpp::IntegerVector x)  {
    return sample(x, x.size());
}

/*** R
v <- seq(1, 1e6)
res <- bench::mark(min_iterations = 100, check = FALSE, shuffle_cpp(v), sample_rcpp(v))
res
ggplot2::autoplot(res) + ggplot2::theme_minimal() + ggplot2::ylab(NULL)
*/
