/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:49:09 by ral-faya          #+#    #+#             */
/*   Updated: 2024/09/12 12:49:12 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem_blk;
	int		blk_size;

	blk_size = nmemb * size;
	if (!blk_size || blk_size / size != nmemb)
		return (NULL);
	mem_blk = malloc(blk_size);
	if (!mem_blk)
		return (NULL);
	ft_bzero(mem_blk, blk_size);
	return (mem_blk);
}
