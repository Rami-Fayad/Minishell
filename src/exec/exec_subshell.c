/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:31:24 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 14:59:13 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	exec_subshell(t_node *node, t_context *ctx)
{
	int			pid;
	int			saved_fd[2];
	t_node		*list;
	t_context	aux_ctx;

	list = node->data.pair.left;
	redirect_io(saved_fd, ctx);
	aux_ctx = *ctx;
	pid = pfork();
	if (pid == FORKED_CHILD)
	{
		exec_node(list, &aux_ctx);
		restore_io(saved_fd);
		reaper(&aux_ctx);
		msh_clean();
		exit(aux_ctx.retcode);
	}
	restore_io(saved_fd);
	enqueue(pid, ctx);
	reaper(ctx);
}
