/* Program to compute a given integral using three point Gaussian 
Quadrature by reading nodes and weights from files */ 
#include<stdio.h> 
#include<math.h> 

double f(double x); 

int main() 
{ 
    int i, n = 3; 
    double a, b, sum = 0.0, u[11], w[11], x[11]; 
    FILE *fp1, *fp2; 

    // Open files
    fp1 = fopen("NODES.txt", "r"); 
    fp2 = fopen("WEIGHTS.txt", "r"); 

    if (fp1 == NULL || fp2 == NULL) { 
        printf("Error: Could not open NODES.txt or WEIGHTS.txt\n"); 
        return 1;
    }

    printf("Enter the values of the lower and upper limits of integration: "); 
    if (scanf("%lf %lf", &a, &b) != 2) return 1;

    // Read nodes and weights from files
    for(i = 1; i <= n; i++) { 
        if (fscanf(fp1, "%lf", &u[i]) != 1) { 
            printf("Error reading from NODES.txt\n"); return 1;
        }
        if (fscanf(fp2, "%lf", &w[i]) != 1) { 
            printf("Error reading from WEIGHTS.txt\n"); return 1;
        }
    }

    printf("\n			*** INPUT ***\n"); 
    printf("\tThe given function is exp(-x^2).\n"); 
    printf("\tThe limits of the integration are %.4lf and %.4lf.\n", a, b); 
    
    printf("\n			*** OUTPUT ***\n"); 
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

    fclose(fp1); 
    fclose(fp2); 
    return 0;
}

double f(double x) 
{ 
    return exp(-x * x); 
}