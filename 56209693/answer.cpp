#include <Rcpp.h>

// [[Rcpp::export]]
void foo() {

#ifdef DEBUG
  Rcpp::Rcout << "foo: Debug mode" << std::endl;
#endif

  Rcpp::Rcout << "foo: Hello, world" << std::endl;
}

#define DEBUG 1

// [[Rcpp::export]]
void bar() {

#ifdef DEBUG
  Rcpp::Rcout << "bar: Debug mode" << std::endl;
#endif

  Rcpp::Rcout << "bar: Hello, world" << std::endl;
}

// follow the trick in https://stackoverflow.com/questions/24275714/
#ifdef NDEBUG
# define NDEBUG_DISABLED
# undef NDEBUG
#endif
#include <cassert>

#ifdef NDEBUG_DISABLED
# define NDEBUG        // re-enable NDEBUG if it was originally enabled
#endif

// [[Rcpp::export]]
void biz() {

#ifdef DEBUG
  Rcpp::Rcout << "biz: Debug mode" << std::endl;
#endif
assert(2==1+1);

  Rcpp::Rcout << "biz: Hello, world" << std::endl;
}


/*** R
foo()
bar()
biz()
*/
