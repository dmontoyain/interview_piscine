#include "header.h"

int getPlace(unsigned int parkingRow, int pos)
{
    if (!pos)
        return parkingRow & 1;
    return getPlace(parkingRow >> 1, --pos);
}