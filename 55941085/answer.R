library(Rcpp)

sourceCpp(code='
#include <Rcpp.h>
#include <cstdio>

struct MyStruct {
public:

    bool boolVar;

    explicit MyStruct(bool t_boolVar=false) : boolVar(t_boolVar) {}

    void print() const {
        printf("C++ Value: %s\\n", boolVar ? "TRUE" : "FALSE");
    }
};

// [[Rcpp::export]]
int myFunc(const Rcpp::List &myList) {
    MyStruct myStruct(Rcpp::as<bool>(myList["boolVar"]));
    myStruct.print();
    return 0;
}
')

testFunc <- function(boolVar=FALSE) {
    print(paste("R value:", boolVar))
    myList <- list("boolVar"=boolVar)
    myFunc(myList)
}

testFunc()
testFunc(TRUE)
testFunc(FALSE)

sessionInfo()
system('uname -a')
