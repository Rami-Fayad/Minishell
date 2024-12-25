/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rami <rami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:04:19 by sdalaty           #+#    #+#             */
/*   Updated: 2024/12/26 00:47:18 by rami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	(void)!write(fd, s, len);
}
/*int main() {
    char *message = "Hello, world!\n";
    int fd = STDOUT_FILENO;  // Writing to standard output

    // Call the function to output the message to stdout
    ft_putstr_fd(message, fd);

    return 0;
}
*/
