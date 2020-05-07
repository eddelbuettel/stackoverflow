#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
List DataFrameExample(const DataFrame & DF) {

    // access each column by name
    IntegerVector a = DF["a"];
    CharacterVector b = DF["b"];
    DateVector c = DF["c"];

    // do something
    a[2] = 42;
    b[1] = "foo";
    c[0] = c[0] + 7; // move up a week

    // create a new data frame
    DataFrame NDF = DataFrame::create(Named("a")=a,
                                      Named("b")=b,
                                      Named("c")=c);

    // and reassign names
    NDF.attr("names") = CharacterVector::create("tic", "tac", "toe");

    // and return old and new in list
    return List::create(Named("origDataFrame") = DF,
                        Named("newDataFrame") = NDF);
}

/*** R
D <- data.frame(a=1:3,
                b=LETTERS[1:3],
                c=as.Date("2011-01-01")+0:2)
rl <- DataFrameExample(D)
print(rl)
*/
