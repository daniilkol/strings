#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define LEN 1234
int filter(const char* name1,const char* name2, const char* s, const char* r)
{
    int i,dlina_s=strlen(s),dlina_r=strlen(r),kolichestvo=0,dlina_buf,d=abs(dlina_r-dlina_s);
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
        tmp=strstr(buf,s);
        while (tmp)
        {
          f=1;
          dlina_buf=strlen(buf);
          if (dlina_s<dlina_r)
          {
                memcpy(tmp,r,dlina_s);

                for (i=dlina_buf+d-1;i>=tmp-buf+dlina_s; i--)
                    buf[i+d]=buf[i];

                memcpy(tmp+dlina_s,r+dlina_s,d);
          }
          else
          {
        memcpy(tmp,r,dlina_r);

        for (i=tmp-buf+dlina_r;i<dlina_buf;i++)
          buf[i]=buf[i+d];
          }
          tmp=strstr(tmp+dlina_s+dlina_r,s);
        }
      if (f)
        {
          kolichestvo++;
          f=0;
        }

     fprintf(fp2, "%s", buf);
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


