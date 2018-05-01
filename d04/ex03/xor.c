#include "header.h"

char *getXor(char *a, char *b)
{
    for (int i = 0; i < 6; i++){
        if (a[i] != b[i])
            a[i] = 49;
        else
            a[i] = 48;
    }
    return a;
}

int     toInt(char *bits)
{
    int ret = 0;
    int shift = 5;
    for (int i = 0; i <= 5; i++){
        ret |= (bits[i] - '0') << shift--;
    }
    return ret;
}