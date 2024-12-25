/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <ral-faya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:27:05 by ral-faya          #+#    #+#             */
/*   Updated: 2024/09/21 12:29:52 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "helpers.h"
# include "parser.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/wait.h>

# define FORKED_CHILD 0
# define PIPE_LIMIT 1024
# define HEREDOC_TEMPFILE "/tmp/heredoc_tempfile"

typedef struct s_context
{
	int		fd[2];
	int		pid[PIPE_LIMIT];
	int		fd_close;
	int		proc;
	t_byte	retcode;
	t_bool	error;
	t_bool	quit;
	t_bool	pipeline;
}			t_context;

t_bool		execute(t_node *root);
void		exec_node(t_node *node, t_context *ctx);
void		exec_command(t_node *node, t_context *ctx);
void		exec_input(t_node *node, t_context *ctx);
void		exec_output(t_node *node, t_context *ctx);
void		exec_append(t_node *node, t_context *ctx);
void		exec_pipe(t_node *node, t_context *ctx);
void		exec_and(t_node *node, t_context *ctx);
void		exec_or(t_node *node, t_context *ctx);
void		exec_heredoc(t_node *node, t_context *ctx);
void		exec_subshell(t_node *node, t_context *ctx);
t_bool		exec_builtin(char **argv, t_context *ctx);

void		enqueue(long pid, t_context *ctx);
void		copy_queue(t_context *ctx, t_context aux_ctx);
void		redirect_io(int saved[], t_context *ctx);
void		restore_io(int saved[]);
void		reaper(t_context *ctx);
void		update_shlvl_value(t_list *current);
void		increment_shlvl(t_list **envl);

void		set_exit_status(int status);
int			*get_exit_status(void);
void		save_tree_ref(t_node *root);
t_node		**get_tree_ref(void);
void		msh_clean(void);

void		here_doc(char *delimiter);
void		set_fd_close(int fd);
int			*get_fd_close(void);
int			count_env_list(t_list *envl);
int			search_and_update_shlvl(t_list **envl);
char		**fill_env_array(t_list *envl, char **env_array);
char		**convert_envl_to_array(t_list *envl);

#endif
