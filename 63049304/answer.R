library(Rcpp)
cppFunction("int doubleMe(int x) { return x + x; }")
doubleMe(21)
doubleMe("this won't work")
