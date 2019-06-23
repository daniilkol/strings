#include <stdio.h>
#include <time.h>
#include <string.h>
#define LEN 1234
#define NMAX 10000000
int strcspn_ (const char *string1,const char *string2);
int strlen_ (const char *string);
int strlen_ (const char *string)
{
    int i=0;
    while (string[i])
        i++;
    return i;
}
int strcspn_ (const char *string1,const char *string2)
{
    int i,j,len1,len2;
    len1=strlen_(string1);
    len2=strlen_(string2);
    for (i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        if (string1[i]==string2[j])
        return i;
    }
return (len1);
}
int main(void)
{
   char buf1[LEN],buf2[LEN];
    int res,res1,i,j,k;
    double t1,t2;
    printf("Input string1: \n");
    if (!fgets(buf1,LEN,stdin))
    {
        printf("Cannot read:\n");
        return 1;
    }
   for (i=0;buf1[i];i++)
    {
        if(buf1[i]=='\n')
        {
            buf1[i]=0;
            break;
        }
    }
    printf("Input string2: \n");
    if (!fgets(buf2,LEN,stdin))
    {
        printf("Cannot read:\n");
        return 1;
    }
   for (i=0;buf2[i];i++)
    {
        if(buf2[i]=='\n')
        {
            buf2[i]=0;
            break;
        }
    }

    t1=clock();
    for (j=0;j<NMAX;j++)
       res=strcspn_(buf1,buf2);
    t1=(clock()-t1)/CLOCKS_PER_SEC;
    t2=clock();
    for (k=0;k<NMAX;k++)
        res1=strcspn(buf1,buf2);
    t2=(clock()-t2)/CLOCKS_PER_SEC;
    printf("%d\n",res);
    printf("Elapsed t1: %.6lf\n",t1);
    printf("Elapsed t2: %.6lf\n",t2);
    return 0;
}
