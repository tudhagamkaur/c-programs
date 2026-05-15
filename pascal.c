#include<stdio.h>
int main(){
    int row,i,j,num;
    printf("enter number of rows");
    scanf("%d",&row);
    for(i=0;i<row;i++)
   {
    num=1;
   //print spaces
   for(j=0;j<row-i-1;j++)
   {
    printf(" ");
   }
   for(j=0;j<=i;j++)
   {
    printf("%d ",num);
    num=num*(i-j)/(j+1);
   }
   printf("\n");}
   return 0;}
