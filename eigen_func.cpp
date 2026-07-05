/* Program to find the Numerically largest Eigen value and the corresponding Eigen vector of a 
Matrix using Power Method.*/ 
#include <stdio.h> 
#include <math.h> 

#define MAX_SIZE 10
#define MAX_ITER 100
#define TOLERANCE 0.00001

int main() 
{ 
    double x[MAX_SIZE], y[MAX_SIZE], c[MAX_SIZE], a[MAX_SIZE][MAX_SIZE];
    double max_eigen_value = 0.0, sum; 
    int i, j, n, iteration; 

    printf("Enter the order of the square matrix (n): "); 
    if (scanf("%d", &n) != 1) return 1;

    if (n > MAX_SIZE) {
        printf("Error: Max order is %d\n", MAX_SIZE);
        return 1;
    }

    printf("Enter the elements of the matrix row wise:\n"); 
    for(i = 0; i < n; i++) 
    { 
        for(j = 0; j < n; j++) 
        { 
            scanf("%lf", &a[i][j]); 
        } 
    } 

    printf("\n\t\t\t*** INPUT ***\n"); 
    printf("\tThe order of the matrix is %dx%d\n", n, n); 
    printf("\tThe input matrix is :\n\t\t\t"); 
    for(i = 0; i < n; i++) 
    { 
        for(j = 0; j < n; j++) 
        { 
            printf("%.4lf \t", a[i][j]); 
        } 
        printf("\n\t\t\t"); 
    } 

    // Initial guess for Eigen vector: [1, 0, 0, ...]
    x[0] = 1.0; 
    for(i = 1; i < n; i++) x[i] = 0.0; 

    printf("\n\t\t\t*** OUTPUT ***\n"); 
    printf("\n\t------------------------------------------------------------------\n"); 
    printf("\t Iteration\t Eigen Value\t Eigen Vector\n"); 
    printf("\t------------------------------------------------------------------\n"); 

    iteration = 0;
    int converged = 0;

    do {
        iteration++;
        
        // Save previous x values to check convergence later
        for(i = 0; i < n; i++) c[i] = x[i]; 

        // Matrix Multiplication: y = A * x
        for(i = 0; i < n; i++) 
        { 
            sum = 0.0; 
            for(j = 0; j < n; j++) 
            { 
                sum += a[i][j] * x[j]; 
            } 
            y[i] = sum; 
        } 

        // Find largest element in y as the new Eigen Value
        max_eigen_value = fabs(y[0]); 
        for(i = 1; i < n; i++) 
        { 
            if(fabs(y[i]) > max_eigen_value) 
                max_eigen_value = fabs(y[i]); 
        }
        
        // If max is 0, avoid division
        if (max_eigen_value == 0) max_eigen_value = 1e-10;
        
        // Preserve sign of the largest element
         for(i = 0; i < n; i++) 
        { 
            if(fabs(y[i]) == max_eigen_value) 
            {
                max_eigen_value = y[i];
                break;
            }
        }

        // Normalize y to get new x
        for(i = 0; i < n; i++) 
        { 
            x[i] = y[i] / max_eigen_value; 
        } 

        // Print Iteration status
        printf("\t %d\t\t %.5lf\t [ ", iteration, max_eigen_value);
        for(i = 0; i < n; i++) printf("%.4lf ", x[i]);
        printf("]\n");

        // Check Convergence
        converged = 1;
        for(i = 0; i < n; i++) 
        { 
            if(fabs(c[i] - x[i]) > TOLERANCE) 
            { 
                converged = 0;
                break;
            } 
        }

    } while(!converged && iteration < MAX_ITER);

    printf("\t------------------------------------------------------------------\n"); 
    
    if (iteration >= MAX_ITER) {
        printf("\n\tWarning: Maximum iterations reached. Method might not have converged.\n");
    }

    printf("\n\tThe largest Eigen Value is %.5lf\n", max_eigen_value); 
    printf("\tThe corresponding Eigen Vector is:\n\t\t[ "); 
    for(i = 0; i < n; i++) 
    { 
        printf("%.5lf ", x[i]); 
    } 
    printf("]\n");

    return 0;
}