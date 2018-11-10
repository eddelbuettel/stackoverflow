// [[Rcpp::depends(BH)]]
#include <Rcpp.h>
#include <boost/multiprecision/float128.hpp>

namespace mp = boost::multiprecision;

// [[Rcpp::export]]
std::string qexp(double da = -1500.0, double db = -1501.0) {
    mp::float128 a(da), b(db);
    mp::float128 res = mp::exp(a) / (mp::exp(a) + mp::exp(b));
    return res.convert_to<std::string>();
}


/*** R
qexp()
*/
