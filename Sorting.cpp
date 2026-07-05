/* Program to find the Bubble sorting (both ascending order & decending order) 
of some given numbers.*/
#include<stdio.h> 
#include<math.h> 
#include<stdlib.h> 
int main() 
{ 
 int array[100],n=0,i,j,swap; 
 char line[4096], *ptr, *endptr;

 printf("Enter the numbers to be sorted (separated by space): ");
 if (fgets(line, sizeof(line), stdin)) {
     ptr = line;
     while (n < 100) {
         long val = strtol(ptr, &endptr, 10);
         if (ptr == endptr) break; 
         array[n++] = (int)val;
         ptr = endptr;
     }
 } 
 printf("\n The number of terms is %d.\n",n); 
 printf("\n The numbers to be sorted are \t"); 
 for(i=0;i<n;i++) 
   { 
  printf("\t%d", array[i]);   
   } 
 for(i=0;i<n-1;i++) 
   { 
    for(j=0;j<n-i-1;j++) 
      { 
      if(array[j]>array[j+1]) 
       { 
        swap=array[j]; 
        array[j]=array[j+1]; 
        array[j+1]=swap; 
        } 
      } 
    } 
 printf("\n The sorted list in ascending order is\t"); 
 for(i=0;i<n;i++) 
   { 
    printf("\t%d",array[i]); 
   } 
 for(i=0;i<n-1;i++) 
   { 
    for(j=0;j<n-i-1;j++) 
      { 
       if(array[j]<array[j+1]) 
        { 
         swap=array[j]; 
         array[j]=array[j+1]; 
         array[j+1]=swap; 
        } 
      } 
    } 
 printf("\n The sorted list in descending order is \t"); 
 for(i=0;i<n;i++) 
   { 
    printf("\t %d",array[i]); 
   }   
 return 0;
 } 
