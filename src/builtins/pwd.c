/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <ral-faya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:09:31 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/21 12:54:18 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(char **args)
{
	char	*pwd;

	(void) args;
	pwd = ft_getenv("PWD");
	if (pwd)
		printf("%s\n", pwd);
	if (!pwd)
		msh_error("pwd", "Environment variable doesn't exist.", 0);
	return (EXIT_SUCCESS);
}
