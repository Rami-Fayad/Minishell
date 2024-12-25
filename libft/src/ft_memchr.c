/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:10:19 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/14 12:17:24 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/
/*#include <stdlib.h>*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = (const unsigned char *)s;
	while (n--)
	{
		if (*p == (unsigned char) c)
			return ((void *) p);
		p++;
	}
	return (NULL);
}
/*int main() {
    char str[] = "Hello, World!";
    char *result;

    // Search for 'W' in the string
    result = (char *)ft_memchr(str, 'e', sizeof(str));
    if (result != NULL) {
        printf("Found 'W' at position %ld\n", result - str);
    } else {
        printf("Did not find 'W' in the string\n");
    }

    // Search for 'Z' in the string
    result = (char *)ft_memchr(str, 'Z', sizeof(str));
    if (result != NULL) {
        printf("Found 'Z' at position %ld\n", result - str);
    } else {
        printf("Did not find 'Z' in the string\n");
    }

    return 0;
}
*/
