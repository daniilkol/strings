#include <stdio.h>
#include <time.h>
#include <string.h>
#define LEN 1234
#define NMAX 1000000
char *strchr_ (const char *string,int ch);
char *strchr_ (const char *string, int ch)
{
  int i=0;
  do
  {
    if (string[i]==ch)
      return (char *)(string+i);
  } while (string[i++]);

  return 0;
}
int main(void)
{
    char buf[LEN];
    int i,j,k;
    double t1,t2;
    char ch;
    printf("Input string:\n");
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
    printf("Input ch:\n");
    scanf("%s",ch);
    //t1=clock();
    //for (j=0;j<NMAX;j++)
        //strchr_(buf,ch);
    //t1=(clock()-t1)/CLOCKS_PER_SEC;
    //t2=clock();
    //for (k=0;k<NMAX;k++)
        //strchr(buf,ch);
    //t2=(clock()-t2)/CLOCKS_PER_SEC;
    printf("%s\n",strchr_(buf,ch));
    //printf("Elapsed t1: %.6lf\n",t1);
    //printf("Elapsed t2: %.6lf\n",t2);
    return 0;
}
