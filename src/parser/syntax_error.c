/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:57:04 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 15:59:53 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	show(t_token token);

void	syntax_error(t_scanner *scanner)
{
	t_token	token;

	token = peek(scanner);
	if (token.type == TOKEN_UNKNOWN)
		return ;
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (token.type == TOKEN_ERROR)
		show(token);
	else
	{
		ft_putstr_fd("syntax error near unexpected token ", STDERR_FILENO);
		ft_putchar_fd('`', STDERR_FILENO);
		if (token.type == TOKEN_EOF)
			ft_putstr_fd("newline", STDERR_FILENO);
		else
			show(token);
		ft_putchar_fd('\'', STDERR_FILENO);
	}
	ft_putchar_fd('\n', STDERR_FILENO);
	scanner->next.type = TOKEN_UNKNOWN;
}

static void	show(t_token token)
{
	write(STDERR_FILENO, token.start, token.length);
}
