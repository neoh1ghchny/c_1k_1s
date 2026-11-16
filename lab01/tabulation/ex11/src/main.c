#include "app.h"

#define Z(x, y) (log(sqrt((x) + (y))) / ((x) * (y)))

int main()
{
    double a = 1.0, b = 2.0, hx = 0.2;
    double c = 1.0, d = 3.0, hy = 0.3;

    printf("y\\x\t");

    double x = 0;

    for (x = a; x <= b + 1e-9; x += hx)
    {
        printf("%2.2f\t", x);
    }

    printf("\n");

    for (double y = c; y <= d + 1e-9; y += hy)
    {
        printf("%2.2f\t", y);
        for (double x = a; x <= b + 1e-9; x += hx)
        {
            double z = Z(x, y);

            printf("%4.2f\t", z);
        }
        printf("\n");
    }

    return 0;
}