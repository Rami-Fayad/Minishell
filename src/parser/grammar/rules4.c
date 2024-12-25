/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:54:17 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 15:54:51 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*redirect_list(t_scanner *scanner)
{
	t_node	*parent;
	t_node	*child;

	if (first_set(IO_REDIRECT, scanner))
	{
		parent = io_redirect(scanner);
		if (parent)
		{
			child = redirect_list_null(scanner);
			return (subtree(parent, child));
		}
	}
	syntax_error(scanner);
	return (NULL);
}

t_node	*redirect_list_null(t_scanner *scanner)
{
	t_node	*parent;
	t_node	*child;

	if (first_set(IO_REDIRECT, scanner))
	{
		parent = io_redirect(scanner);
		if (parent)
		{
			child = redirect_list_null(scanner);
			return (subtree(parent, child));
		}
	}
	return (NULL);
}

t_node	*io_redirect(t_scanner *scanner)
{
	if (first_set(IO_FILE, scanner))
		return (io_file(scanner));
	return (io_here(scanner));
}
