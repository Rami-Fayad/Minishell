/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:13:30 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 14:14:30 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "events.h"
#include "exec.h"

static void	forked_builtin(char **argv, t_builtin builtin, t_context *ctx);

t_bool	exec_builtin(char **argv, t_context *ctx)
{
	int			saved_fd[2];
	t_bool		is_builtin;
	t_builtin	builtin;

	is_builtin = FALSE;
	builtin = builtin_pool(argv[0], ctx);
	if (builtin)
	{
		is_builtin = TRUE;
		if (ctx->pipeline)
			forked_builtin(argv, builtin, ctx);
		else
		{
			redirect_io(saved_fd, ctx);
			ctx->retcode = builtin(argv);
			restore_io(saved_fd);
		}
	}
	return (is_builtin);
}

static void	forked_builtin(char **argv, t_builtin builtin, t_context *ctx)
{
	int	pid;

	wait_child_signals();
	pid = pfork();
	if (pid == FORKED_CHILD)
	{
		dup2(ctx->fd[STDOUT_FILENO], STDOUT_FILENO);
		dup2(ctx->fd[STDIN_FILENO], STDIN_FILENO);
		if (ctx->fd_close >= 0)
			close(ctx->fd_close);
		ctx->retcode = builtin(argv);
		free_strtab(argv);
		msh_clean();
		close(ctx->fd[STDIN_FILENO]);
		close(ctx->fd[STDOUT_FILENO]);
		exit(ctx->retcode);
	}
	wait_user_signals();
	if (ctx->fd[STDIN_FILENO] != STDIN_FILENO)
		close(ctx->fd[STDIN_FILENO]);
	if (ctx->fd[STDOUT_FILENO] != STDOUT_FILENO)
		close(ctx->fd[STDOUT_FILENO]);
	enqueue(pid, ctx);
}
