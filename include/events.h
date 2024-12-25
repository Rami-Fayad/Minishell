/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:53:04 by ral-faya          #+#    #+#             */
/*   Updated: 2024/09/03 16:53:28 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <signal.h>
# include <sys/types.h>

# include "libft.h"
# include "helpers.h"

typedef void	t_handler(int);

void			wait_user_signals(void);
void			wait_child_signals(void);
void			wait_heredoc_signals(void);
void			show_new_prompt(int sig);
void			exit_heredoc(int sig);
void			exit_child(int sig);
void			heredoc_parent_sighandler(void);

#endif
