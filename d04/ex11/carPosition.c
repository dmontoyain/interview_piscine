#include "header.h"

int occupiedPlaces(unsigned int parkingRow)
{
    return (!parkingRow) ? 0 : occupiedPlaces(parkingRow &= (parkingRow - 1)) + 1;
}

int carPosition(unsigned int parkingRow)
{
    if (!parkingRow || occupiedPlaces(parkingRow) > 1)
        return -1;
    unsigned int count = 0;
    while ((parkingRow /= 2))
        count++;
    return count;
}