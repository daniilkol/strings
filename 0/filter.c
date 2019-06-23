#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define LEN 1234
int del_newline(char* s);
int del_newline(char* s)
{
    int i;
    for (i=0;s[i];i++)
        if(s[i]=='\n')
    {
        s[i]=0;
        break;
    }
    return i;
}
int  my_strcmp(const char* s1,const char* s2, const char* s3,const char* buf)
{
  int i,j;
  for(i=0;buf[i]&&s1[i];i++)
  {
    if (s2[i]=='0')
    {
        if(buf[i]!=s1[i])
            return 0;
    } else
    {
        if (!(buf[i]>=s2[i]&&buf[i]<=s3[i]))
            return 0;
    }
  }
  if (s1[i])
    return 0;

  return 1;
}
int filter(const char* name1,const char* name2, const char* s)
{
    int i,len_buf,kolichestvo=0,dlina_buf;
    int f=0,j=0;
    FILE *fp1;
    FILE *fp2;
    char buf[LEN],s1[LEN],s2[LEN],s3[LEN];
      for (i=0;s[i];i++)
    {
      if ((s[i]=='\\'&&s[i+1]=='['))
      {s1[j]='[';s2[j]='0';s3[j]='0';j++;i++;}
      else if ((s[i]=='\\'&&s[i+1]==']'))
      {s1[j]=']';s2[j]='0';s3[j]='0';j++;i++;}
      else if ((s[i]=='\\'&&s[i+1]=='\\'))
      {s1[j]='\\';s2[j]='0';s3[j]='0';j++;i++;}
      else if ((s[i]=='[')&&(s[i-1]!='\\')&&(s[i+2]=='-'))
      {s1[j]='.';s2[j]=s[i+1];s3[j]=s[i+3];i=i+4;j++;}
      else {s1[j]=s[i];s2[j]='0';s3[j]='0';j++;}

    }
    s1[j]=0;
    s2[j]=0;
    s3[j]=0;
    if (!(fp1=fopen(name1,"r")))
        return -1;
    if (!(fp2=fopen(name2,"w")))
        return -1;
    while (fgets(buf,LEN,fp1))
    {
      len_buf=del_newline(buf);
      for (i=0;buf[i];i++)
      if (my_strcmp(s1,s2,s3,buf+i))
      {
	    fprintf(fp2, "%s\n", buf);
        kolichestvo++;
      break;
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


