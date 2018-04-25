/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 22:10:01 by dmontoya          #+#    #+#             */
/*   Updated: 2018/04/23 22:10:02 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_dict *dictInit(int capacity)
{
    struct s_dict* ret = malloc(sizeof(struct s_dict));
    ret->items = calloc(capacity, sizeof(struct s_item*));
    ret->capacity = capacity;
    return ret;    
}

char    *compress(char *book, struct s_dict *dict)
{
    
}
