/*Program to find the summation of natural numbers upto a given number*/
#include<stdio.h>
#include<math.h>
int main()
{
int n,sum,i;
printf("Enter the natural number:");
scanf("%d",&n);
sum=0;
for(i=1;i<=n;i++)
{
sum=sum+i;
}
printf("\n\t\t\t***INPUT***\n");
printf("\t\tThe given natural number is %d\n",n);
printf("\n\t\t\t***OUTPUT***\n");
printf("\t The sum of natural numbers upto %d is %d",n,sum);
}
