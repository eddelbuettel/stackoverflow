#include <Rcpp.h>
#include <omp.h>

// [[Rcpp::plugins(openmp)]]

// [[Rcpp::export]]
int foo() {

    int th_id, nthreads;

#pragma omp parallel private(th_id)
    {
        th_id = omp_get_thread_num();
        std::ostringstream ss;  // allow for better synchronization
        ss << "Hello World from thread " << th_id << std::endl;
        Rcpp::Rcout << ss.str();
#pragma omp barrier
#pragma omp master
        {
            nthreads = omp_get_num_threads();
            Rcpp::Rcout << "There are " << nthreads << " threads" << std::endl;
        }
    }
    return 0;
}

/*** R
foo()
*/
