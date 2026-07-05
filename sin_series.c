#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    double x_deg, x_rad, sum, term;
    int n, i;

    printf("Enter the value of x (in degrees): ");
    if (scanf("%lf", &x_deg) != 1) return 1;

    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("\n\t\t*** INPUT ***\n");
    printf("\tValue of x: %.2f degrees\n", x_deg);
    printf("\tNumber of terms: %d\n", n);

    x_rad = x_deg * M_PI / 180.0;
    sum = 0.0;
    term = x_rad;

    for (i = 1; i <= n; i++) {
        sum += term;
        // Next term = -term * x^2 / ((2*i) * (2*i + 1))
        term = -term * x_rad * x_rad / ((2 * i) * (2 * i + 1));
    }

    double exact_val = sin(x_rad);
    double error = exact_val - sum;

    printf("\n\t\t*** OUTPUT ***\n");
    printf("\tComputed sin(%.2f): %.8f\n", x_deg, sum);
    printf("\tExact sin(%.2f):    %.8f\n", x_deg, exact_val);
    printf("\tError:                  %.8f\n", error);

    return 0;
}
