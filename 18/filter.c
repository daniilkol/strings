#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN 1234
int compare( const char *a, const char *b )
{
  int i;

  for (i = 0; a[i] && b[i]; i++)
    if (a[i] != b[i])
      return 0;
  if (a[i] || b[i])
    return 0;



  return 1;
}
int filter(const char* name1,const char* name2, const char* s, const char* t)
{
    int i,pos,dlina_buf,kolichestvo=0;
    FILE *fp1;
    FILE *fp2;
    char buf_orig[LEN],buf[LEN];
    if (!(fp1=fopen(name1,"r")))
        return -1;
    if (!(fp2=fopen(name2,"w")))
        return -1;
    while (fgets(buf,LEN,fp1))
    {
        pos = 0;
    dlina_buf = strlen(buf);

    if (strstr(buf, s))
    {
      while (!strcspn(buf + pos, t))
	pos++;
      fprintf(fp2, "%s", buf + pos);
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
