/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:30:23 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 14:31:04 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "expansion.h"
#include "helpers.h"

static char	*expand_file(char *filename, t_context *ctx);
static void	set_redir(char *file, int fd, int stdfd, t_context *ctx);

void	exec_input(t_node *node, t_context *ctx)
{
	int		fd;
	char	*filename;

	filename = node->data.pair.right->data.cmd[0];
	filename = expand_file(filename, ctx);
	if (filename)
	{
		fd = open(filename, O_RDONLY);
		set_redir(filename, fd, STDIN_FILENO, ctx);
	}
	free(filename);
	exec_node(node->data.pair.left, ctx);
}

void	exec_output(t_node *node, t_context *ctx)
{
	int		fd;
	char	*filename;

	filename = node->data.pair.right->data.cmd[0];
	filename = expand_file(filename, ctx);
	if (filename)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		set_redir(filename, fd, STDOUT_FILENO, ctx);
	}
	free(filename);
	exec_node(node->data.pair.left, ctx);
}

void	exec_append(t_node *node, t_context *ctx)
{
	int		fd;
	char	*filename;

	filename = node->data.pair.right->data.cmd[0];
	filename = expand_file(filename, ctx);
	if (filename)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		set_redir(filename, fd, STDOUT_FILENO, ctx);
	}
	free(filename);
	exec_node(node->data.pair.left, ctx);
}

static char	*expand_file(char *filename, t_context *ctx)
{
	t_list	*list;
	t_bool	pattern;

	list = split_quotes(filename);
	pattern = has_pattern(list, '*');
	if (pattern)
	{
		msh_error(filename, "ambiguous redirect", 0);
		ctx->error = TRUE;
		ctx->retcode = 1;
		ft_lstclear(&list, free);
		return (NULL);
	}
	parameter_expansion(list);
	unquote(list);
	filename = concatenate(list);
	ft_lstclear(&list, free);
	return (filename);
}

static void	set_redir(char *file, int fd, int stdfd, t_context *ctx)
{
	if (fd < 0)
	{
		msh_error(file, NULL, 0);
		ctx->error = TRUE;
		ctx->retcode = 1;
	}
	else
	{
		if (ctx->fd[stdfd] != stdfd)
			close(ctx->fd[stdfd]);
		ctx->fd[stdfd] = fd;
	}
}
