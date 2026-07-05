#include <stdio.h>
#include <math.h>

int main() {
    double x, sum, term;
    int n, i;

    printf("Enter the value of x: ");
    if (scanf("%lf", &x) != 1) return 1;

    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("\n\t\t*** INPUT ***\n");
    printf("\tValue of x: %.2f\n", x);
    printf("\tNumber of terms: %d\n", n);

    sum = 1.0;  // First term (x^0 / 0!)
    term = 1.0;

    for (i = 1; i < n; i++) {
        term = term * x / i;
        sum += term;
    }

    double exact_val = exp(x);
    double error = exact_val - sum;

    printf("\n\t\t*** OUTPUT ***\n");
    printf("\tComputed exp(%.2f): %.8f\n", x, sum);
    printf("\tExact exp(%.2f):    %.8f\n", x, exact_val);
    printf("\tError:                  %.8f\n", error);

    return 0;
}
