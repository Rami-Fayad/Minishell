/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <ral-faya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:38:23 by ral-faya          #+#    #+#             */
/*   Updated: 2024/09/21 17:00:01 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define GREEN_PROMPT "\001\e[1;34m\002[\001\e[1;36m\00242 \
Beirut\001\e[1;34m\002]\001\e[1;32m\002 ➜  \001\e[m\002"

static void	msh_loop(void)
{
	t_bool		quit;
	char		*cmdline;
	t_scanner	scanner;
	t_node		*root;

	cmdline = "";
	while (cmdline)
	{
		cmdline = readline(GREEN_PROMPT);
		if (cmdline)
		{
			if (*cmdline)
				add_history(cmdline);
			scanner = init_scanner(cmdline);
			root = parse(&scanner);
			quit = execute(root);
			free_tree(root);
			free(cmdline);
			if (quit)
				cmdline = NULL;
		}
	}
}

static	void	prompt_logo(void)
{
	printf("\033[0;32m"
		"  _______        __       ___      ___   __            &    \n"
		" /\"      \\      /\"\"\\     |\"  \\    /\"  | |\" \\                \n"
		"|:        |    /    \\     \\   \\  //   | ||  |               \n"
		"|_____/   )   /' /\\  \\    /\\\\  \\/.    | |:  |               \n"
		" //      /   //  __'  \\  |: \\.        | |.  |               \n"
		"|:  __   \\  /   /  \\\\  \\ |.  \\    /:  | /\\  |\\              \n"
		"|__|  \\___)(___/    \\___)|___|\\__/|___|(__\\_|_)             \n"
		"                                                            \n"
		"  ________     __      ___       ___      ___       __      \n"
		" /\"       )   /\"\"\\    |\"  |     |\"  \\    /\"  |     /\"\"\\     \n"
		"(:   \\___/   /    \\   ||  |      \\   \\  //   |    /    \\    \n"
		" \\___  \\    /' /\\  \\  |:  |      /\\\\  \\/.    |   /' /\\  \\   \n"
		"  __/  \\\\  //  __'  \\  \\  |___  |: \\.        |  //  __'  \\  \n"
		" /\" \\   :)/   /  \\\\  \\( \\_|:  \\ |.  \\    /:  | /   /  \\\\  \\ \n"
		"(_______/(___/    \\___)\\_______)|___|\\__/|___|(___/    \\___)\n"
		"============================================================\n"
		"                  Crafted with care by\n"
		"               Rami Al Fayad & Salma Dalaty, 2024               \n"
		"============================================================\n\n"
		"\033[0m"
		);
}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	prompt_logo();
	wait_user_signals();
	init_environ(envp);
	increment_shlvl(get_envl());
	init_pathtab();
	msh_loop();
	free_pathtab();
	free_environ();
	rl_clear_history();
	ft_putendl_fd("exit", STDOUT_FILENO);
	return (*get_exit_status());
}
