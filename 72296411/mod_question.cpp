
#include <Rcpp.h>
#include <random>
#include <algorithm>

using namespace Rcpp;

// [[Rcpp::export]]
List test_cpp(int n, int x)  {
    List return_list(n);

    std::vector<int> v;
    v.reserve(x);

    for(int i = 0; i < x; ++i) {
        v.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());

    for(int i = 0; i < n; ++i)  {
        std::shuffle(v.begin(), v.end(), g);
        return_list(i) = v;
    }

    return return_list;
}


// [[Rcpp::export]]
Rcpp::IntegerVector shuffle_cpp(IntegerVector x)  {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(x.begin(), x.end(), g);
    return x;
}

// [[Rcpp::export]]
Rcpp::IntegerVector sample_rcpp(IntegerVector x)  {
    IntegerVector v = sample(x, x.size());
    return v;
}

/*** R
n <- 1000
x <- 999
#speed <- bench::mark(min_iterations = 100, check = FALSE,
#                     cpp = test_cpp(n, x),
#                     rcpp = test_r(n, x))
#speed
#ggplot2::autoplot(speed) + ggplot2::theme_minimal() + ggplot2::xlab(NULL) +
ggplot2::ylab(NULL)

v <- seq(1, 1e6)
res <- bench::mark(min_iterations = 100, check = FALSE,
                   shuffle_cpp(v),
                   sample_rcpp(v))
res
ggplot2::autoplot(res) + ggplot2::theme_minimal()

*/
