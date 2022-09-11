#' My Sum Function
#'
#' @param vec A vector of values
#'
#' @return The sum
#' @export
#'
#' @examples
#' my_sum(1:10)
my_sum <- function(vec) {
  rcpp_sum(vec)
}
