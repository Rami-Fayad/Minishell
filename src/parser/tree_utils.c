/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:57:22 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 16:02:15 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "tree.h"

static t_node	*append_cmd(t_node *command, t_node *param);
static t_node	*insert_left(t_node *parent, t_node *child);
static t_node	*insert_command(t_node *parent, t_node *child);

t_node	*subtree(t_node *node, t_node *child)
{
	if (child == NULL)
		return (node);
	if (node && child)
		return (insert_left(node, child));
	return (NULL);
}

static t_node	*insert_left(t_node *parent, t_node *child)
{
	t_node	**aux;

	aux = &parent->data.pair.left;
	if (parent->type == COMMAND)
		return (insert_command(parent, child));
	else if (*aux == NULL)
		*aux = child;
	else if ((*aux)->type == COMMAND)
		*aux = insert_left(child, *aux);
	else
		insert_left(*aux, child);
	return (parent);
}

static t_node	*insert_command(t_node *parent, t_node *child)
{
	if (child->type == COMMAND)
		return (append_cmd(parent, child));
	return (insert_left(child, parent));
}

static t_node	*append_cmd(t_node *command, t_node *param)
{
	int		str;
	int		size;
	char	**new_cmd;

	size = 0;
	size += strtab_size(command->data.cmd);
	size += strtab_size(param->data.cmd);
	new_cmd = ft_calloc(sizeof(*new_cmd), size + 1);
	str = 0;
	size = 0;
	while (command->data.cmd[str])
		new_cmd[size++] = command->data.cmd[str++];
	str = 0;
	while (param->data.cmd[str])
		new_cmd[size++] = param->data.cmd[str++];
	free(command->data.cmd);
	free(param->data.cmd);
	free(param);
	command->data.cmd = new_cmd;
	return (command);
}
