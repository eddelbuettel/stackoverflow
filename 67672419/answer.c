#define MATHLIB_STANDALONE
#include <R.h>
#include <Rmath.h>

int main() {
    /*  Inputs  */
    double V1 = 1;
    double V2 = 2;

    /*  Normal Distribution  */
    double result = dnorm(V1, V2, M_PI, 1);
    printf("%lf\n",result);
    return 0;
}
