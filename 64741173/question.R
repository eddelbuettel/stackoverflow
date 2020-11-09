library(MASS)
library(Matrix)
library(Rcpp)
sourceCpp("MatMultFunc.cpp")
nreps <- 50
p <- 500
nSeq <- seq(80, 300, by = 20)
storeTime <- matrix(0, nreps, length(nSeq))
set.seed(1)

for (replicate in 1:nreps) {
  for (n in nSeq) {

    X <- matrix(rnorm(n*p), nrow = n)
    l <- n*(n-1)/2
    D <- matrix(0, nrow = l, ncol = n)

    counter <- 1
    for (j in 1:(n-1)) {
      for (k in (j+1):n) {
          D[counter, j] <- 1
          D[counter, k] <- -1
          counter <- counter + 1
      }
    }


    D <- Matrix(D, sparse=TRUE)

    Beta <- rep(0, p)
    Beta[sample(1:p, 50)] <- 1
    Beta <- Matrix(Beta, sparse = TRUE)

    ptm <- proc.time()
    RcppMatProds <- MatMultFunc(D, X, Beta)
    t0 <- proc.time() - ptm

    storeTime[replicate, which(nSeq == n)] <- t0[3]

    cat("Replicate: ", replicate, "; n = ", n,"\n")

  }
}

plot(nSeq, colMeans(storeTime), type = "l", ylab="Average runtime in seconds", xlab="n")
