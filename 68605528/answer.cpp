#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericVector esat(Rcpp::NumericVector Tk) {
  Rcpp::NumericVector esat_out(Tk.size(), NAN);
  for (R_xlen_t i=0; i<Tk.size(); i++) {
    esat_out[i] = 6.1121 * Tk[i];
  }
  return esat_out;
}

// [[Rcpp::export]]
Rcpp::NumericVector h_evap(Rcpp::NumericVector Tk) {
  Rcpp::NumericVector h_evap_out(Tk.size(), NAN);
  Rcpp::NumericVector f_out = esat(Tk);
  for (R_xlen_t i=0; i<Tk.size(); i++) {
    h_evap_out[i] = (313.15 - Tk[i]);
    h_evap_out[i] = h_evap_out[i] + f_out[i];
  }
  return h_evap_out;
}

/*** R
esat(42)
h_evap(42)
*/
