// [[Rcpp::depends(BH)]]

#include <Rcpp.h>
#include <boost/math/statistics/t_test.hpp>

// Performs a T test on the measurements according to the design (1s and 2s)
// and returns a P value.
// [[Rcpp::export]]
double designTTest(std::vector<double> ints, std::vector<double> design) {
    if (ints.size() != design.size()) Rcpp::stop("ERROR: DESIGN VECTOR AND MEASUREMENT VECTOR NOT EQUAL IN LENGTH!");
    std::vector<double> cIntensities, tIntensities;
    for (size_t i = 0; i < design.size(); i++) {
        if (design[i] == 1) {
            cIntensities.push_back(ints[i]);
        } else if (design[i] == 2) {
            tIntensities.push_back(ints[i]);
        } else {
            Rcpp::stop("ERROR: DESIGN SYMBOL IS NOT 1 OR 2!");
        }
    }

    auto [t, p] = boost::math::statistics::two_sample_t_test(cIntensities, tIntensities);
    return p;
}

/*** R
designTTest(c(1,2,1,2,1), c(2,1,2,1,2))
*/
