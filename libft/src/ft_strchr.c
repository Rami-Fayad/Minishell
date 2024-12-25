/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:01:54 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/20 10:47:30 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*char *ft_strchr(const char *s, int c);

int main() {
    const char *s = "Hello, world!";
    int c = '\0';
    char *result = ft_strchr(s, c);

    if (result != NULL) {
        printf("Character '%c' found at position: %ld\n", c, result - s);
    } else {
        printf("Character '%c' not found in the string.\n", c);
    }

    return 0;
}
*/
