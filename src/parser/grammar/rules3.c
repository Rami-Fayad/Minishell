/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:52:43 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 15:54:01 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*fcmd_prefix(t_scanner *scanner)
{
	t_node	*parent;
	t_node	*child;

	if (peek(scanner).type == TOKEN_WORD)
	{
		parent = mkleaf(next(scanner));
		child = word_null(scanner);
		return (subtree(parent, child));
	}
	return (NULL);
}

t_node	*cmd_prefix(t_scanner *scanner)
{
	t_node	*parent;
	t_node	*child;

	if (first_set(IO_REDIRECT, scanner))
	{
		parent = io_redirect(scanner);
		if (parent)
		{
			child = cmd_prefix_null(scanner);
			return (subtree(parent, child));
		}
	}
	syntax_error(scanner);
	return (NULL);
}

t_node	*cmd_prefix_null(t_scanner *scanner)
{
	t_node	*parent;
	t_node	*child;

	if (first_set(IO_REDIRECT, scanner))
	{
		parent = io_redirect(scanner);
		if (parent)
		{
			child = cmd_prefix_null(scanner);
			return (subtree(parent, child));
		}
	}
	return (NULL);
}

t_node	*cmd_suffix(t_scanner *scanner)
{
	t_node	*parent;
	t_node	*child;

	if (first_set(IO_REDIRECT, scanner))
	{
		parent = io_redirect(scanner);
		if (parent)
		{
			child = cmd_suffix_null(scanner);
			return (subtree(parent, child));
		}
	}
	if (peek(scanner).type == TOKEN_WORD)
	{
		parent = mkleaf(next(scanner));
		child = cmd_suffix_null(scanner);
		return (subtree(parent, child));
	}
	syntax_error(scanner);
	return (NULL);
}

t_node	*cmd_suffix_null(t_scanner *scanner)
{
	t_node	*parent;
	t_node	*child;

	if (first_set(IO_REDIRECT, scanner))
	{
		parent = io_redirect(scanner);
		if (parent)
		{
			child = cmd_suffix_null(scanner);
			return (subtree(parent, child));
		}
	}
	if (peek(scanner).type == TOKEN_WORD)
	{
		parent = mkleaf(next(scanner));
		child = cmd_suffix_null(scanner);
		return (subtree(parent, child));
	}
	return (NULL);
}
