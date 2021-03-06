// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// triple_balance
NumericVector triple_balance(const NumericVector& balance);
RcppExport SEXP _so62061935_triple_balance(SEXP balanceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type balance(balanceSEXP);
    rcpp_result_gen = Rcpp::wrap(triple_balance(balance));
    return rcpp_result_gen;
END_RCPP
}
// triple_balance_orig
double triple_balance_orig(const double& balance);
RcppExport SEXP _so62061935_triple_balance_orig(SEXP balanceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const double& >::type balance(balanceSEXP);
    rcpp_result_gen = Rcpp::wrap(triple_balance_orig(balance));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_hello_world
List rcpp_hello_world();
RcppExport SEXP _so62061935_rcpp_hello_world() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(rcpp_hello_world());
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_so62061935_triple_balance", (DL_FUNC) &_so62061935_triple_balance, 1},
    {"_so62061935_triple_balance_orig", (DL_FUNC) &_so62061935_triple_balance_orig, 1},
    {"_so62061935_rcpp_hello_world", (DL_FUNC) &_so62061935_rcpp_hello_world, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_so62061935(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
