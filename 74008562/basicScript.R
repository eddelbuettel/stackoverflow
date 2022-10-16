#!/usr/bin/env Rscript

args <- commandArgs(trailingOnly = TRUE)
stopifnot("require at least one arg" = length(args) > 0)
cat("We were called with '", args[1], "'\n", sep="")
