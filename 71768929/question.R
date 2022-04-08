
set.seed(124)
ro <- round(runif(n = 30,1,10),2)
dat <- as.data.frame(matrix(data = ro, ncol = 3))
colnames(dat) <- paste0("x", 1:ncol(dat))
rule <- c("x1 > 5 & x2/2 > 2", "x1 > x2*2", "x3 != 4")

res <- do.call(cbind, lapply(rule, \(r) with(dat, eval(parse(text=r)))))
