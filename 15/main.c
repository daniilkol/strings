#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEN 1234
int del_newline(char* s);
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
int main (void)
{
    const char *name1="a.txt";
    const char *name2="b.txt";
    char s[LEN],t[LEN];
    int result,p,dlina_s,i;
    printf ("Input string s:");
    if(!fgets(s,LEN,stdin))
    {
        printf("Cannot read\n");
        return 1;
    }
    printf ("Input string t:");
    if(!fgets(t,LEN,stdin))
    {
        printf("Cannot read\n");
        return 1;
    }
    del_newline(s);
    del_newline(t);
    for(i=0;s[i];i++)
    {
        if (compare(s[i],t))
            s[i]='\0';
    }
    printf("%s",s);
    return 0;
}
