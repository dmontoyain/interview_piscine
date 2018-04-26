#include "header.h"

void insertionSort(struct s_player **players)
{
    int i, j;
    struct s_player *key;
    for (i = 1; players[i]; i++){
        key = players[i];
        j = i - 1;
        while (j >= 0 && key->score > players[j]->score)
        {
            players[j + 1] = players[j];
            j--;
        }
        players[j + 1] = key;
    }
}