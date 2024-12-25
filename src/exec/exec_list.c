/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:22:10 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 14:22:51 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	wait_queue(t_context *ctx, t_context *aux);

void	exec_and(t_node *node, t_context *ctx)
{
	t_node		*lhs;
	t_node		*rhs;
	t_context	aux_ctx;

	lhs = node->data.pair.left;
	aux_ctx = *ctx;
	exec_node(lhs, &aux_ctx);
	wait_queue(ctx, &aux_ctx);
	if (ctx->retcode == EXIT_SUCCESS)
	{
		aux_ctx = *ctx;
		rhs = node->data.pair.right;
		exec_node(rhs, &aux_ctx);
		wait_queue(ctx, &aux_ctx);
	}
}

void	exec_or(t_node *node, t_context *ctx)
{
	t_node		*lhs;
	t_node		*rhs;
	t_context	aux_ctx;

	lhs = node->data.pair.left;
	aux_ctx = *ctx;
	exec_node(lhs, &aux_ctx);
	wait_queue(ctx, &aux_ctx);
	if (ctx->retcode != EXIT_SUCCESS)
	{
		aux_ctx = *ctx;
		rhs = node->data.pair.right;
		exec_node(rhs, &aux_ctx);
		wait_queue(ctx, &aux_ctx);
	}
}

static void	wait_queue(t_context *ctx, t_context *aux)
{
	if (aux->proc)
	{
		copy_queue(ctx, *aux);
		reaper(ctx);
	}
	else
		ctx->retcode = aux->retcode;
}
