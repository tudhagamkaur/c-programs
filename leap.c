#include<stdio.h>
int main(){
    int day ,year,n ,leap,max,i,date;
    char m[12][4]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    printf("Day number:");
    scanf("%d",&day);
    printf("year:");
    scanf("%d",&year);
    printf("N:");
    scanf("%d",&n);
    leap=(year%400==0||(year%4==0 & year%100!=0));
    if (leap == 1)
    max = 366;
    else
    max = 365;
    if(day<1|| day>max||year<1000||year>9999||n<1||n>100)
    {
    printf("INVALID");
    }
    int md[12]={31,28+leap,31,30,31,30,31,31,30,31,30,31};
    date=day;
    for(i=0;date>md[i];i++)
    date-=md[i];
    printf("\nDATE:%d %s %d",date,m[i],year);
    day=day+n;
    if(day>max)
    {
        day=day-max;
        year++;
        leap=(year%400==0||(year%4==0 && year%100!=0));
        md[1]=28+leap;
    }
    date=day;
    for(i=0;date>md[i];i++)
    date-=md[i];
    printf("\nDATE AFTER %d DAYS:%d %s %d",n,date,m[i],year);
    return 0;
}