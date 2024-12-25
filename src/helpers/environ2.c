/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:35:36 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 15:41:14 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

static char		*pairjoin(const char *key, const char *value);
static t_list	*_getenv_internal(const char *name, t_list **envl, int remove);

char	*ft_getenv(const char *name)
{
	int		len;
	char	*var;
	t_list	*node;

	node = _getenv_internal(name, get_envl(), FALSE);
	if (node)
	{
		var = node->content;
		len = ft_strlen(name);
		if (ft_strncmp(var, name, len) == 0)
			return (var + len + 1);
	}
	return (NULL);
}

int	ft_setenv(const char *name, const char *value)
{
	t_list	*node;
	char	*env;

	if (!name || name[0] == 0 || ft_strchr(name, '='))
		return (-1);
	env = pairjoin(name, value);
	if (env == NULL)
		return (-1);
	node = _getenv_internal(name, get_envl(), FALSE);
	if (node)
	{
		free(node->content);
		node->content = env;
	}
	else
		ft_lstadd_back(get_envl(), ft_lstnew(env));
	return (EXIT_SUCCESS);
}

int	ft_unsetenv(const char *name)
{
	t_list	*node;

	node = _getenv_internal(name, get_envl(), TRUE);
	if (node)
	{
		ft_lstdelone(node, free);
		return (EXIT_SUCCESS);
	}
	return (-1);
}

static char	*pairjoin(const char *key, const char *value)
{
	char	*var;
	char	*aux;

	aux = ft_strjoin(key, "=");
	if (!aux)
		return (NULL);
	if (!value)
		value = "";
	var = ft_strjoin(aux, value);
	free(aux);
	if (!var)
		return (NULL);
	return (var);
}

static t_list	*_getenv_internal(const char *name, t_list **envl, int remove)
{
	int		len;
	char	*var;
	t_list	*temp;
	t_list	*prev;

	temp = *envl;
	prev = NULL;
	while (temp != NULL)
	{
		var = temp->content;
		if (var[0] == name[0])
		{
			len = ft_strlen(name);
			if (ft_strncmp(var, name, len) == 0 && var[len] == '=')
				break ;
		}
		prev = temp;
		temp = temp->next;
	}
	if (remove && prev && temp)
		prev->next = temp->next;
	else if (!prev && temp)
		*envl = temp->next;
	return (temp);
}
