/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:35:43 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 15:42:35 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	msh_error(char *name, char *msg, int error)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (msg == NULL && error == 0)
	{
		perror(name);
		return ;
	}
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	else if (error)
		ft_putendl_fd(strerror(error), STDERR_FILENO);
}
