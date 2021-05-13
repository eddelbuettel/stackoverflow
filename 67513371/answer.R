
library(Rcpp)
cppFunction("DatetimeVector xtsIndex(NumericMatrix X) { return DatetimeVector(wrap(X.attr(\"index\"))); } ")
xx <- xts(1:10, order.by = as.POSIXct(seq.Date(Sys.Date(), by = "day", length.out = 10)))
head(xx)
head(xtsIndex(xx))
head(xx)
