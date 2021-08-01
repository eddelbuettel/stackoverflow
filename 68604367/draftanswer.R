suppressMessages({
    library(janitor)
    library(collapse)
    library(dplyr)
    library(Rcpp)
    library(microbenchmark)
})

# source https://stackoverflow.com/questions/31001392/rcpp-version-of-tabulate-is-slower-where-is-this-from-how-to-understand
Rcpp::cppFunction('IntegerVector tabulate_rcpp(const IntegerVector& x, const unsigned max) {
    IntegerVector counts(max);
    for (auto& now : x) {
        if (now > 0 && now <= max)
            counts[now - 1]++;
    }
    return counts;
}')

Rcpp::cppFunction('IntegerVector table_rcpp(const IntegerVector& x) { return table(x); }')
})

set.seed(1234)
##a <- c(1,3,4,4,3)
a <- sample(1000, 10000, TRUE)
df <- data.frame(X1 = a)


b1 <- microbenchmark(tabulate_rcpp = tabulate_rcpp(df$X1, max(df$X1)),
                     table_rcpp = table_rcpp(df$X1),
                     base_table = base::table(factor(df$X1, 1:max(df$X1))),
                     stats_aggregate = stats::aggregate(. ~ X1, cbind(df, n = 1), sum),
                     graphics_hist = hist(df$X1, plot = FALSE, right = FALSE)[c("breaks", "counts")],
                     janitor_tably = adorn_totals(tabyl(df, X1)),
                     collapse_fnobs = fnobs(df, df$X1),
                     base_tabulate = tabulate(df$X1),
                     dplyr_count = count(df, X1))


df <- data.frame(X1 = sample(1:5, 1000, replace = TRUE))

b2 <- microbenchmark(tabulate_rcpp = tabulate_rcpp(df$X1, max(df$X1)),
                     table_rcpp = table_rcpp(df$X1),
                     base_table = base::table(factor(df$X1, 1:max(df$X1))),
                     stats_aggregate = stats::aggregate(. ~ X1, cbind(df, n = 1), sum),
                     graphics_hist = hist(df$X1, plot = FALSE, right = FALSE)[c("breaks", "counts")],
                     janitor_tably = adorn_totals(tabyl(df, X1)),
                     collapse_fnobs = fnobs(df, df$X1),
                     base_tabulate = tabulate(df$X1),
                     dplyr_count = count(df, X1))
