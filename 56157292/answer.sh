#!/bin/bash

docker run --rm -ti -v${PWD}:/work -w/work rocker/r-rmd Rscript -e 'rmarkdown::render("file.Rmd")'
