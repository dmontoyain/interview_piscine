#include "header.h"
#include <string.h>  

void    countSort(unsigned char *utensils, int n)
{
    int k, i;
    int count[NUMBER_OF_USTENSILS + 1];
    
    k = 0;
    memset(count, 0, sizeof(count));
    for(i = 0; i < n; ++i)
        ++count[utensils[i]];

    for (i = 0; i <= NUMBER_OF_USTENSILS; i++)
        while (count[i]-- > 0)
            utensils[k++] = i;
}