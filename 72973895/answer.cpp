#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
List updatingList(int n) {
    // Create a NumericMatrix that will be updated every step
    NumericMatrix mat(n, 2);
    for (int i=0; i < n; i++) { // set the initial state of the susceptible hosts
        mat(i,0) = 0; // initial Th1
        mat(i,1) = 1; // initial Th2
    }
    // create a List that will store mat every step
    List list(n);

    for (int j=0; j < n; j++) {
        // store a deep copy of mat
        list(j) = clone(mat);
        // update mat
        for (int i=0; i < n; i++) {
            mat(i,0) += 1;
            mat(i,1) += 1;
        }
    }
    return(list);
}

/*** R
updatingList(3)
*/
