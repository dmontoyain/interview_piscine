#include "header.h"

void swap(struct s_player **player_a, struct s_player **player_b)
{
    struct s_player *tmp = *player_b;
    *player_b = *player_a;
    *player_a = tmp;
}

int partition (struct s_player **players, int low, int high)
{
    int pivot = players[high]->score;
    int i = low - 1;
 
    for (int j = low; j <= high- 1; j++)
    {
        if (players[j]->score > pivot)
            swap(&players[++i], &players[j]);
    }
    swap(&players[i + 1], &players[high]);
    return (i + 1);
}

void quickSort_(struct s_player **players, int low, int high)
{
    int pi;

    if (low < high)
    {
        pi = partition(players, low, high);
 
        quickSort_(players, low, pi - 1);
        quickSort_(players, pi + 1, high);
    }
}

void quickSort(struct s_player **players)
{
    int i;

    for (i = 0; players[i]; i++){}
    quickSort_(players, 0, i - 1);
}