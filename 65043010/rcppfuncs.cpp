
#include <Rcpp.h>
#include <fstream>

//[[Rcpp::export]]

Rcpp::DataFrame read_to_df_ifstream(std::string filename) {
  const int n_lines = 1000000;
  std::ifstream file(filename, std::ifstream::in);

  std::string line;
  // burn the header
  std::getline(file, line);

  std::vector<std::string> a, b;
  a.reserve(n_lines);
  b.reserve(n_lines);

  while (std::getline(file, line)) {
    a.push_back(line.substr(0, 80));
    b.push_back(line.substr(82, 162));
  }

  Rcpp::List df(2);
  df.names() = Rcpp::CharacterVector::create("unsolved", "solved");

  df["unsolved"] = a;
  df["solved"] = b;

  df.attr("class") = Rcpp::CharacterVector::create("data.table", "data.frame");

  return df;
}

//[[Rcpp::export]]
Rcpp::DataFrame read_to_df_ifstream_charvector(std::string filename) {
  const int n_lines = 1000000;
  std::ifstream file(filename, std::ifstream::in);

  std::string line;
  // burn the header
  std::getline(file, line);

  Rcpp::CharacterVector a(n_lines), b(n_lines);

  int l = 0;
  while (std::getline(file, line)) {
    a(l) = line.substr(0, 80);
    b(l) = line.substr(82, 162);
    l++;
  }

  Rcpp::List df(2);
  df.names() = Rcpp::CharacterVector::create("unsolved", "solved");

  df["unsolved"] = a;
  df["solved"] = b;

  df.attr("class") = Rcpp::CharacterVector::create("data.table", "data.frame");

  return df;
}
