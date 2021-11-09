

set.seed(1)
Vec <- rnorm(5,100,3)
DF <- data.frame(X1=Vec[-1], X2=Vec[-length(Vec)])

coef(lm(X1 ~ X2, DF))[2]

cov(DF$X1, DF$X2) / var(DF$X2)

myN <- nrow(DF)
(sum(DF[,1]*DF[,2])*myN - sum(DF[,1])*sum(DF[,2])) / (myN * sum(DF[,1]^2) - (sum(DF[,1])^2))
