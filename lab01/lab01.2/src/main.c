#include "app.h"

#define DEFAULT_PRECISION 3

int main()
{
    double x, a, b;

    printf("Enter x, a, b:");

    int ret = scanf("%lf %lf %lf", &x, &a, &b);

    if (ret < 3) {
        printf("Incorrect input parameters. Must be 3");
        return -1;
    }

    double result = exp(2*x - a) + log(x - b)/(a-x);

    printf("Enter precision (default is %d):", DEFAULT_PRECISION);
    int precision;
    ret = scanf("%d", &precision);

    if (ret < 1 || precision < 1)
    {
        precision = DEFAULT_PRECISION;
    }

    printf("Result (with %d digits): %.3f\n", precision, result);
    return 0;
}