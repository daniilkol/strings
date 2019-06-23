#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define LEN 1234
int compare (const char*a, const char* b);
int compare (const char*a, const char* b)
{
    int i,f=1,dlina_b=strlen(b),j=0;
    for (i=0;a[i];i++)
    {
        if((a[i]=='.')||(a[i]=='\\'))
        {
            if(i<dlina_b)
            {
                if(a[i]=='.')
                {
                    if((b[j]!='\\')&&(b[j+1]!='.'))
                      return 0;
                }
                if(a[i]=='\\')
                {
                    if((b[j]!='\\')&&(b[j+1]!='\\'))
                      return 0;
                }
                j=j+2;
            }
            else return 0;

        }
        else
        {
            if (b[j]!='.')
            {
              if(a[i]!=b[j])
                 return 0;
            }
            j++;
        }
    }


      return 1;
}
int filter(const char* name1,const char* name2, const char* s)
{
    int kolichestvo=0;
    int f=0;
    FILE *fp1;
    FILE *fp2;
    char buf[LEN],*tmp;
    if (!(fp1=fopen(name1,"r")))
        return -1;
    if (!(fp2=fopen(name2,"w")))
        return -1;
    while (fgets(buf,LEN,fp1))
    {
       if (compare(buf,s))
       {
           fprintf(fp2,"%s",buf);
           kolichestvo++;
       }
    }

    if (!feof(fp1))
    {
      fclose(fp1);
      fclose(fp2);
      return -2;
    }

    fclose(fp1);
    fclose(fp2);
    return kolichestvo;
}
