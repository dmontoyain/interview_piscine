/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:26:52 by dmontoya          #+#    #+#             */
/*   Updated: 2018/04/23 18:26:53 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define CAPACITY 69
#include <string.h>
#include <stdlib.h>

size_t hash(char *input)
{
    size_t ret = 0;

    for (int i = 0; i < (int)strlen(input); i++) {
        ret += (((input[i] << 6) * 69));
    }
    return (ret % CAPACITY);
}

struct s_dict *dictInit(int capacity)
{
    struct s_dict* ret = malloc(sizeof(struct s_dict));
    ret->items = calloc(capacity, sizeof(struct s_item*));
    ret->capacity = capacity;
    return ret;
}

int dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
    struct s_item *item;
    size_t index = hash(key);

    if (!(item = malloc(sizeof(struct s_item))))
        return 0;
    item->key = key;
    item->value = value;
    item->next = dict->items[index];
    dict->items[index] = item;
    return 1;
}

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
    size_t index = hash(key);

    struct s_item* item = dict->items[index];
    while (item)
    {
        if (!strcmp(item->key, key))
            return (item->value);
        item = item->next;
    }
    return 0;
}

int searchPrice(struct s_dict *dict, char *name)
{
    struct s_art *art = dictSearch(dict, name);

    if (!art)
        return 0;
    return art->price;
}