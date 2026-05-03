#include<stdio.h>
int main(){
    int marks;
    printf("enter the marks of the student");
    scanf("%d",&marks);
    if(marks<=80&&marks>=100)
    {
        printf("merit");
    }
    else if(marks>33)
    {
        printf("pass");
    }
    else {
      printf("fail");
    }
    return 0;
}