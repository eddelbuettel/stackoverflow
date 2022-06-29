
# include <R.h>

extern "C" void fibCpp(int *n) {
    int out[200];
    out[0] = 1;
    if (*n > 1) {
        out[1] = 1;
        for (int i = 2; i < *n; i++) {
            out[i] = out[i-1] + out[i-2];
        }
    }
    Rprintf ("The fibonacci sequence until n is %f " , out);
}
