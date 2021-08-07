sourceCpp(code = '
#include <Rcpp.h>
#include <omp.h>
using namespace Rcpp ;

// [[Rcpp::export]]
int test() {

#pragma omp parallel for
int foo = omp_get_num_threads() ;
for(int i = 0; i < 2; i++) {
  Rcout << i ;
}
return foo ;

}')
