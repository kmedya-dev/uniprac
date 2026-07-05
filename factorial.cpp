/*Program to evaluate the factorial of a given number*/
 #include<stdio.h>
 #include<math.h>
 int main()
{
int n,prod,i;
printf("Enter the natural number n:");
scanf("%d",&n);
prod=1;
for(i=1;i<=n;i++)
{
prod=prod*i;
}
printf("\n\t\t\t***INPUT***\n");
printf("\t\t The natural number is %d.\n",n);
printf("\n\t\t\t***OUTPUT***\n");
printf("\t\t The factorial of %d is %d.",n,prod);
}
