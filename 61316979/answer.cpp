#include <Rcpp.h>
// [[Rcpp::plugins(cpp11)]]
using namespace Rcpp;
// [[Rcpp::export]]
void insideOfCommEdgeIdsCpp(CharacterVector g, CharacterVector v) {
  Environment igraph = Environment("package:igraph");
  Function game_er = igraph["erdos.renyi.game"];
  Function get_adjacency = igraph["get.adjacency"];
}
