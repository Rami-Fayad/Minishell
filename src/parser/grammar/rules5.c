/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:56:11 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 15:56:17 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_node	*mkio(t_node_type type, t_token_type tk, t_scanner *scanner);

t_node	*io_file(t_scanner *scanner)
{
	if (match(TOKEN_LESS, scanner))
		return (mkio(INPUT, TOKEN_WORD, scanner));
	if (match(TOKEN_GREAT, scanner))
		return (mkio(OUTPUT, TOKEN_WORD, scanner));
	if (match(TOKEN_DGREAT, scanner))
		return (mkio(APPEND, TOKEN_WORD, scanner));
	return (NULL);
}

t_node	*io_here(t_scanner *scanner)
{
	if (match(TOKEN_DLESS, scanner))
		return (mkio(HERE_DOC, TOKEN_WORD, scanner));
	return (NULL);
}

static t_node	*mkio(t_node_type type, t_token_type tk, t_scanner *scanner)
{
	t_node	*right;

	if (peek(scanner).type == tk)
	{
		right = mkleaf(next(scanner));
		return (mknode(type, NULL, right));
	}
	syntax_error(scanner);
	return (NULL);
}
