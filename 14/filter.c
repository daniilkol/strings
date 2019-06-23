#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN 1234
int filter(const char* name1,const char* name2, const char* s, const char* t)
{
    int i,pos,dlina_buf,kolichestvo=0,dlina_buf_orig;
    FILE *fp1;
    FILE *fp2;
    char buf_orig[LEN],buf[LEN];
    if (!(fp1=fopen(name1,"r")))
        return -1;
    if (!(fp2=fopen(name2,"w")))
        return -1;
    while (fgets(buf,LEN,fp1))
    {
        dlina_buf=dlina_buf_orig=strlen(buf);
        strcpy(buf_orig,buf);
        while(((pos=strcspn(buf,t))!=dlina_buf)&&dlina_buf_orig>0)
        {
            for (i=pos;i<dlina_buf_orig-1;i++)
                buf[i]=buf[i+1];
            dlina_buf_orig--;

        }
        buf[dlina_buf_orig-1]=0;
        if(strstr(buf,s))
        {
            fprintf(fp2,"%s",buf_orig);
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
