// [[Rcpp::plugins(cpp17)]]
#include <boost/math/special_functions/beta.hpp>
// [[Rcpp::depends(BH)]]
#include <Rcpp.h>
using namespace Rcpp;


// Compute the regularized incomplete Beta function.
// [[Rcpp::export]]
NumericVector RIBF(NumericVector q, NumericVector a, NumericVector b,
                   bool useboost = false)
{
  NumericVector rst(q.size());
  for (int i = 0, iend = q.size(); i < iend; ++i)
  {
    if (useboost) rst[i] = boost::math::ibeta( a[i], b[i], q[i] );
    else          rst[i] = R::pbeta( q[i], a[i], b[i], 1, 0 );
  }
  return rst;
}

/*** R

set.seed(123)
N = 300000L
q = runif(N) # Generate quantiles.
a = runif(N, 0, 10) # Generate a in (0, 10)
b = runif(N, 0, 10) # Generate b in (0, 10)


# Use R's pbeta(). This function calls a C wrapper of toms708.c:
#   https://svn.r-project.org/R/trunk/src/nmath/toms708.c
system.time({ Rrst = RIBF(q, a, b, useboost = F) })
# Windows 10 (seconds):
# user  system elapsed
# 0.11    0.00    0.11

# RedHat Linux:
# user  system elapsed
# 0.097   0.000   0.097


# Use Boost's implementation, which also depends on TOMS 708 by their claim:
# https://www.boost.org/doc/libs/1_41_0/libs/math/doc/sf_and_dist/html/math_toolkit/special/sf_beta/ibeta_function.html
system.time({ boostRst = RIBF(q, a, b, useboost = T) })
# Windows 10:
# user  system elapsed
# 0.52    0.00    0.52

# RedHat Linux:
# user  system elapsed
# 0.988   0.001   0.993

summary(Rrst - boostRst)

*/
