class XYZ{
public:
  List A;

    XYZ(List A_) {
        A = A_;
    }

    void show_elem(const int j) {
        Rcpp::print(A[j]);
    }

    void print_elem(const int j) {
        Rcpp::print(A[j]);
    }
};

RCPP_MODULE(test_xyz) {
      class_<XYZ>("XYZ")
      .constructor<List>()
      .field("A", &XYZ::A)
      .method("print_elem", &XYZ::print_elem)
      .method("show_elem", &XYZ::show_elem)
        ;

};

RCPP_EXPOSED_CLASS(XYZ)

/*** R
x = list("w","a", 4)
xyz = new(XYZ, x)
xyz$print_elem(1)
xyz$show_elem(2)
*/
