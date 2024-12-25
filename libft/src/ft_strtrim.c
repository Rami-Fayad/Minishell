/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:40:46 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/18 12:30:20 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	result = malloc (len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy (result, s1 + start, len + 1);
	return (result);
}
// int main() {
//     char *s1 = " ";
//     char *set = "H";

//     char *trimmed = ft_strtrim(s1, set);
//     if (trimmed) {
//         printf("Trimmed string: \"%s\"\n", trimmed);
//         free(trimmed);
//     } else {
//         printf("Memory allocation failed or input string was NULL.\n");
//     }

//     return 0;
// }
