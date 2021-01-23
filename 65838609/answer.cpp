
#include <Rcpp.h>
#include <fstream>

// we need this define under current Boost to silence warning about use of deprecated auto_ptr
#define BOOST_NO_AUTO_PTR
#include <boost/uuid/detail/md5.hpp>
#include <boost/algorithm/hex.hpp>

// make sure we 'see' header files from BH
// [[Rcpp::depends(BH)]]

// [[Rcpp::export]]
bool hasher(const std::string& infilename, const std::string& outfilename) {

  // cf https://stackoverflow.com/questions/48545330/c-fastest-way-to-read-file-line-by-line
  std::ifstream infile(infilename);
  std::ofstream outfile(outfilename);
  std::string line;

  while (std::getline(infile, line)) {
    // line contains the current line

    // cf https://stackoverflow.com/questions/55070320/how-to-calculate-md5-of-a-file-using-boost
    boost::uuids::detail::md5 hash;
    md5::digest_type digest;
    hash.process_bytes(line.data(), line.size());
    hash.get_digest(digest);
    const auto charDigest = reinterpret_cast<const char *>(&digest);
    std::string res;
    boost::algorithm::hex(charDigest, charDigest + sizeof(md5::digest_type), std::back_inserter(res));
    outfile << res << '\n';
  }
  outfile.close();
  infile.close();
  return true;
}
