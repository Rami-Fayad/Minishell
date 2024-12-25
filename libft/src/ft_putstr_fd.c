/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:04:19 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/15 10:55:08 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write (fd, s, 1);
			s++;
		}
	}
}
/*int main() {
    char *message = "Hello, world!\n";
    int fd = STDOUT_FILENO;  // Writing to standard output

    // Call the function to output the message to stdout
    ft_putstr_fd(message, fd);

    return 0;
}
*/
