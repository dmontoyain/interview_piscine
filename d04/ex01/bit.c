#include "header.h"
#include <stdlib.h>
#include <stdio.h>

char    *ones_complement(char *bits)
{
    for(int i = 0; i < 4; i++){
        if (bits[i] == 48)
            bits[i] = 49;
        else
            bits[i] = 48;
    }
    return ++bits;
}

char *getAnd(char *a, char *b)
{
    if (a[0] == '~')
        a = ones_complement(a);
    if (b[0] == '~')
        b = ones_complement(b);
    for (int i = 3; i >= 0; i--){
        if (a[i] == b[i] && a[i] == '1')
            a[i] = '1';
        else
            a[i] = '0';
    }
    return a;
}

char *getOr(char *a, char *b)
{
    if (a[0] == '~')
        a = ones_complement(a);
    if (b[0] == '~')
        b = ones_complement(b);
    for (int i = 5; i >= 0; i--){
        if (a[i] == b[i] && a[i] == 48)
            a[i] = '0';
        else
            a[i] = '1';
    }
    return a;
}

int     toInt(char *bits)
{
    int ret = 0;
    int shift = 3;
    for (int i = 0; i <= 3; i++){
        ret |= (bits[i] - '0') << shift--;
    }
    return ret;
}