#include <stdint.h>
#include <Rcpp.h>

class MyObj {
public:
    int val;
    MyObj(int val) : val(val) {};
    ~MyObj() {
        std::cout << "I' being destructed - value was: " << val << std::endl;
    }
};

// [[Rcpp::export]]
Rcpp::NumericVector crashme(unsigned int seed)
{
    srand(seed);
    MyObj obj1(rand());
    Rcpp::NumericVector out(INT64_MAX-1, 100.);
    return out;
}
