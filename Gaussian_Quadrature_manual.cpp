/* Program to compute a given integral using three point Gaussian 
Quadrature with MANUAL input of nodes and weights */ 
#include<stdio.h> 
#include<math.h> 

double f(double x); 

int main() 
{ 
    int i, n = 3; 
    double a, b, sum = 0.0, u[11], w[11], x[11]; 

    printf("Enter the values of the lower and upper limits of integration: "); 
    if (scanf("%lf %lf", &a, &b) != 2) return 1;

    printf("Enter the value of the %d nodes:\n", n);
    for(i = 1; i <= n; i++) {
        printf("Node %d: ", i);
        scanf("%lf", &u[i]);
    }

    printf("Enter the corresponding %d weights:\n", n);
    for(i = 1; i <= n; i++) {
        printf("Weight %d: ", i);
        scanf("%lf", &w[i]);
    }

    printf("\n\t\t\t*** INPUT ***\n"); 
    printf("\tThe given function is exp(-x^2).\n"); 
    printf("\tThe limits of the integration are %.4lf and %.4lf.\n", a, b); 
    
    printf("\n\t\t\t*** OUTPUT ***\n"); 
    printf("\t----------------------------------------------------------\n"); 
    printf("\t\t u(i)\t\t w(i)\t\t x(i)\t\t w[i]*f(x(i))\n"); 
    printf("\t----------------------------------------------------------\n"); 

    for(i = 1; i <= n; i++) 
    { 
        x[i] = (b - a) * u[i] / 2.0 + (b + a) / 2.0; 
        double term = w[i] * f(x[i]);
        printf("\t\t %.4lf\t %.6lf\t %.4lf\t %.6lf\n", u[i], w[i], x[i], term); 
        sum = sum + (b - a) * term / 2.0; 
    } 

    printf("\t----------------------------------------------------------\n"); 
    printf("\tThe value of the integral is %.6lf\n", sum); 

    return 0;
}

double f(double x) 
{ 
    return exp(-x * x); 
}
