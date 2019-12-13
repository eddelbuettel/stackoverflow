
library(dplyr)

f1 <- count_by_list <- function(lst, var_nm = as.character(substitute(lst)), count_nm = "n"){
    unique_lst <- unique(lst)
    res <- tibble::tibble(!!var_nm := unique_lst, !!count_nm := NA)
    for(i in seq_along(unique_lst)) {
        res[[count_nm]][[i]] <- sum(lst %in% res[[var_nm]][i])
    }
    res
}


x <- list(list(a=1, b=2),
          list(a=1, b=2),
          list(b=3),
          list(b=3, c=4))


f2 <- function(x) {
  xcv <- vapply(x, function(xl) paste0(paste0(names(xl), collapse = ""), paste0(xl, collapse = "")), character(1))
  xcv_count <- table(match(xcv, xcv))
  tibble(x = x[as.integer(names(xcv_count))], n = as.vector(xcv_count))
}

print(f1(x))
print(f2(x))
