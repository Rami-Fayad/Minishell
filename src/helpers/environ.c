/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:35:24 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 15:39:49 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	init_environ(char **environ)
{
	int		var;
	t_list	**envl;
	t_list	*new_node;

	var = 0;
	envl = get_envl();
	while (environ[var])
	{
		new_node = ft_lstnew(ft_strdup(environ[var]));
		ft_lstadd_back(envl, new_node);
		var++;
	}
}

t_list	**get_envl(void)
{
	static t_list	*envl;

	return (&envl);
}

void	free_environ(void)
{
	ft_lstclear(get_envl(), free);
}
