/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:56:43 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/20 10:36:05 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*int main()
{
    char character = '\0'; // Example character to write
    int fd = STDOUT_FILENO; // Use STDOUT_FILENO for standard output (console)

    ft_putchar_fd(character, fd); // Write 'A' to standard output

    return 0;
}
*/
