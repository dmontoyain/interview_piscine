#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
    if (!parkingRow)
        return -1;
    if (parkingRow & 1)
        return 0;
    return rightmostCar(parkingRow >> 1) + 1;
}