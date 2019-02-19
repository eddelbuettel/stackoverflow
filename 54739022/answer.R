#!/usr/bin/Rscript

library(getopt)
spec <- matrix(c(
    'help'   , 'h', 0, "character",
    'input'  , 'i', 1, "character",
    'output' , 'o', 1, "character"),
    byrow=TRUE, ncol=4)
opt <- getopt(spec)

if ( !is.null(opt$input) ) {
    file <- read.table(opt$input)
}

print(file)
