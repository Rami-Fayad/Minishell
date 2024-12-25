/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:56:51 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 15:59:06 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parser.h"

#define FAILED 2

t_node	*parse(t_scanner *scanner)
{
	t_node	*root;

	if (peek(scanner).type == TOKEN_EOF)
	{
		set_exit_status(EXIT_SUCCESS);
		return (NULL);
	}
	root = list(scanner);
	if (peek(scanner).type != TOKEN_EOF)
	{
		syntax_error(scanner);
		free_tree(root);
		set_exit_status(FAILED);
		return (NULL);
	}
	return (root);
}

t_bool	match(t_token_type type, t_scanner *scanner)
{
	if (peek(scanner).type == type)
	{
		next(scanner);
		return (TRUE);
	}
	return (FALSE);
}
