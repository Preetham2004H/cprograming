#include<stdio.h>
#include<string.h>
#define n 7
#include<malloc.h>
int i=0;
typedef struct
{
    char *activity;
    int date;
    char *day;
}s;
s *creatcal();
void readcal(s*);
void display(s*);
void freecal(s*);
int main()
{
    s *cal=creatcal();
    readcal(cal);
    display(cal);
    freecal(cal);
    return 0;
}
s *creatcal()
{
    s *calender=(s*)malloc(n*sizeof(s));
    for(i=0;i<n;i++)
    {
        calender[i].activity=NULL;
        calender[i].date=0;
        calender[i].day=NULL;
    }
    return calender;
}
void readcal(s*calender)
{
    char ch,dname[20],deactivate[20];
    for(i=0;i<n;i++)
    {
        printf("do you want to enter the details for the day :%d[Y/N]");
        scanf(" %c",&ch);
        if(tolower(ch)=='n')
            continue;
        printf("Enter the day name");
        scanf("%s",dname);
        calender[i].day=strdup(dname);
        printf("ENTER THE ACTIVITY FOR THE DAY");
        scanf("%s",deactivate);
        calender[i].activity=strdup(deactivate);
        printf("Enter date in formate mmddyyy");
        scanf("%d",&calender[i].date);
    }
}
void display(s *calender)
{
    printf("-------------------------------------------------------------------------------------------------");
  printf("\n week details :\n");
  for(i=0;i<n;i++)
  {
      printf("\n day %d :\n ",i+1);
      if(calender[i].date==0)
      {
          printf("no activity");
          continue;
      }
      printf("Dayname : %s \n",calender[i].day);
      printf("Datte : %d \n",calender[i].date);
      printf("activity : %s \n",calender[i].activity);

  }
printf("--------------------------------------------------------------------------------------------------");
}
void freecal(s *calender)
{
    for(i=0;i<n;i++)
    {

        free(calender[i].day);
        free(calender[i].activity);
    }
    free(calender);
}

