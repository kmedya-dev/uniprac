/* Program to find the solution of an Initial Value Problem using 
Eulers method.*/ 
#include<stdio.h>
#include<math.h> 
float f(float x, float y); 
int main() 
{
float x[50],y[50],h,xf; 
int i,n; 
printf("Enter the initial and final values of x:\t"); 
scanf("%f %f",&x[0],&xf); 
printf("Enter the initial value of y:\t"); 
scanf("%f",&y[0]); 
printf("Enter the step size:\t"); 
scanf("%f",&h); 
printf("\n\t\t\t***INPUT***\n"); 
printf("\t The differential equation :\n\n"); 
printf("\t\t y' = x^2 + y^2,  y(%f) = %f\n", x[0], y[0]); 
printf("\n\t\t\t***OUTPUT***\n"); 
n = (int)ceil((xf - x[0]) / h);  
printf("\n\t------------------------------------\n"); 
printf("\n\t\t\t x_n\t\t y_n \n"); 
printf("\t--------------------------------\n"); 
printf("\t\t\t %f\t %f\n",x[0],y[0]); 
for(i=0;i<n;i++) 
{
x[i+1]=x[i]+h;
y[i+1]=y[i]+h*f(x[i],y[i]); 
printf("\t\t\t %f\t %f\n",x[i+1],y[i+1]); 
}
printf("\t----------------------------------\n"); 
printf("\n\t\t The solution of the given differential equation at %f is %f.",xf,y[n]); 
return 0;
} 
float f(float x,float y) 
{
return pow(x,2)+pow(y,2);
}

/*
Enter the initial and final values of x:	Enter the initial value of y:	Enter the step size:	
			***INPUT***
	 The differential equation :

		 y' = x^2 + y^2,  y(0.000000) = 0.000000

			***OUTPUT***

	------------------------------------

			 x_n		 y_n 
	--------------------------------
			 0.000000	 0.000000
			 0.100000	 0.000000
			 0.200000	 0.001000
			 0.300000	 0.005000
			 0.400000	 0.014003
			 0.500000	 0.030022
			 0.600000	 0.055112
			 0.700000	 0.091416
			 0.800000	 0.141252
			 0.900000	 0.207247
			 1.000000	 0.292542
	----------------------------------

		 The solution of the given differential equation at 1.000000 is 0.292542.
*/