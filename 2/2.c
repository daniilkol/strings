#include <stdio.h>
#include <time.h>
#include <string.h>
#define LEN 1234
#define NMAX 10000000
char *strcpy_ (char *string1, const char *string2);
char *strcpy_ (char *string1, const char *string2)
{
  int i = 0;
  do
  {
    string1[i] = string2[i];
  } while (string2[i++]);
  return string1;
}
int main(void)
{
    char buf1[LEN],buf2[LEN];
    int i,j,k;
    double t1,t2;
    char *res;
    printf("Input string2: ");
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
       strcpy_(buf1,buf2);
    t1=(clock()-t1)/CLOCKS_PER_SEC;
    t2=clock();
    for (k=0;k<NMAX;k++)
        strcpy(buf1,buf2);
    t2=(clock()-t2)/CLOCKS_PER_SEC;
    res=strcpy_(buf1,buf2);
    printf("%s\n",res);
    printf("Elapsed t1: %.6lf\n",t1);
    printf("Elapsed t2: %.6lf\n",t2);
    return 0;
}
