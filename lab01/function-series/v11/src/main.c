#include "app.h"

/**
 * a(n)   = ((2n + 1) / n!) * x^(2n)
 * a(n+1) = ((2(n+1) + 1) / (n+1)!) * x^(2(n+1)) = ((2n + 3) / (n+1)!) * x^(2n+2)
 *
 *                      ((2n + 3) / (n+1)!) * x^(2n+2)
 * q(n) = a(n+1)/a(n) = -------------------------------
 *                      ((2n + 1) / n!) * x^(2n)
 *
 *                      (2n + 3) * x^2
 * q(n) = a(n+1)/a(n) = ----------------
 *                      (n + 1) * (2n + 1)
 *
 * a(0) = 1
 */

int main()
{
    
    for (int N = 5; N <= 15; N += 5)
    {
        printf("=======Computed with %d members of series=======\n", N);
        
        printf("%-10s%15s%18s\n", "x", "Etalon", "Sum of series");

        for (double x = 0.0; x <= 1.0 + 1e-9; x += 0.1)
        {
            double a = 1.0, S = 0.0;

            for (int n = 0; n < N; ++n)
            {
                S += a;

                double q = (2.0 * n + 3.0) * x * x / ((n + 1.0) * (2.0 * n + 1.0));

                a *= q;
            }

            double etalon = exp(x * x) * (1.0 + 2.0 * x * x);

            printf("%-10.2f%15.5f%18.5f\n", x, etalon, S);
        }
        printf("\n");
    }

    return 0;
}