#include<stdio.h>
int main(){
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%d",1+i+j);
        }
        for(j=i-1;j>=0;j--)
        {
            printf("%d",1+i+j);
        }
        printf("\n");
    }
    return 0;
}