#include <cpp11.hpp>
#include <cpp11/doubles.hpp>
#include <cpp11/logicals.hpp>

using namespace cpp11;

[[cpp11::register]] logicals fun_with_errors(doubles x) {
    int n = x.size();
    int m = 3; // just to create an incomplete loop

    writable::logicals y(n);

    // here I forgot to fill x with 0s

    for (int i = 0; i < m; ++i) { // here I put m instead of n to skip some elements
        if(x[i] > 0) {
            y[i] = true;
        } else {
            y[i] = false;
        }
    }
    return y;
}

// run with
//   cpp11::cpp_source("~/git/stackoverflow/75923413/question.cpp")
//   fun_with_errors(c(1,-1,1,-1,1))
//
