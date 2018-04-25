/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:53:10 by dmontoya          #+#    #+#             */
/*   Updated: 2018/04/23 12:53:10 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

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

void    sortArts(struct s_art **arts)
{
    int n = 0;

    for (int i = 0; arts[i] != NULL; i++)
        n++;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arts, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arts[0], &arts[i]);

        heapify(arts, i, 0);
    }
}
