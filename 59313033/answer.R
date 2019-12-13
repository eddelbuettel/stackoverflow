## questions
simulate_and_evaluate <- function(simulate, evaluate) {
  y <- simulate(1)
  eval <- evaluate(y)
  return(eval)
}

simulate_fun <- function(n) rnorm(n, 0, 1)
evaluate_fun <- function(x) dnorm(x, 0, 1)

set.seed(123)
simulate_and_evaluate(simulate = simulate_fun,
                      evaluate = evaluate_fun)

Rcpp::cppFunction("double simAndEval(Function sim, Function eval) {
  double y = as<double>(sim(1));
  double ev = as<double>(eval(y));
  return(ev);
}")

set.seed(123) # reset RNG
simAndEval(simulate_fun, evaluate_fun)
