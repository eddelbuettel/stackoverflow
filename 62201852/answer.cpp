#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericVector i2_to_the_power_j ( int64_t j )
{

  int64_t base = 1;
  int64_t value = base << j;

  // cout << "C++ value: " << value << "\n";

  // Create a vector of length 1 with `value` as the sole contents
  const   std::vector<int64_t> v(1, value);
  const size_t len = v.size();

  Rcpp::NumericVector nn(len);         // storage vehicle we return them in

  // transfers values 'keeping bits' but changing type
  // using reinterpret_cast would get us a warning
  std::memcpy(&(nn[0]), &(v[0]), len * sizeof(double));

  nn.attr("class") = "integer64";
  return nn;

  return value;
}

// [[Rcpp::export]]
Rcpp::NumericVector largeval ( ) {
  int64_t val = 9223372036854775807LL - 1;
  Rcpp::Rcout << "C++ value: " << val << "\n";
  Rcpp::NumericVector dbl(1);
  std::memcpy(&(dbl[0]), &val, sizeof(double));
  dbl.attr("class") = "integer64";
  return dbl;
}


/*** R
library(bit64)
# I can get 2^62
i2_to_the_power_j(62)

# ...but I cannot get 2^63
i2_to_the_power_j(63)

# I cannot get 2^63, despite bit64 package claiming it can
# handle integers of this size
bit64::lim.integer64()

largeval()
*/
