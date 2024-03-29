% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/pkg.R
\name{cpp11_Xt}
\alias{cpp11_Xt}
\title{Transpose a matrix}
\usage{
cpp11_Xt(X)
}
\arguments{
\item{X}{numeric matrix}
}
\value{
numeric matrix
}
\description{
Transpose a matrix
}
\examples{
set.seed(1234)
X <- matrix(rnorm(4), nrow = 2, ncol = 2)
X
cpp11_Xt(X)
}
