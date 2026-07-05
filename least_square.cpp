/* Program to compute the Least Square approximate of a set of numbers (Smart Input).*/ 
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_VALS 100 

int main() 
{ 
    int n = 0, n_y = 0, i; 
    double x[MAX_VALS], y[MAX_VALS]; 
    double sumx = 0.0, sumy = 0.0, sumxy = 0.0, sumx2 = 0.0, a0, a1; 
    char line[4096]; 
    char *ptr, *endptr; 

    // Smart Input for X 
    printf("Enter the values of x (separated by space): "); 
    if (fgets(line, sizeof(line), stdin)) { 
        ptr = line; 
        while (n < MAX_VALS) { 
            double val = strtod(ptr, &endptr); 
            if (ptr == endptr) break; 
            x[n++] = val; 
            ptr = endptr; 
        } 
    } 

    // Smart Input for Y 
    printf("Enter the corresponding values of y: "); 
    if (fgets(line, sizeof(line), stdin)) { 
        ptr = line; 
        while (n_y < MAX_VALS) { 
            double val = strtod(ptr, &endptr); 
            if (ptr == endptr) break; 
            y[n_y++] = val; 
            ptr = endptr; 
        } 
    } 

    if (n != n_y) { 
        printf("\nError: Mismatch in number of values! x has %d, y has %d.\n", n, n_y); 
        return 1; 
    } 
     
    if (n == 0) { 
        printf("\nError: No valid data entered.\n"); 
        return 1; 
    } 

    printf("\n\t\t*** INPUT DATA (%d points) ***\n", n); 
    printf("\t-------------------------------------------\n"); 
    printf("\t\t x \t\t y \n"); 
    printf("\t-------------------------------------------\n"); 
    for(i = 0; i < n; i++) 
    { 
        printf("\t\t %.4f\t %.4f\n", x[i], y[i]); 
    } 

    // Calculations 
    for(i = 0; i < n; i++) 
    { 
        sumx += x[i]; 
        sumy += y[i]; 
        sumxy += (x[i] * y[i]); 
        sumx2 += (x[i] * x[i]); 
    } 

    double denominator = (n * sumx2 - sumx * sumx); 
    if (denominator == 0) { 
        printf("\nError: Denominator is zero, cannot fit a line (vertical line or single point).\n"); 
        return 1; 
    } 

    a1 = (n * sumxy - sumx * sumy) / denominator; 
    a0 = (sumy - a1 * sumx) / n; 

    printf("\n\t\t*** RESULTS ***\n"); 
    printf("\tSum of x:   %.4f\n", sumx); 
    printf("\tSum of y:   %.4f\n", sumy); 
    printf("\tSum of xy:  %.4f\n", sumxy); 
    printf("\tSum of x^2: %.4f\n", sumx2); 
    printf("\t-------------------------------------------\n"); 
    printf("\n\t The best straight line fit is:\n"); 
    printf("\n\t\t y = %.4f + (%.4f) * x\n", a0, a1); 

    return 0; 
} 
