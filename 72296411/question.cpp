
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
List test_r(int n,
            int x)  {

  List return_list(n);

  std::vector<int> v;
  v.reserve(x);

  for(int i = 0; i < x; ++i){
      v.push_back(i);
    }

  IntegerVector vs = wrap(v);

  for(int i = 0; i < n; ++i)  {
    IntegerVector s_v = sample(vs, v.size());
    std::vector<int> s_v_c = as<std::vector<int>>(s_v);
    return_list(i) = s_v_c;
  }

  return return_list;
}

/*** R
n <- 1000
x <- 999

speed <- bench::mark(min_iterations = 100,
                       check = FALSE,
                       cpp = test_cpp(n, x),
                       rcpp = test_r(n, x)
                       )

  ggplot2::autoplot(speed) +
    ggplot2::theme_minimal() +
    ggplot2::xlab(NULL) +
    ggplot2::ylab(NULL)
*/
