/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:33:02 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/14 17:59:00 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c1;
	const unsigned char	*c2;
	size_t				i;

	i = 0;
	c1 = s1;
	c2 = s2;
	while (i < n)
	{
		if (c1[i] != c2[i])
		{
			return (c1[i] - c2[i]);
		}
		i++;
	}
	return (0);
}
// int main() {
//     char str1[] = "Hello";
//     char str2[] = "Hellw";
//     int result;

//     // Compare the first 3 characters of str1 and str2
//     result = ft_memcmp(str1, str2, 3);
//     printf("Result of ft_memcmp for first 3 characters: %d\n", result);

//     // Compare the first 5 characters of str1 and str2
//     result = ft_memcmp(str1, str2, 5);
//     printf("Result of ft_memcmp for first 5 characters: %d\n", result);

//     // Compare the first 7 characters of str1 and str2
//     result = ft_memcmp(str1, str2, 7);
//     printf("Result of ft_memcmp for first 7 characters: %d\n", result);

//     return 0;
// }
