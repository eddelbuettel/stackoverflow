// [[Rcpp::plugins(cpp11)]]

#include <Rcpp.h>
#include <cmath>
#include <vector>

using namespace Rcpp;

// [[Rcpp::export]]
double meanC(NumericVector x) {
    int n = x.size();
    double total = 0;
    for(int i = 0; i < n; ++i) total += x[i];
    return total / n;
}


// [[Rcpp::export]]
NumericVector Vols(const float sampling_rate, NumericVector Vol) {
    const int N = Vol.size();
    const float hours_f = (60.0f * N) / 3600.0f;
    const int hours = std::ceil(hours_f);
    const int subarr_size = 60;

    std::vector<double> f_vol = as< std::vector<double> >(Vol);
    std::vector<double> sub_arr[subarr_size];

    NumericVector res(subarr_size);
    // each iteration of this loop process next set of n elements
    // and store it in a vector at k'th index in result
    for (size_t k = 0; k < subarr_size; ++k) {
        // get range for next set of n elements
        auto start_itr = std::next(f_vol.cbegin(), k*hours);
        auto end_itr = std::next(f_vol.cbegin(), k*hours + hours);

        // allocate memory for the sub-vector
        sub_arr[k].resize(hours);

        // code to handle the last sub-vector as it might
        // contain less elements

        // edd: if we comment this out the run-time error disappears
        //if (k*hours + hours > f_vol.size()) {
        //    end_itr = f_vol.cend();
        //    sub_arr[k].resize(f_vol.size() - k*hours);
        //}

        // copy elements from the input range to the sub-vector
        std::copy(start_itr, end_itr, sub_arr[k].begin());
    }

    // take mean of each sub array
    for (int i = 0; i < subarr_size; ++i) {
        res[i] = meanC(wrap(sub_arr[i]));
    }

    return res;
}
/*** R
s <- 60
v <- c(43000, 43100, 43123, 43234, 43333, 43500, 43600)
Vols(s, v)
*/
