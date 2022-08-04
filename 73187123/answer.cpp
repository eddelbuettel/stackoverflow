
#include <Rcpp/Lightest> // Rcpp 1.0.8 or newer

// [[Rcpp::export]]
std::string getFile() {
    const std::string filename = __FILE__;
    return filename;
}

/*** R
getFile()
*/
