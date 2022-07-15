
rwR <- function(n = 10000) {
    ones <- rep(1, n)
    s1 <- ones %*% matrix(c(1,0), 1, 2)
    s2 <- ones %*% matrix(c(-1,0), 1, 2)
    s3 <- ones %*% matrix(c(0,1), 1, 2)
    s4 <- ones %*% matrix(c(0,-1), 1, 2)

    step <- sample(1:4, n, replace=TRUE)

    steps <- (step == 1) * s1 + (step == 2) * s2 + (step == 3) * s3 + (step == 4) * s4
    finalSpot <- colSums(steps)

    ## if you want the path traveled:
    ##routeTraveled <- apply(steps, 2, cumsum)

    finalSpot
}
