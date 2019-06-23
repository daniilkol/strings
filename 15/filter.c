#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN 1234
int compare (const char* a,char b)
{
    int i;
    for (i=0;a[i];i++)
        if (a[i]==b)
            return 1;
    return 0;
}
int filter(const char* name1,const char* name2, const char* s, const char* t)
{
    int j,i=0,kolichestvo=0,dlina_s=strlen(s),f=0;
    FILE *fp1;
    FILE *fp2;
    char slovo[LEN],buf[LEN];
    if (!(fp1=fopen(name1,"r")))
        return -1;
    if (!(fp2=fopen(name2,"w")))
        return -1;
    while (fgets(buf,LEN,fp1))
    {

        for (i=0;s[i];i++)
        {

            if (!compare(t,s[i]))
              {
                  j=i;
                while(!compare(t,s[j]))
                        {

                                j++;
                        }

                memcpy(slovo,s+i,j-i);
                slovo[j-i+1]=0;
                if(strstr(buf,slovo))
                {
                    fprintf(fp2,"%s",buf);
                    kolichestvo++;
                   f=1;break;
                } else {i=j;break;}
               }
               if(f)
               {
                   f=0;break;
               }

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
