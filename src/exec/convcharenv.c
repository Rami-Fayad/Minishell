/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convcharenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <ral-faya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:17:00 by ral-faya          #+#    #+#             */
/*   Updated: 2024/09/21 13:17:23 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "events.h"
#include "exec.h"
#include "expansion.h"

int	count_env_list(t_list *envl)
{
	int		count;
	t_list	*current;

	count = 0;
	current = envl;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

char	**fill_env_array(t_list *envl, char **env_array)
{
	int		i;
	t_list	*current;

	i = 0;
	current = envl;
	while (current)
	{
		env_array[i] = ft_strdup((char *)current->content);
		if (!env_array[i])
		{
			while (i > 0)
				free(env_array[--i]);
			free(env_array);
			return (NULL);
		}
		current = current->next;
		i++;
	}
	env_array[i] = NULL;
	return (env_array);
}

char	**convert_envl_to_array(t_list *envl)
{
	int		count;
	char	**env_array;

	count = count_env_list(envl);
	env_array = (char **)malloc((count + 1) * sizeof(char *));
	if (!env_array)
		return (NULL);
	return (fill_env_array(envl, env_array));
}
