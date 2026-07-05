/*Program to generate all the terms of Fibonacci series upto a certain number*/
#include<stdio.h>
#include<math.h>
int main()
{
long int i,nt=0,t1=0,t2=1;
long int n;
printf("Enter the number of terms n:");
scanf("%ld",&n);
printf("\n\t\t\t***INPUT***\n");
printf("\t First two terms are t1=%ld and t2=%ld.\n",t1,t2);
printf("\t Required upto %ld terms \n",n);
printf("\n\t\t\t***OUTPUT***\n");
printf("\t The Fibonacci series upto %ld terms are:\n\n",n);
int count = 0;
while(count < n)
{
printf(" %ld",nt);
t1=t2;
t2=nt;
nt=t1+t2;
count++;
}
}
