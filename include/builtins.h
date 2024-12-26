/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <ral-faya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:26:51 by ral-faya          #+#    #+#             */
/*   Updated: 2024/09/21 12:43:26 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <dirent.h>
# include <limits.h>

# include "exec.h"
# include "helpers.h"

# define NEW_LINE "-n"

typedef int	(*t_builtin)(char **args);

t_builtin	builtin_pool(char *name, t_context *ctx);
int			ft_echo(char **args);
int			ft_env(char **args);
int			ft_pwd(char **args);
int			ft_unset(char **args);
int			ft_cd(char	**args);
int			ft_export(char	**args);
int			ft_exit(char **args);

#endif
