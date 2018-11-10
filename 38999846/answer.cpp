#include<armadillo>

int main() {
  arma::arma_rng::set_seed_random();
  arma::mat(3,3, arma::fill::randu).print();
  exit(0);
}
