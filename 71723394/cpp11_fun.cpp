#include <cpp11.hpp>
#include <math.h>

using namespace cpp11;
using namespace std;

[[cpp11::register]]
doubles cpp11_fun(int Q, integers nbCluster) {
  int iter;

  int q;
  int sum_cases=0;
  writable::integers start(Q), end(Q);

  for(q=0 ; q<Q ; q++){
    // the total number of clusters (eg if man/woman and 10 countries: total of 12 cases)
    sum_cases += nbCluster(q);
    if(q == 0){
      start(q) = 0;
      end(q) = nbCluster(q);
    } else {
      start(q) = start(q-1) + nbCluster(q-1);
      end(q) = end(q-1) + nbCluster(q);
    }
  }

  return(q);
}
