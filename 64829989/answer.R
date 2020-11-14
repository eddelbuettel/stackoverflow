library(inline)

increment <- cfunction(c(a = "integer"), "
  INTEGER(a)[0]++;
  return R_NilValue;
")

print_one = function(){
  one = 0L
  increment(one)
  print(one)
}

print_one() # prints 1
print_one() # prints 2

Rcpp::cppFunction("void increment2(int a) { a++; }")

print_two <- function(){
  two <- 0L
  increment2(two)
  print(two)
}

print_two() # prints 0
print_two() # prints 0
