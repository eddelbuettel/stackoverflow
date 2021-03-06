##' A placeholder function using roxygen
##'
##' This function shows a standard text on the console. In a time-honoured
##' tradition, it defaults to displaying \emph{hello, world}.
##' @return Nothing is returned but as a side effect output is printed
##' @examples
##'   hello()
##'   hello("and goodbye")
##' @export
hello2 <- function(txt = "world") {
    cat("Hello, ", txt, "\n")
}
