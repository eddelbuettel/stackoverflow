
#include <Rcpp.h>

void consumeConstChar(std::vector<const char*> v) {
  for (auto s : v) Rcpp::Rcout << s << std::endl;
}

void consumeChar(std::vector<char*> v) {
  for (auto s : v) Rcpp::Rcout << s << std::endl;
}

// [[Rcpp::export]]
void doStuff(Rcpp::StringVector x) {
  std::vector<const char*> vcc;
  std::vector<char*> vc;
  for (int i=0; i<x.size(); i++) {
    vcc.push_back(x[i]);
    vc.push_back(x[i]);
  }
  consumeConstChar(vcc);
  consumeChar(vc);
}

/*** R
x <- c("The quick", "brown", "fox", "jumped")
doStuff(x)
*/
