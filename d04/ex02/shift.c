#include "header.h"
#include <stdio.h>
#include <string.h>

char    *ones_complement(char *bits)
{
    for(int i = 0; i < 6; i++){
        if (bits[i] == 48)
            bits[i] = 49;
        else
            bits[i] = 48;
    }
    return bits;
}

char    *leftShift(char *bin, int k)
{
    int shift = 5 - k;
    for (int i = 0; i <= 5; i++){
        if (shift >= 0)
            bin[i] = bin[5 - shift--];
        else
            bin[i] = 48;
    }
    return bin;
}

char    *rightShift(char *bin, int k)
{
    int shift = 5 - k;
    for (int i = 5; i >= 0; i--){
        if (shift >= 0)
            bin[i] = bin[shift--];
        else
            bin[i] = bin[0];
    }
    return bin;
}

int     toInt(char *bits)
{
    int sign = 0;
    char *str;
    if (bits[0] == '1')
    {
        str = strdup(bits);
        str = ones_complement(str);
        sign = -1;
    }
    else
        str = bits;
    int ret = 0;
    int shift = 4;
    for (int i = 1; i <= 5; i++){
        ret |= (str[i] - '0') << shift--;
    }
    if (sign)
        ret = (ret * sign) + sign;
    return ret;
}