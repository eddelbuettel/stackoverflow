#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
List test_bug(int N) {

    std::vector<int>    inds;
    std::vector<double> vals;

    for (int k = 0; k < N; k++) {
        int i_k = k;
        double x_k = k;
        inds.push_back(i_k);
        vals.push_back(x_k);
    }

    return List::create(wrap(inds), wrap(vals));
}

/*** R
for (k in 1:100) {
    if (k %% 10 == 0) print(k)
    test <- test_bug(1000000)
}
*/
