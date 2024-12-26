/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <ral-faya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:53:50 by ral-faya          #+#    #+#             */
/*   Updated: 2024/09/21 12:30:33 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include <dirent.h>

# include "libft.h"
# include "helpers.h"

typedef struct s_regex
{
	size_t	eval_size;
	size_t	pattern_size;
	size_t	write_index;
	t_bool	is_first;
}	t_regex;

t_bool	is_match(char *eval, char *pattern);
void	init_regex(t_regex *regex, char *eval, char *pattern);
void	free_dparr(t_bool **split, size_t length);

char	**expand(char **cmdtab);

char	*variable_expansion(char *string);

t_list	*split_quotes(char *str);

void	parameter_expansion(t_list *list);

char	*concatenate(t_list *list);

t_list	*pathname_expansion(t_list *chunks, t_bool glob);
t_list	*list_matches(char *pattern);
char	**table(t_list *list);
t_bool	has_pattern(t_list *list, char chr);
void	unquote(t_list *list);

#endif
