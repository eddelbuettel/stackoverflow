code='
#include <Rcpp.h>
using namespace Rcpp;
class MyModel{  public: MyModel(const Rcpp::NumericVector& ModelData) {};};
RCPP_MODULE(MyModel){
    Rcpp::class_<MyModel>(\"MyModel\")
    .constructor<const Rcpp::NumericVector &>()
    ;
}'

inline::cxxfunction(code=code, verbose=TRUE, rebuild = T)
