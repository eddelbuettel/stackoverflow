#!/bin/sh
Rscript -e 'Rcpp::Rcpp.package.skeleton("rcpptest")'
R CMD INSTALL rcpptest
