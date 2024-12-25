/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:42:28 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 14:51:58 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

void	init_regex(t_regex *regex, char *eval, char *pattern)
{
	regex->eval_size = ft_strlen(eval);
	regex->pattern_size = ft_strlen(pattern);
	regex->write_index = 0;
	regex->is_first = TRUE;
}

void	free_dparr(t_bool **split, size_t length)
{
	size_t	x;

	x = 0;
	while (x < length)
	{
		free(split[x]);
		x++;
	}
	free(split);
}
