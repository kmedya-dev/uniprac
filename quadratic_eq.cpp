/*Program to find the roots of a given Quadratic equation*/
#include<stdio.h>
#include<math.h>
int main()
{
double a,b,c,d,r,r1,r2,rl,im;
printf("Enter the values of a,b and c: ");
scanf("%lf%lf%lf",&a,&b,&c);
printf("\n\n\t\t\t***INPUT***\n");
printf("\t The equation is %lfx^2+%lfx+%lf.",a,b,c);
printf("\n\n\t\t\t***OUTPUT***\n");
d=b*b-4.0*a*c;
if(d>0)
{
r1=(-b+sqrt(d))/(2.0*a);
r2=(-b-sqrt(d))/(2.0*a);
printf("\t Two distinct roots exist and are %lf and %lf",r1,r2);
}
else if(d==0)
{
r=-b/(2.0*a);
printf("\t Two roots are equal and is %lf",r);
}
else
 {
rl=-b/(2.0*a);
im=sqrt(-d)/(2.0*a);
printf("\t The roots are imaginary and are %lf+i%lf and %lf-i%lf",rl,im,rl,im);
}
}
