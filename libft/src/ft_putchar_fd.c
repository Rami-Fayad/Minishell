/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rami <rami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:56:43 by sdalaty           #+#    #+#             */
/*   Updated: 2024/12/26 00:38:18 by rami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	(void)!write(fd, &c, 1);
}
/*int main()
{
    char character = '\0'; // Example character to write
    int fd = STDOUT_FILENO; // Use STDOUT_FILENO for standard output (console)

    ft_putchar_fd(character, fd); // Write 'A' to standard output

    return 0;
}
*/
