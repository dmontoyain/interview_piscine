#include "header.h"
#include <stdlib.h>
#include <stdio.h>

char    *getSum(char *a, char *b)
{
    int     carry = 48;
    for (int i = 5; i >= 0; i--){
        if (a[i] == b[i] && a[i] == '1')
        {
            if (carry == 49)
                a[i] = '1';
            else
                a[i] = '0';
            carry = 49;
        }
        else if (a[i] == b[i] && a[i] == '0')
        {
            if (carry == 49)
                a[i] = '1';
            else
                a[i] = '0';
            carry = 48;
        }
        else
        {
            if (carry == 49)
                a[i] = '0';
            else
                a[i] = '1';
        }
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