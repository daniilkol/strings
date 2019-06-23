#include <stdlib.h>
#include <stdio.h>
#include "filter.h"
#include "filter.c"
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
int main (void)
{
    const char *name1="a.txt";
    const char *name2="b.txt";
    char s[LEN],t[LEN];
    int result;
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
    result=filter(name1,name2,s,t);
    if (result<0)
    {
        switch(result)
        {

           case -1: printf("Cannot open %s\n",name1); break;
           case -2: printf("Cannot read %s\n",name1); break;
           default: printf("Unknown error\n"); break;
        }
        return 2;
    }
    printf("lines=%d",result);
    return 0;
}
