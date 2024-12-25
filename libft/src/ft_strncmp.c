/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:38:30 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/14 16:03:46 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (*p1 && *p1 == *p2 && n)
	{
		p1++;
		p2++;
		n--;
	}
	if (n > 0)
		return (*p1 - *p2);
	else
		return (0);
}
/*int ft_strncmp(const char *s1, const char *s2, size_t n);

int main() {
    const char *s1 = "Hello";
    const char *s2 = "Hell";
    int result = ft_strncmp(s1, s2, 4);

    if (result == 0) {
        printf("Strings are equal.\n");
    } else if (result < 0) {
        printf("s1 is less than s2.\n");
    } else {
        printf("s1 is greater than s2.\n");
    }

    return 0;
}
*/
