/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <ral-faya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:01:36 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/21 12:52:32 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	write_output(char **word, size_t index);

int	ft_echo(char **args)
{
	int		new_line_flag;
	size_t	index;

	new_line_flag = 1;
	index = 1;
	if (args[1] && !ft_strncmp(args[1], "-n", 3))
	{
		new_line_flag = 0;
		index = 2;
	}
	if (!args[index])
	{
		if (new_line_flag)
			ft_putstr_fd("\n", 1);
		return (EXIT_SUCCESS);
	}
	write_output(args, index);
	if (new_line_flag)
		ft_putstr_fd("\n", 1);
	return (EXIT_SUCCESS);
}

static void	write_output(char **word, size_t index)
{
	while (word && word[index + 1])
	{
		ft_putstr_fd(word[index], 1);
		ft_putstr_fd(" ", 1);
		index++;
	}
	ft_putstr_fd(word[index], 1);
}
