set.seed(1)

N <- 1e6
V <- runif(N)
v1 <- V > 0.1
v2 <- V > 0.4
v3 <- V > 0.9

install.packages("microbenchmark")

mb_res_le <- microbenchmark::microbenchmark(times = 100, unit = "ms", v1 & v2 & v3, v3 & v2 & v1)
print(mb_res_le)

#ggplot2::autoplot(mb_res_le)
