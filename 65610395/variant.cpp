#include <stdint.h>
#include <Rcpp.h>
#include <Rcpp/unwindProtect.h>
// [[Rcpp::plugins(unwindProtect)]]

class MyObj {
public:
    int val;
    MyObj(int val) : val(val) {};
    ~MyObj() {
        std::cout << "I' being destructed - value was: " << val << std::endl;
    }
};

struct NumVecArgs {
    size_t size;
    double fillwith;
};

SEXP alloc_NumVec(void *data)
{
    NumVecArgs *args = (NumVecArgs*)data;
    return Rcpp::NumericVector(args->size, args->fillwith);
}

// [[Rcpp::export]]
Rcpp::NumericVector crashme() {
    MyObj obj1(R::runif(1,INT_MAX));
    NumVecArgs args = {INT64_MAX-1, 100.};
    Rcpp::NumericVector out = Rcpp::unwindProtect(alloc_NumVec, (void*)&args);
    return out;
}

/*** R
set.seed(123)
crashme()
*/
