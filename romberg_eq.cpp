/* Program to compute a given integral using Romberg Formula. */
#include<stdio.h>
#include<math.h>

double f(double x);

int main()
{
    int i, j, n = 4;
    double a, b, h[n+1], r[n+1][n+1], sum;

    printf("Enter the values of the lower and upper limits of the integration: ");
    scanf("%lf %lf", &a, &b);

    printf("\n\t\t\tInput \n");
    printf("\tThe given integrand is: 1/(1+x)\n");
    printf("\tThe limits of the integration are: %lf and %lf\n", a, b);

    for(i=1; i<=n; i++)
    {
        h[i] = (b-a)/pow(2, i-1);
        sum = 0.0;
        for(j=0; j<=pow(2, i-1); j++)
        {
            sum = sum + f(a + j*h[i]);
        }
        r[i][1] = h[i] * (2*sum - (f(a) + f(b))) / 2.0;
    }

    for(i=2; i<=n; i++)
    {
        for(j=2; j<=i; j++)
        {
            r[i][j] = r[i][j-1] + (r[i][j-1] - r[i-1][j-1]) / (pow(4, j-1) - 1);
        }
    }

    printf("\n\t\t\tOutput \n");
    printf("\t\t--------------------\n");
    printf("\t\t1\t\t2\t\t3\t\t4\n");
    printf("\t\t---------------------\n\t\t");

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("%lf\t", r[i][j]);
        }
        printf("\n\t\t");
    }
    printf("\n--------------------------\n");
    printf("\tThe value of the integral is = %lf\n", r[n][n]);
    return 0;
}

double f(double x)
{
    return 1.0/(1.0+x);
}
