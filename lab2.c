#include<stdio.h>
#include<string.h>
int strmatch(char[],char[],char[],char[]);
void main()
{
    char s[20]={0},p[20]={0},r[20]={0},f[20]={0};
    int found;
    printf("\n Enter the source string :\n");
    gets(s);
    printf("Enter pattern string :\n");
    gets(p);
    printf("Enter replace string : \n");
    gets(r);
    found=strmatch(s,p,r,f);
    if(found==1)
    {
        printf("The final string :\n");
        puts(f);
    }
    else{
        printf("Search string 1 pattern not found ");
    }
}
int strmatch(char s[],char p[], char r[] ,char f[])
{
    int i,j,m,k,t,found=0;
    i=j=k=t=0;
    while(s[i]!='\0')
    {
        if(s[m++]==p[j++])
        {
            if(p[j]=='\0')
            {
                for(k=0;r[k]!='\0';k++,t++)
                {
                    f[t]=r[k];
                    i=m;
                    j=0;
                    found=1;
                }
            }
        }
        else
        {
            f[t++]=s[i++];
            m=i;
            j=0;
        }
    }
    return found;

}
