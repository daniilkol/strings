#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN 1234
int split_words(const char* s,char** words)
{

    int i,f=1,j=0,pos;
    for (i=0;s[i];i++)
    {
        if(!(s[i]==0))
        {
            if(f)
            {
                pos=i;
                f=0;
            }

        }

        else
        {
            if(!f)
            {words[j]=(char*)malloc((i-pos+1)*sizeof(char));
            memcpy(words[j],s+pos,i-pos+1);
            j++;}
            f=1;
        }

    }
    return j;




}
int compare(char s,const char* t)
{
    int i;
    for(i=0;t[i];i++)
    {
        if(t[i]==s)
            return 1;
    }
    return 0;
}
int filter(const char* name1,const char* name2,char* s, const char* t)
{
    int i,kolichestvo=0,dlina_s=strlen(s),p,j;
    FILE *fp1;
    FILE *fp2;
    char buf_orig[LEN],buf[LEN];
    char** words;
    if(!(words=(char**)malloc(LEN*sizeof(char*))))
   {
       printf("Not enough memory\n");
       return 2;
   }
    if (!(fp1=fopen(name1,"r")))
        return -1;
    if (!(fp2=fopen(name2,"w")))
        return -1;
    for(i=0;s[i];i++)
    {
        if (compare(s[i],t))
            s[i]=0;
    }
    j=split_words(s,words);
    while (fgets(buf,LEN,fp1))
    {
        for(i=0;i<=j;i++)
        {
            if (strstr(buf,words[i]))
            {
                kolichestvo++;
                fprintf(fp2,"%s",buf);
                break;
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
