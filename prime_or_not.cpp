/*Program to test whether a number is prime or not*/

 #include<stdio.h>

 #include<math.h>

 int main()

{

int i,num,count=0;

printf("Enter the number:");

scanf("%d",& num);

printf("\n\t\t\t***INPUT***\n");

printf("\t The given number is %d.\n",num);

printf("\n\t\t\t***OUTPUT***\n");

for(i=1;i<=num;i++)

{

if(num%i==0)

count++;

}

if(count==2)

printf("\t The given number %d is prime.",num);

else

printf("\t The given number %d is not prime.",num);

}
