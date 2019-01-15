#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
List modifyDataFrame2(DataFrame df) {

  // access the columns
  CharacterVector chrom = df["chrom"];
  IntegerVector start = df["start"];

  List Out;
  IntegerVector ind = IntegerVector::create(0,1,2,3);

  // write the for loop
  for(int i=0; i < df.nrow()-3; ++i){
    IntegerVector currind = ind + i;
    IntegerVector substart = start[currind];
    CharacterVector subchrom = chrom[currind];

    Rcout << "substart is:" << substart << "\n";
    Rcout << "subchrom is:" << subchrom << "\n";
    List temp = List::create(subchrom, substart);
    Out.push_back(temp);
  }
  return Out;
}

/*** R
#example data for R
start <- c(0, 2, 4, 6, 8, 10)
chrom <- c("chr1", "chr1", "chr1", "chr1", "chr1", "chr1")
df <- data.frame(start, chrom)
modifyDataFrame2(df)
*/
