/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:24:30 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/14 16:11:33 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
	{
		return (ft_strlen(src));
	}
	while (src[i] && (i < size -1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*int main() {
    char src[] = "Hello, world!";
    char dst[20]; // Assuming destination buffer size of 20

    // Call strlcpy
    size_t result = strlcpy(dst, src, sizeof(dst));

    // Print the result
    printf("Copied string: %s\n", dst);
    printf("Length of copied string: %zu\n", result);

    return 0;
}
*/
