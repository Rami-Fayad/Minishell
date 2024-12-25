/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:13:20 by ral-faya          #+#    #+#             */
/*   Updated: 2024/09/12 13:13:25 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_byte	*dest;
	t_byte	*source;

	dest = dst;
	source = (t_byte *)src;
	while (n--)
		dest[n] = source[n];
	return (dest);
}
