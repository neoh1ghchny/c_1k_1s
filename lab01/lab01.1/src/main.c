#include "app.h"

int main() 
{
    double x = -0.8, a = 2.07, b = 0.15;

    double t1 = asin(2 * x);
    printf("t1: %.3f\n", t1);

    double t2 = fabs(b - log(fabs(a * x - 2)));
    printf("t2: %.3f\n", t2);

    double result = t1 / t2;
    printf("Result: %.3f\n", result);

    return 0;
}