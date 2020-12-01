
suppressMessages({
    library(data.table)
    library(Rcpp)
    library(vroom)
    library(stringfish)
    library(microbenchmark)
})

vroomread <- function(csvfile) {
    a <- vroom(csvfile, col_types = "cc", progress = FALSE)
    vroom:::vroom_materialize(a, TRUE)
}
sfread <- function(csvfile) {
    a <- sf_readLines(csvfile)
    dt <- data.table::data.table(uns = sf_substr(a, 1, 81),
                                 sol = sf_substr(a, 83, 163))
}

sourceCpp("rcppfuncs.cpp")


csvfile <- "sudoku_100k.csv"
res <- microbenchmark(fread=fread(csvfile),
                      vroom=vroomread(csvfile),
                      sfish=sfread(csvfile),
                      rcpp1=data.table::setalloccol(read_to_df_ifstream(csvfile)),
                      rcpp2=data.table::setalloccol(read_to_df_ifstream_charvector(csvfile)),
                      times=10)
print(res)
