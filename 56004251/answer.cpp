#include <Rcpp.h>
using namespace Rcpp;

class MyModel {
public:
  double a;
  ~MyModel();
  MyModel();
  MyModel(const Rcpp::NumericVector ModelData, int temp);
};

RCPP_EXPOSED_CLASS(MyModel)

MyModel::~MyModel() {}
MyModel::MyModel() : a(0) {}
MyModel::MyModel(const Rcpp::NumericVector ModelData, int temp) : a(0) {}

RCPP_MODULE(MyModel) {
  Rcpp::class_<MyModel>("MyModel")
  .constructor()
  .constructor<const Rcpp::NumericVector, int>()
  ;
}
