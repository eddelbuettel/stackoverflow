library(Rcpp)
library(RcppParallel)
library(RcppArmadillo)

# Setting up dummy data
vec1 <- rep(1, 500)
vec2 <- rep(1, 500)
vec_inds <- sort(rep(1:20, 25))
length(vec1);length(vec2);length(vec_inds)

## Checking that allwhich_ts is working as expected
allwhich_ts(vec_inds, 1)

# Checking that vector_addition is working as expected
vector_addition(vec1, vec2)

# Checking that the same logic can be applied serially (mainly to verify data handling method)
r_repro_function <- function(vec1, vec2, vec_inds) {
    op_vec <- numeric(length(vec1))

    for(i in unique(vec_inds)) {
        tmp1 <- vec1[vec_inds <- i]
        tmp2 <- vec2[vec_inds == i]
        tmp_op <- tmp1 + tmp2
        for(n in 1:length(tmp1)) {
            op_vec[(i - 1)*length(tmp1) + n] <- tmp_op[n]
        }
    }
    op_vec
}

r_repro_function(vec1, vec2, vec_inds)
vector_addition_parallel(vec1, vec2, vec_inds)
