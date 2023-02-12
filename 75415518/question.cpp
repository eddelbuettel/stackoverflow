#include <Rcpp.h>
#include <RcppParallel.h>

// [[Rcpp::depends(RcppParallel)]]

using namespace RcppParallel;
using namespace Rcpp;

struct SquareRootPlus : public Worker
{
  // source vector etc
  const RVector<double> input;
  const double constParam;

  // destination vector
  RVector<double> output;

  // initialize with source and destination
  // get the data type correctly unless auto promoted/cast
  SquareRootPlus(const Rcpp::NumericVector input, const double constParam, Rcpp::NumericVector output)
    : input(input), constParam(constParam), output(output) {}

  struct sqrt_wrapper {  // describe worker function
    public: double operator()(double a, double cp) {
      return ::sqrt(a) * cp;
    }
  };

  // take the square root of the range of elements requested
  // (and multiply it by the constant)
  void operator()(std::size_t begin, std::size_t end) {
    std::transform(input.begin() + begin,
                   input.begin() + end,
                   output.begin() + begin,
                   sqrt_wrapper());
  }
};

// public called routine
// [[Rcpp::export]]
Rcpp::NumericVector paralleVectorSqrt(Rcpp::NumericVector x, double c) {
  // allocate the output matrix
  Rcpp::NumericVector output(x.length());
  // SquareRoot functor (pass input and output matrixes)
  SquareRootPlus squareRoot(x, c, output);
  // call parallelFor to do the work
  parallelFor(0, x.length(), squareRoot);
  // return the output matrix
  return output;
}
