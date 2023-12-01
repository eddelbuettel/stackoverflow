
Rcpp::cppFunction("int ll(List L) { return L.length(); }")
ll(letters)
# [1] 26
ll(NULL)
# [1] 0
