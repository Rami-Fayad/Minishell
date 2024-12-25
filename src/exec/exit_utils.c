/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:38:53 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 14:39:45 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	msh_clean(void)
{
	free_pathtab();
	free_environ();
	rl_clear_history();
	free_tree(*get_tree_ref());
}

int	*get_exit_status(void)
{
	static int	status;

	return (&status);
}

void	set_exit_status(int status)
{
	int	*code;

	code = get_exit_status();
	*code = status;
}

void	save_tree_ref(t_node *root)
{
	t_node	**tree;

	tree = get_tree_ref();
	*tree = root;
}

t_node	**get_tree_ref(void)
{
	static t_node	*root;

	return (&root);
}
