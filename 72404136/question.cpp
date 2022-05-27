#include <Rcpp.h>
#include <fstream>
using namespace Rcpp;

std::vector<double> read_vector_from_file(std::string filename)
{
  std::vector<char> buffer{};
  std::ifstream ifs(filename, std::ios::in | std::ifstream::binary);
  std::istreambuf_iterator<char> iter(ifs);
  std::istreambuf_iterator<char> end{};
  std::copy(iter, end, std::back_inserter(buffer));
  std::vector<double> newVector(buffer.size() / sizeof(double));
  memcpy(&newVector[0], &buffer[0], buffer.size());
  return newVector;
}

std::vector<double> LT = read_vector_from_file("test.bin");

// [[Rcpp::export]]
double Rcpp_test() {
  return LT[3];
}

/*** R
output_file <- file(description="test.bin",open="a+b")
writeBin(runif(10), output_file, size=8)
close(output_file)
*/
