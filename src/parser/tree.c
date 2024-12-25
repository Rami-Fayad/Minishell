/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:57:35 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 16:08:50 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "tree.h"

t_node	*mkleaf(t_token token)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->type = COMMAND;
	node->data.cmd = malloc(sizeof(char *) * 2);
	node->data.cmd[0] = ft_substr(token.start, 0, token.length);
	node->data.cmd[1] = NULL;
	return (node);
}

t_node	*mknode(t_node_type type, t_node *left, t_node *right)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->type = type;
	node->data.pair.left = left;
	node->data.pair.right = right;
	return (node);
}

void	free_tree(t_node *self)
{
	if (self == NULL)
		return ;
	else if (self->type == COMMAND)
		free_strtab(self->data.cmd);
	else
	{
		free_tree(self->data.pair.left);
		free_tree(self->data.pair.right);
	}
	free(self);
}
