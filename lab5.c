#include<stdio.h>
int count=0;
void tower(int n,int source,int temp,int dest)
{
    if(n==1)
    {
        printf("\n move disc  from %c to %c",source,dest);
        count++;
        return;
    }
    tower(n-1,source,dest,temp);
    printf("\n moves dis  from %c to %c ",source,dest);
    count++;
    tower(n-1,temp,source,dest);
}
void main()
{
    int n;
    printf("Enter number of disc \n");
    scanf("%d",&n);
    tower(n,'A','B','C');
    printf("\n tower moves for %d disc is %d :",n,count);
}
