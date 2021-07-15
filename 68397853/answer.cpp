
#include <Rcpp.h>

// [[Rcpp::export]]
bool contains(std::string s, Rcpp::List L) {
    Rcpp::CharacterVector nv = L.names();
    for (int i=0; i<nv.size(); i++) {
        if (std::string(nv[i]) == s) {
            return true;
        }
    }
    return false;
}

/*** R
l <- list(aa="a", bb=1.23, cc=LETTERS[1:4])
contains("aaa", l) # false
contains("bb", l)  # true
*/
