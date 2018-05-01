#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
    if (!parkingRow)
        return -1;
    if ((parkingRow | 1) == 1)
        return 0;
    return leftmostCar(parkingRow >> 1) + 1; 
}