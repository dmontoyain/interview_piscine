#include "header.h"

int occupiedPlaces(unsigned int parkingRow)
{
    return (!parkingRow) ? 0 : occupiedPlaces(parkingRow &= (parkingRow - 1)) + 1;
}

int carPosition(unsigned int parkingRow)
{
    return (occupiedPlaces(parkingRow) > 1) ? -1 : (!parkingRow) ? -1 : carPosition(parkingRow >> 1) + 1;
}