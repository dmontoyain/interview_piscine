#include "header.h"
#include <stdio.h>

/*
To return the left-most value found in the shifted arrray
*/
int findfirst(int *rocks, int found, int value)
{
    int i;
    int newi;

    i = 1;
    newi = found;
    if (found > 0)
        while ((found - i) >= 0)
        {
            if (rocks[found - i] == value)
                newi = found - i;
            i++;
        }
    return newi;
}

int binarySearch(int *rocks, int left, int right, int value)
{
    int mid;
    int result;

    if (right >= left)
    {
        mid = left + (right - left) / 2;    
        if (rocks[mid] == value)
            return mid;
        if (rocks[left] == value)
            return left;
        if (rocks[right] == value)
            return right;
        if (rocks[mid] < value)
        {
            if ((result = binarySearch(rocks, mid + 1, right, value)) != -1)
                return result;
        }
        return binarySearch(rocks, left, mid - 1, value);
    }
    return -1;
}

int searchShifted(int *rocks, int length, int value)
{
    return findfirst(rocks, binarySearch(rocks, 0, length - 1, value), value);
}