/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:09:21 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/17 13:44:52 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	ss1;
	size_t	ss2;

	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	if (s1 == 0 || s2 == 0)
		return (NULL);
	s = (char *)malloc (ss1 + ss2 + 1);
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, ss1);
	ft_memcpy(s + ss1, s2, ss2 + 1);
	return (s);
}
