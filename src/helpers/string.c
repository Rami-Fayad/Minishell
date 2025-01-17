/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <sdalaty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:36:21 by sdalaty           #+#    #+#             */
/*   Updated: 2024/09/14 15:45:54 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordcount(char *str, char *word)
{
	int	pos;
	int	counter;
	int	wordlen;

	pos = 0;
	counter = 0;
	wordlen = ft_strlen(word);
	while (str[pos])
	{
		if (ft_strnstr(&str[pos], word, ft_strlen(&str[pos])) == &str[pos])
		{
			counter++;
			pos += wordlen - 1;
		}
		pos++;
	}
	return (counter);
}

char	*str_replace(char *str, char *oldw, char *neww)
{
	int		pos;
	int		neww_len;
	int		oldw_len;
	char	*result;

	oldw_len = ft_strlen(oldw);
	neww_len = ft_strlen(neww);
	result = malloc(ft_strlen(str) + wordcount(str, oldw) * (neww_len
				- oldw_len) + 1);
	pos = 0;
	while (*str)
	{
		if (ft_strnstr(str, oldw, ft_strlen(str)) == str)
		{
			ft_strlcpy(&result[pos], neww, neww_len + 1);
			pos += neww_len;
			str += oldw_len;
		}
		else
			result[pos++] = *str++;
	}
	result[pos] = '\0';
	return (result);
}

size_t	strtab_size(char **tab)
{
	size_t	str;

	str = 0;
	while (tab[str])
		str++;
	return (str);
}

void	free_strtab(char **tab)
{
	int	str;

	str = 0;
	if (tab == NULL)
		return ;
	while (tab[str])
		free(tab[str++]);
	free(tab);
}
