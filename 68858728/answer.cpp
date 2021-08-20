
#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::List mysplit(Rcpp::NumericVector nums, int n, int size) {
    std::vector<std::vector<double>> result(n);
    int i = 0;
    auto beg = nums.cbegin();
    auto end = nums.cend();

    while (beg != nums.cend()) {
        //get end iterator safely
        auto next = std::distance(beg, end) >= size ? beg + size : end;
        //insert into result
        result[i].insert(result[i].end(), beg, next);
        //advance iterator
        beg = next;
        i = (i + 1) % n;
    }

    Rcpp::List ll;
    for (const auto&v : result)
        ll.push_back(v);

    return ll;
}

/*** R
testvec <- 1:12
mysplit(testvec, 2, 3)
*/
