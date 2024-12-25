/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:51:33 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 15:52:37 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*pipeline_null(t_scanner *scanner)
{
	t_node	*child;

	if (match(TOKEN_PIPE, scanner))
	{
		child = pipeline(scanner);
		if (child)
			return (mknode(PIPE, NULL, child));
	}
	return (NULL);
}

t_node	*subshell(t_scanner *scanner)
{
	t_node	*parent;

	parent = NULL;
	if (match(TOKEN_LEFT_PAREN, scanner))
	{
		parent = list(scanner);
		if (parent && match(TOKEN_RIGHT_PAREN, scanner))
			return (mknode(SUBSHELL, parent, NULL));
	}
	syntax_error(scanner);
	return (parent);
}

t_node	*subshell_redir(t_scanner *scanner)
{
	if (first_set(IO_REDIRECT, scanner))
		return (redirect_list(scanner));
	return (NULL);
}

t_node	*simple_cmd(t_scanner *scanner)
{
	t_node	*parent;
	t_node	*child;

	if (peek(scanner).type == TOKEN_WORD)
		return (word_null(scanner));
	if (first_set(CMD_PREFIX, scanner))
	{
		parent = cmd_prefix(scanner);
		if (parent)
		{
			child = fcmd_prefix(scanner);
			return (subtree(parent, child));
		}
	}
	syntax_error(scanner);
	return (NULL);
}

t_node	*word_null(t_scanner *scanner)
{
	if (first_set(CMD_SUFFIX, scanner))
		return (cmd_suffix(scanner));
	return (NULL);
}
