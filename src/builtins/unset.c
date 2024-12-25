/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:10:36 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 14:11:15 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_unset(char **args)
{
	size_t	size;

	size = strtab_size(args);
	if (size == 1)
		return (EXIT_SUCCESS);
	while (*(++args))
	{
		if (ft_strncmp(*args, "PATH", ft_strlen(*args)) == 0)
		{
			free_pathtab();
			init_pathtab();
		}
		ft_unsetenv(*args);
	}
	return (EXIT_SUCCESS);
}
