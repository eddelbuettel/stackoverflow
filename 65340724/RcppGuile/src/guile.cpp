#include <Rcpp.h>
#include <stdio.h>
#include <libguile.h>

using namespace Rcpp;

// [[Rcpp::export]]
int test_guile(std::string file) {
    SCM func, func2;
    scm_init_guile();

    scm_c_primitive_load(file.c_str());

    //func = scm_variable_ref(scm_c_lookup("simple-func"));
    //func2 = scm_variable_ref(scm_c_lookup("quick-test"));

    //scm_call_0(func);
    //scm_call_0(func2);

    return 0;
}
