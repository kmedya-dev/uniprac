/* Improved Program to find the solution of a first order Ordinary Differential 
   Equation by Milne's Predictor-Corrector method with Iterative Refinement. */ 
#include <stdio.h> 
#include <math.h> 

#define MAX_ITER 20
#define TOLERANCE 0.000001

// Define the differential equation y' = f(x, y)
// Example: y' = (x + y) / 2
double f(double x, double y) { 
    return (x + y) / 2.0; 
}

int main() 
{ 
    int i; 
    double x[10], y[10], yd[10], h, yp, yc, yc_old; 

    printf("Enter the step size (h): ");
    if (scanf("%lf", &h) != 1) return 1;

    printf("Enter the 4 initial values of x and y:\n");
    for(i = 0; i < 4; i++) {
        printf("Point %d (x y): ", i); 
        scanf("%lf %lf", &x[i], &y[i]);
    }

    // Validate Step Size Consistency
    for(i = 1; i < 4; i++) {
        if (fabs((x[i] - x[i-1]) - h) > 0.0001) {
            printf("\nWarning: Input x values are not spaced by h=%.4lf at index %d!\n", h, i);
        }
    }

    printf("\n\t\t\t*** INPUT ***\n"); 
    printf("\tThe differential equation is y' = (x + y) / 2\n"); 
    printf("\tStep size h = %.4lf\n", h);
    
    printf("\n\t\t\t*** OUTPUT ***\n"); 
    printf("\t----------------------------------------------\n"); 
    printf("\t\t x \t\t y \t\t y'\n"); 
    printf("\t----------------------------------------------\n"); 

    // Calculate derivatives for the known points
    for(i = 0; i < 4; i++) { 
        yd[i] = f(x[i], y[i]); 
        printf("\t\t %.4lf\t %.4lf\t %.4lf\n", x[i], y[i], yd[i]); 
    } 
    printf("\t----------------------------------------------\n"); 

    // --- STEP 1: PREDICTOR ---
    // y4_p = y0 + 4h/3 * (2y1' - y2' + 2y3')
    yp = y[0] + (4.0 * h / 3.0) * (2.0 * yd[1] - yd[2] + 2.0 * yd[3]); 
    
    // Target x
    x[4] = x[3] + h;
    
    printf("\n\t[Predictor] y_p(%.4lf) = %.6lf\n", x[4], yp); 

    // --- STEP 2: CORRECTOR (Iterative) ---
    // y4_c = y2 + h/3 * (y2' + 4y3' + y4')
    
    yc = yp; // Start with predictor value
    int iter = 0;
    
    printf("\n\t... Refining Corrector Value ...\n");
    do { 
        yc_old = yc;
        
        // Calculate slope at predicted/corrected point
        yd[4] = f(x[4], yc); 
        
        // Apply Corrector Formula
        yc = y[2] + (h / 3.0) * (yd[2] + 4.0 * yd[3] + yd[4]);
        
        iter++;
        // printf("\t  Iter %d: y = %.6lf\n", iter, yc); // Debug print

    } while(fabs(yc - yc_old) > TOLERANCE && iter < MAX_ITER);

    if (iter >= MAX_ITER) {
        printf("\tWarning: Corrector did not fully converge within %d iterations.\n", MAX_ITER);
    }

    printf("\n\t[Corrector] y_c(%.4lf) = %.6lf\n", x[4], yc); 
    printf("\tIterations required: %d\n", iter);
    printf("\tEstimated Error (Corrector - Predictor): %.6lf\n", yc - yp);

    return 0;
}
