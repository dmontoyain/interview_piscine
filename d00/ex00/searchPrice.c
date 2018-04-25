/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:47:23 by dmontoya          #+#    #+#             */
/*   Updated: 2018/04/23 11:52:45 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

int		searchPrice(struct s_art **arts, char *name)
{
    struct s_art **art_ptr;

    art_ptr = arts;
    while (*art_ptr)
    {
        if (!strcmp((*art_ptr)->name, name))
            return ((*art_ptr)->price);
        art_ptr++;
    }
    return (-1);
}
