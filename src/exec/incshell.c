/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <ral-faya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:14:23 by ral-faya          #+#    #+#             */
/*   Updated: 2024/09/21 13:18:08 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "events.h"
#include "exec.h"
#include "expansion.h"

void	update_shlvl_value(t_list *current)
{
	char	*shlvl_value;
	char	*new_shlvl;
	int		shlvl_int;

	shlvl_value = current->content + 6;
	shlvl_int = ft_atoi(shlvl_value);
	if (shlvl_int < 0)
		shlvl_int = 1;
	else
		shlvl_int += 1;
	new_shlvl = ft_itoa(shlvl_int);
	if (!new_shlvl)
		return ;
	free(current->content);
	current->content = ft_strjoin("SHLVL=", new_shlvl);
	free(new_shlvl);
}

int	search_and_update_shlvl(t_list **envl)
{
	t_list	*current;

	current = *envl;
	while (current)
	{
		if (ft_strncmp(current->content, "SHLVL=", 6) == 0)
		{
			update_shlvl_value(current);
			return (1);
		}
		current = current->next;
	}
	return (0);
}

void	increment_shlvl(t_list **envl)
{
	if (!search_and_update_shlvl(envl))
	{
		ft_lstadd_back(envl, ft_lstnew(ft_strdup("SHLVL=1")));
	}
}
