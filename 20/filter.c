#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define LEN 1234
int filter(const char* name1,const char* name2, const char* s, const char* r,const char* l)
{
    int i,dlina_s=strlen(s),dlina_r=strlen(r),dlina_l=strlen(l),kolichestvo=0,dlina_buf,d=dlina_r+dlina_s+dlina_l;
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
        dlina_buf=strlen(buf);
        while (tmp)
        {
          f=1;
          for(i=dlina_buf+dlina_r+dlina_l-1;i>=tmp-buf;i--)
            buf[i+dlina_r+dlina_l]=buf[i];
          memcpy(tmp,l,dlina_l);
          memcpy(tmp+dlina_l,s,dlina_s);
          memcpy(tmp+dlina_l+dlina_s,r,dlina_r);
          tmp=strstr(tmp+d,s);
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
