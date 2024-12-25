/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:06:34 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/20 10:59:46 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;

	if (!b && len == 0)
		return (NULL);
	if (*l == '\0')
		return ((char *)b);
	i = 0;
	while (i < len && b[i])
	{
		if (b[i] == l[0])
		{
			j = 0;
			while (l[j] && (i + j) < len)
			{
				if (b[i + j] != l[j])
					break ;
				j++;
			}
			if (l[j] == '\0')
				return ((char *)b + i);
		}
		i++;
	}
	return (NULL);
}
