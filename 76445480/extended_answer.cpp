
#include <Rcpp/Lightest>

inline bool dupevec(Rcpp::NumericVector x, Rcpp::NumericVector y) {
    return x[0] == y[0] && x[1] == y[1] && x[2] == y[2];
}

// [[Rcpp::export(rng=false)]]
Rcpp::LogicalVector dupes(Rcpp::NumericMatrix M) {
    int n = M.ncol();
    Rcpp::LogicalVector lv(n);
    for (int i=0; i<n; i++) {
        bool val = false;
        Rcpp::NumericVector x = M.column(i);
        for (int j=i+1; !val && j<n; j++) {
            val = dupevec(x, M.column(j));
        }
        lv[i] = val;
    }
    return lv;
}

typedef std::tuple<double, double, double> Point3;

// [[Rcpp::export()]]
Rcpp::List duplicated_vertices(Rcpp::NumericMatrix x) {
    std::map<Point3, Rcpp::IntegerVector> positions;
    std::set<Point3> duplicates;

    for (R_len_t i = 0; i < x.ncol(); ++i) {
        Point3 vertex = { x(0, i), x(1, i), x(2, i) };
        if (positions.count(vertex) == 0) {
            Rcpp::IntegerVector position = { i + 1 };
            positions.emplace(vertex, position);
        } else {
            duplicates.insert(vertex);
            positions.at(vertex).push_back(i + 1);
        }
    }

    Rcpp::List result;
    for (const Point3& vertex: duplicates) {
        result.push_back(positions.at(vertex));
    }

    return result;
}

/*** R
set.seed(123)
N <- 15
M <- matrix(sample(c(1,2,3), N*3, replace=TRUE), 3, N)
M
dupes(M)
duplicated(t(M), fromLast=TRUE)
microbenchmark::microbenchmark(Rcpp=dupes(M), R=duplicated(t(M), fromLast=TRUE),
times=100)

microbenchmark::microbenchmark(Rcpp = dupes(M),
                               R = duplicated(t(M), fromLast = TRUE),
                               cpp_map = duplicated_vertices(M))
*/
