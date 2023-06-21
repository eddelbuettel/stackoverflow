#' @useDynLib cpp11dummypackage, .registration = TRUE
NULL

#' Transpose a matrix
#' @export
#' @rdname Xt
#' @param X numeric matrix
#' @return numeric matrix
#' @examples
#' set.seed(1234)
#' X <- matrix(rnorm(4), nrow = 2, ncol = 2)
#' X
#' cpp11_Xt(X)
cpp11_Xt <- function(X) {
  Xt(X)
}
