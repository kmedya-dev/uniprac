/* Program to compute the root of a given real function by Newton 
Raphson method, correct upto 5 decimal places */ 
#include<stdio.h> 
#include<math.h> 

#define MAX_ITER 100

double f(double x); 
double df(double x); 

int main() 
{
    int i = 1; 
    double x0, x1, h; 
    double error = 0.000001; // Set for 5-6 decimal places accuracy
    double derivative;

    printf("Enter the initial value of the root: "); 
    if (scanf("%lf", &x0) != 1) return 1;

    printf("\n\t\t\t*** INPUT ***\n"); 
    printf("\tThe given equation is x^3 - 2*x - 5 = 0.\n"); 
    printf("\tThe initial value of the root is %.5lf.\n", x0); 
    printf("\tRequirement: Correct upto 5 decimal places.\n"); 

    printf("\n\t\t\t*** OUTPUT ***\n"); 
    printf("\n\t---------------------------------\n"); 
    printf("\t\t i \t\t xi\n"); 
    printf("\t---------------------------------\n"); 

    do 
    {
        derivative = df(x0);
        if (fabs(derivative) < 0.0000001) {
            printf("\n\tError: Derivative is too small at x = %lf. Method failed.\n", x0);
            return 1;
        }

        h = f(x0) / derivative; 
        x1 = x0 - h;

        printf("\t\t%d\t\t%.5lf\n", i, x1); 
        x0 = x1; 
        i++; 

        if (i > MAX_ITER) {
            printf("\n\tError: Maximum iterations reached. Method did not converge.\n");
            return 1;
        }

    } while(fabs(h) > error); 

    printf("\t---------------------------------\n"); 
    printf("\n\tThe root of the given equation is %.5lf\n", x1); 

    return 0;
}

double f(double x) 
{
    return x*x*x - 2.0*x - 5.0; 
}

double df(double x) 
{
    return 3.0*x*x - 2.0;
}
