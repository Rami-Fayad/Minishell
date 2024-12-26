/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <ral-faya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:29:48 by ral-faya          #+#    #+#             */
/*   Updated: 2024/09/21 12:32:03 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include "libft.h"
# include <stdio.h>
# include <string.h>

void	init_environ(char **environ);

t_list	**get_envl(void);

void	free_environ(void);

char	*ft_getenv(const char *name);

int		ft_setenv(const char *name, const char *value);

int		ft_unsetenv(const char *name);

void	init_pathtab(void);

char	*search_path(char *execfile);

void	free_pathtab(void);

size_t	strtab_size(char **tab);

void	free_strtab(char **tab);

void	msh_error(char *name, char *msg, int error);

int		pfork(void);

int		wordcount(char *str, char *word);

char	*str_replace(char *str, char *oldw, char *neww);

#endif
