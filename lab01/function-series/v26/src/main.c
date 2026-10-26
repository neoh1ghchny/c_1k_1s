#include "app.h"

/**
 * a(n) = (-1)^(n-1) * 2^n*x^n/n
 * a(n+1) = (-1)^n * 2^(n+1)*x^(n+1)/(n+1)
 * a(n+1) = (-1)^n * 2^n*x^n * 2x/(n+1)
 *
 *                      (-1)^n * 2^n*x^n * 2x * n
 * q(n) = a(n+1)/a(n) = ---------- -------------
 *                       (-1)^(n-1) * 2^n*x^n/(n+1)
 *
 *                      - 2x * n
 * q(n) = a(n+1)/a(n) = ----------
 *                       (n+1)
 *
*                   2x * n
 * a(n+1) = -a(n) ----------
 *                 (n+1)
 *
 * a(1) = 1
 */

int main()
{
    for (int N = 10; N <= 50; N += 10)
    {
        printf("=======Computed with %d member of series=======\n", N);

        printf("%-10s%10s%15s\n", "x", "Etalon", "Sum of series");

        for (double x = -0.4; x <= 0.5; x += 0.1)
        {
            double a = 2 * x, S = 0.0;

            for (int n = 1; n <= N; ++n)
            {

                S += a;

                double q = - 2 * x * n / (n + 1.0);

                a *= q;
            }

            double etalon = log(1 + 2 * x);

            printf("%-10.5f%10.5f%15.5f\n", x, etalon, S);
        }
    }


    return 0;
}
