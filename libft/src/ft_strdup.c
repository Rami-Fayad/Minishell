/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:49:40 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/13 16:16:57 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		index;
	char	*dest;
	char	*d;

	index = 0;
	d = ((dest = (char *)malloc(ft_strlen(s) * sizeof(char) + 1)));
	if (!d)
	{
		return (0);
	}
	while (s[index])
	{
		dest[index] = s[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
/*char *ft_strdup(const char *s);

int main() {
    const char *original = "Hello, world!";
    char *duplicate = ft_strdup(original);

    if (duplicate != NULL) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);

        // Don't forget to free the memory allocated by strdup
        free(duplicate);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/
