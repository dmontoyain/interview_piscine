/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:43:31 by dmontoya          #+#    #+#             */
/*   Updated: 2018/04/23 15:43:32 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void    swap(struct s_art **art1, struct s_art **art2)
{
    struct s_art *tmp;

    tmp = *art1;
    *art1 = *art2;
    *art2 = tmp;
}

void    heapify(struct s_art **arts, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && strcmp(arts[l]->name, arts[largest]->name) > 0)
        largest = l;
    if (r < n && strcmp(arts[r]->name, arts[largest]->name) > 0)
        largest = r;
    if (largest != i)
    {
        swap(&arts[i], &arts[largest]);

        heapify(arts, n, largest);
    }
}

void    sortArts(struct s_art **arts, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arts, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arts[0], &arts[i]);

        heapify(arts, i, 0);
    }
}

int     binarySearch(struct s_art **arts, int l, int r, char *name)
{
    int cmp;
    int m;

    while (l <= r)
    {
        m = l + (r - l) / 2;
        cmp = strcmp(arts[m]->name, name);
        if (!cmp)
            return (arts[m]->price);

        //shrinking lookup range
        if (cmp < 0)
            l = m + 1;
        else
            r = m - 1;
    }
    return (-1);
}

int     searchPrice(struct s_art **arts, int n, char *name)
{
    sortArts(arts, n - 1);

    return (binarySearch(arts, 0, n - 1, name));
}