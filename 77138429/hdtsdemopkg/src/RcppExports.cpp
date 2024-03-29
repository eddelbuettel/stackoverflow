// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// BStestby
arma::vec BStestby(const arma::mat& y1, const arma::mat& y2);
RcppExport SEXP _hdtsdemopkg_BStestby(SEXP y1SEXP, SEXP y2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type y1(y1SEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type y2(y2SEXP);
    rcpp_result_gen = Rcpp::wrap(BStestby(y1, y2));
    return rcpp_result_gen;
END_RCPP
}
// CQtest
arma::vec CQtest(const arma::mat& y1, const arma::mat& y2);
RcppExport SEXP _hdtsdemopkg_CQtest(SEXP y1SEXP, SEXP y2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type y1(y1SEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type y2(y2SEXP);
    rcpp_result_gen = Rcpp::wrap(CQtest(y1, y2));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_hdtsdemopkg_BStestby", (DL_FUNC) &_hdtsdemopkg_BStestby, 2},
    {"_hdtsdemopkg_CQtest", (DL_FUNC) &_hdtsdemopkg_CQtest, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_hdtsdemopkg(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
