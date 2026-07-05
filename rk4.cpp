/* Program to find the solution of an Intial Value Problem using 
Runge Kutta method of order 4.*/ 
#include<stdio.h>
#include<math.h>
float f(float x,float y);
int main()
{
float x[50],y[50],k1,k2,k3,k4,h,xf;
int i,n;
printf("Enter the initial and final values of x :");
scanf("%f%f",&x[0],&xf);
printf("Enter the initial value of y : ");
scanf("%f",&y[0]);
printf("Enter the step size : ");
scanf("%f",&h);
printf("\n\t\t\t***INPUT***\n");
printf("\tThe differential equation is :\n\n");
printf("\t\t\t y'=x-y, y(%f)=%f\n\n", x[0], y[0]);
printf("\n\t\t\t***OUTPUT***\n");
n = (int)ceil((xf - x[0]) / h);
if (n >= 50) n = 49; // Stay within array bounds
printf("\n\t................................................................\n");
printf("\t\t\tx_n\t\ty_n\n");
printf("\t................................................................\n");
printf("\t\t\t%f\t%f\n",x[0],y[0]);
for(i=0; i<n; i++)
{
k1=h*f(x[i],y[i]);
k2=h*f(x[i]+h/2.0,y[i]+k1/2.0);
k3=h*f(x[i]+h/2.0,y[i]+k2/2.0);
k4=h*f(x[i]+h,y[i]+k3);
x[i+1]=x[i]+h;
y[i+1]=y[i]+(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
printf("\t\t\t%f\t%f\n",x[i+1],y[i+1]);
}
printf("\t................................................................\n");
printf("\n\t\tThe value of y(%f) is %f.",xf,y[n]); 
return 0;
} 
float f(float x,float y){
return x-y;
}

/*
Enter the initial and final values of x :0 2        
Enter the initial value of y : 1                    
Enter the step size : 0.05                          
                                                    
                        ***INPUT***                 
        The differential equation is :              
                                                    
                        y'=x-y, y(0.000000)=1.000000
                                                    
                                                    
                        ***OUTPUT***                
                                                    
        ............................................
....................                                
                        x_n             y_n         
        ............................................
....................                                
                        0.000000        1.000000    
                        0.050000        0.952459    
                        0.100000        0.909675    
                        0.150000        0.871416    
                        0.200000        0.837462    
                        0.250000        0.807602    
                        0.300000        0.781636    
                        0.350000        0.759376    
                        0.400000        0.740640    
                        0.450000        0.725256    
                        0.500000        0.713061    
                        0.550000        0.703900    
                        0.600000        0.697623    
                        0.650000        0.694092    
                        0.700000        0.693171    
                        0.750000        0.694733    
                        0.800000        0.698658    
                        0.850000        0.704830    
                        0.900000        0.713139    
                        0.950000        0.723482    
                        1.000000        0.735759    
                        1.050000        0.749876    
                        1.100000        0.765742    
                        1.150000        0.783274    
                        1.200000        0.802389    
                        1.250000        0.823010    
                        1.300000        0.845064    
                        1.350000        0.868481    
                        1.400000        0.893194    
                        1.450000        0.919141    
                        1.500000        0.946260    
                        1.550000        0.974496    
                        1.600000        1.003793    
                        1.649999        1.034100    
                        1.699999        1.065367    
                        1.749999        1.097548    
                        1.799999        1.130598    
                        1.849999        1.164474    
                        1.899999        1.199137    
                        1.949999        1.234548    
                        1.999999        1.270670    
        ............................................
....................                                
                                                    
                The value of y(2.000000) is 1.270670
.
*/