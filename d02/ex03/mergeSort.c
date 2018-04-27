#include "header.h"
#include <string.h>
#include <stdlib.h>

void    merge(struct s_player **players, struct s_player **left, struct s_player **right)
{
    int l, r, k;
    int nl, nr;

    for (nl = 0; left[nl]; nl++){}
    for (nr = 0; right[nr]; nr++){}

    l = r = k = 0;
    while (l < nl && r < nr)
    {
        if (left[l]->score == right[r]->score)
        {
            if (strcmp(left[l]->timeStamp, right[r]->timeStamp) < 0)
                players[k++] = left[l++];
            else
                players[k++] = right[r++];
        }
        else if (left[l]->score > right[r]->score)
            players[k++] = left[l++];
        else
            players[k++] = right[r++];
    }
    while (l < nl)
        players[k++] = left[l++];
    while (r < nr)
        players[k++] = right[r++];
}

struct s_player     **mergeSort_(struct s_player **players, int n)
{
    int m;
    int i, j = 0;

    struct s_player **tmpl;
    struct s_player **tmpr;
    if (n < 2)
        return players;
    m = n / 2;
    struct s_player **new = calloc(n + 1, sizeof(struct s_player *));
    struct s_player **left = calloc(m, sizeof(struct s_player *));
    struct s_player **right = calloc(n - m, sizeof(struct s_player *));
    for (i = 0; i < m; i++)
        left[i] = players[j++];
    for (i = 0; i < n - m; i++)
        right[i] = players[j++];
    tmpl = left;
    tmpr = right; 
    left = mergeSort_(tmpl, m);
    right = mergeSort_(tmpr, n - m);
    merge(new, left, right);
    freeall(tmpl, tmpr, left, right);
    free(tmpl);
    free(tmpr);
    return new;
}

struct s_player **mergeSort(struct s_player **players)
{
    int n;

    for (n = 0; players[n]; n++){}
    return mergeSort_(players, n);
}