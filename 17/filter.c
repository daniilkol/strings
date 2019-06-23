#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN 1234
char* change(char* s)
{
    int i,t;
    for (i=0;s[i];i++)
    {
        t=(int)s[i];
        if ((t<91)&&(t>64))
            s[i]=(char)(t+32);
    }
    return s;
}
int filter(const char* name1,const char* name2,char* s)
{
   FILE *fp1, *fp2;
  int kolichestvo=0;
  char buf_orig[LEN],buf[LEN],*tmp;
   if (!(fp1=fopen(name1,"r")))
        return -1;
    if (!(fp2=fopen(name2,"w")))
        return -1;
    s=change(s);

  while (fgets(buf, LEN, fp1))
  {
      strcpy(buf_orig,buf);
      tmp=change(buf);
      if (strstr(tmp,s))
      {
          kolichestvo++;
          fprintf(fp2,"%s",buf_orig);
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
