#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN 1234
int filter(const char* name1,const char* name2, const char* s)
{
    int i,dlina_buf,kolichestvo=0,dlina_s=strlen(s);
    FILE *fp1;
    FILE *fp2;
    char buf[LEN];
    if (!(fp1=fopen(name1,"r")))
        return -1;
    if (!(fp2=fopen(name2,"w")))
        return -1;
    while (fgets(buf,LEN,fp1))
    {
        dlina_buf=strlen(buf);
        if (strstr(buf+dlina_buf-dlina_s-1,s))
            {
               fprintf(fp2, "%s", buf);
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
