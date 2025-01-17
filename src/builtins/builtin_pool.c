/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:56:03 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 13:57:59 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static t_bool	check_word(char *name, int start, int length, char *rest);

t_builtin	builtin_pool(char *name, t_context *ctx)
{
	if (name[0] == 'c' && check_word(name, 1, 1, "d"))
		return (ft_cd);
	else if (name[0] == 'e')
	{
		if (name[1] == 'c' && check_word(name, 2, 2, "ho"))
			return (ft_echo);
		else if (name[1] == 'n' && check_word(name, 2, 1, "v"))
			return (ft_env);
		else if (name[1] == 'x')
		{
			if (name[2] == 'i' && check_word(name, 3, 1, "t") && ctx)
			{
				ctx->quit = TRUE;
				return (ft_exit);
			}
			if (name[2] == 'p' && check_word(name, 3, 3, "ort"))
				return (ft_export);
		}
	}
	else if (name[0] == 'p' && check_word(name, 1, 2, "wd"))
		return (ft_pwd);
	else if (name[0] == 'u' && check_word(name, 1, 4, "nset"))
		return (ft_unset);
	return (NULL);
}

static t_bool	check_word(char *name, int start, int length, char *rest)
{
	return (ft_memcmp(name + start, rest, length + 1) == 0);
}
