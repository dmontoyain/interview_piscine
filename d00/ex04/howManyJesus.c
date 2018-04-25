/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howmanyjesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:28:57 by dmontoya          #+#    #+#             */
/*   Updated: 2018/04/23 20:29:04 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#define d 256

int     howManyJesus(char *bible, char *jesus)
{
    int txt_len = strlen(bible);
    int pattern_len = strlen(jesus);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int foundpattern = 0;
    int q = 101;

    for (i = 0; i < pattern_len-1; i++)
        h = (h*d)%q;
 
    for (i = 0; i < pattern_len; i++)
    {
        p = (d * p + jesus[i]) % q;
        t = (d * t + bible[i]) % q;
        printf("t first window hash: %d with char %d\n", t, bible[i]);
    }

    for (i = 0; i <= txt_len - pattern_len; i++)
    {
 
        // Check the hash values of current window of text with pattern
        if ( p == t )
        {
            /* Validate characters of both */
            for (j = 0; j < pattern_len; j++)
            {
                if (bible[i+j] != jesus[j])
                    break;
            }
 
            if (j == pattern_len)
                foundpattern++;
        }
 
        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < txt_len - pattern_len )
        {
            t = (d * (t - bible[i] * h) + bible[i + pattern_len]) % q;
 
            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
                t = (t + q);
        }
    }
    return (foundpattern);
}