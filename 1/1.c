#include <stdio.h>
#include <time.h>
#include <string.h>
#define LEN 1234
#define NMAX 100000000
int strlen_ (const char *string);
int strlen_ (const char *string)
{
    int i=0;
    while (string[i])
        i++;
    return i;
}
int main(void)
{
    char buf[LEN];
    int res,i,j,k,n;
    double t1,t2;
    printf("Input string: \n");
    if (!fgets(buf,LEN,stdin))
    {
        printf("Cannot read:\n");
        return 1;
    }
   for (i=0;buf[i];i++)
    {
        if(buf[i]=='\n')
        {
            buf[i]=0;
            break;
        }
    }
    t1=clock();
    for (j=0;j<NMAX;j++)
         res=strlen_(buf);
    t1=(clock()-t1)/CLOCKS_PER_SEC;
    t2=clock();
    for (k=0;k<NMAX;k++)
        n=strlen(buf);
    t2=(clock()-t2)/CLOCKS_PER_SEC;
    printf("Otvet:%d\n",res);
    printf("Elapsed t1: %.6lf\n",t1);
    printf("Elapsed t2: %.6lf\n",t2);
    return 0;
}
