/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:02:51 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 14:03:18 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_env(char **args)
{
	t_list	*envl;

	(void) args;
	envl = *get_envl();
	while (envl)
	{
		ft_putendl_fd(envl->content, STDOUT_FILENO);
		envl = envl->next;
	}
	return (EXIT_SUCCESS);
}
