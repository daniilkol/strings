#include <stdio.h>
#include <time.h>
#include <string.h>
#define LEN 1234
#define NMAX 1000000
char *strcpy_ (char *string1, const char *string2);
char *strcat_(char *string1, const char *string2);
int strlen_ (const char *string);
int strlen_ (const char *string)
{
    int i=0;
    while (string[i])
        i++;
    return i;
}
char *strcpy_ (char *string1, const char *string2)

{
  int i = 0;
  do
  {
    string1[i] = string2[i];
  } while (string2[i++]);
  return string1;
}
char *strcat_(char *string1, const char *string2)
{
  strcpy_(string1+strlen_(string1),string2);
  return string1;
}
int main(void)
{
   char buf1[LEN],buf2[LEN];
    int i,j,k,len1;
    double t1,t2;
    char *otv1;
    char *otv2;
    char *otv;
    len1=strlen_(buf1);
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

    //t1=clock();    for (j=0;j<NMAX;j++)        otv1=strcat_(buf1,buf2);    t1=(clock()-t1)/CLOCKS_PER_SEC;t2=clock(); for (k=0;k<NMAX;k++)    otv2=strcat(buf1,buf2);t2=(clock()-t2)/CLOCKS_PER_SEC;
    otv=strcat_(buf1,buf2);
    printf("%s\n",otv);
    //printf("Elapsed t1: %.6lf\n",t1); printf("Elapsed t2: %.6lf\n",t2);
    return 0;
}
