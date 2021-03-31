#include <Rcpp.h>

// [[Rcpp::export]]
bool contains(std::vector<std::string> sv, std::string txt) {
  for (auto s: sv) {
    if (s == txt) return true;
  }
  return false;
}

/*** R
sv <- c("a", "b", "c")
contains(sv, "foo")
sv[2] <- "foo"
contains(sv, "foo")
*/
