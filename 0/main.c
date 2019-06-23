#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN 1234
#include "filter.h"
#include "filter.c"
int main (void)
{

    const char *name1="a.txt";
    const char *name2="b.txt";
    char s[LEN];
    int result;
    printf ("Input string s:");
    if(!fgets(s,LEN,stdin))
    {
        printf("Cannot read\n");
        return 1;
    }
    del_newline(s);
    result=filter(name1,name2,s);
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
