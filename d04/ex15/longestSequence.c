#include "header.h"

int longestSequence(unsigned int parkingRow)
{
    if (!parkingRow)
        return 0;
    return longestSequence(parkingRow & (parkingRow >> 1)) + 1;
}