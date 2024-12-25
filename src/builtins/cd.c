/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <ral-faya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:59:17 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/21 12:45:57 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static char	*get_valid_arg(char **args);
static char	*handle_special_cd(char **args);

int	ft_cd(char **args)
{
	char	pwd[PATH_MAX];
	char	*old_pwd;
	char	*new_dir;

	new_dir = get_valid_arg(args);
	if (!new_dir)
	{
		msh_error("cd", "too many arguments", 0);
		return (EXIT_FAILURE);
	}
	if (chdir(new_dir))
	{
		msh_error("cd", NULL, 0);
		return (EXIT_FAILURE);
	}
	old_pwd = ft_getenv("PWD");
	ft_setenv("OLDPWD", old_pwd);
	getcwd(pwd, PATH_MAX);
	ft_setenv("PWD", pwd);
	return (EXIT_SUCCESS);
}

static char	*get_valid_arg(char **args)
{
	size_t	size;
	char	*dir_param;

	size = strtab_size(args);
	if (size > 2)
		return (NULL);
	else if (size == 1)
		return (ft_getenv("HOME"));
	dir_param = handle_special_cd(args);
	if (!dir_param)
		dir_param = args[1];
	return (dir_param);
}

static char	*check_special_options(char *arg, size_t arg_len)
{
	char	*old_pwd;

	if (arg_len > 1 && arg[0] == '-' && arg[1] == '-' && arg[2] != '\0')
	{
		return (NULL);
	}
	if (arg_len == 1 && ft_strncmp(arg, "-", 1) == 0)
	{
		old_pwd = ft_getenv("OLDPWD");
		if (old_pwd)
			return (old_pwd);
		return (ft_getenv("PWD"));
	}
	if (ft_strncmp(arg, "--", 2) == 0)
		return (ft_getenv("HOME"));
	return (NULL);
}

static char	*handle_special_cd(char **args)
{
	static char	pwd[PATH_MAX];
	size_t		arg_len;
	char		*dir_param;

	arg_len = ft_strlen(args[1]);
	dir_param = check_special_options(args[1], arg_len);
	if (dir_param)
		return (dir_param);
	if (arg_len == 1 && ft_strncmp(args[1], "~", 1) == 0)
		return (ft_getenv("HOME"));
	if (arg_len == 1 && ft_strncmp(args[1], ".", 1) == 0)
	{
		getcwd(pwd, PATH_MAX);
		return (pwd);
	}
	if (arg_len == 2 && ft_strncmp(args[1], "..", 2) == 0)
		return ("..");
	return (args[1]);
}
