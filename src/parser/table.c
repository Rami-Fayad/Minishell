/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <ral-faya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:00:08 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/21 13:35:33 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#define SETS 4
#define TERMINALS 13

static t_token_type	*parse_table(t_nonterminal nts);

t_bool	first_set(t_nonterminal nts, t_scanner *scanner)
{
	t_token_type	*table;

	table = parse_table(nts);
	return (table[peek(scanner).type] != TOKEN_UNKNOWN);
}

static t_token_type	*parse_table(t_nonterminal nts)
{
	static t_token_type	first[SETS][TERMINALS] = {
	[LIST] = {TOKEN_UNKNOWN, TOKEN_LESS, TOKEN_GREAT, TOKEN_UNKNOWN,
		TOKEN_LEFT_PAREN, TOKEN_UNKNOWN, TOKEN_UNKNOWN, TOKEN_UNKNOWN,
		TOKEN_DLESS, TOKEN_DGREAT, TOKEN_WORD, TOKEN_UNKNOWN, TOKEN_UNKNOWN,
	},
	[SIMPLE_CMD] = {TOKEN_UNKNOWN, TOKEN_LESS, TOKEN_GREAT, TOKEN_UNKNOWN,
		TOKEN_UNKNOWN, TOKEN_UNKNOWN, TOKEN_UNKNOWN, TOKEN_UNKNOWN,
		TOKEN_DLESS, TOKEN_DGREAT, TOKEN_WORD, TOKEN_UNKNOWN, TOKEN_UNKNOWN,
	},
	[IO_REDIRECT] = {TOKEN_UNKNOWN, TOKEN_LESS, TOKEN_GREAT, TOKEN_UNKNOWN,
		TOKEN_UNKNOWN, TOKEN_UNKNOWN, TOKEN_UNKNOWN, TOKEN_UNKNOWN, TOKEN_DLESS,
		TOKEN_DGREAT, TOKEN_UNKNOWN, TOKEN_UNKNOWN, TOKEN_UNKNOWN,
	},
	[IO_FILE] = {TOKEN_UNKNOWN, TOKEN_LESS, TOKEN_GREAT, TOKEN_UNKNOWN,
		TOKEN_UNKNOWN, TOKEN_UNKNOWN, TOKEN_UNKNOWN, TOKEN_UNKNOWN,
		TOKEN_UNKNOWN, TOKEN_DGREAT, TOKEN_UNKNOWN, TOKEN_UNKNOWN,
		TOKEN_UNKNOWN,
	},
	};

	return (first[nts]);
}
