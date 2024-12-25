/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:37:32 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/13 15:20:12 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*dst && i < size)
	{
		dst++;
		i++;
	}
	if (i == size)
		return (i + ft_strlen(src));
	while (src[j])
	{
		if (j < size - i - 1)
			*dst++ = src[j];
		j++;
	}
	*dst = '\0';
	return (i + j);
}
/*int main() {
    char dst[20] = "Hello";
    const char *src = ", world!";
    size_t result = ft_strlcat(dst, src, sizeof(dst));

    printf("Concatenated string: %s\n", dst);
    printf("Total length: %zu\n", result);

    return 0;
}
*/
