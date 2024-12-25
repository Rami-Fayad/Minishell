/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:27:16 by ral-faya          #+#    #+#             */
/*   Updated: 2024/09/03 16:27:19 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include "libft.h"

# define TABLE_LOAD_MAX 0.75
# define RIP ((void *)1)

typedef unsigned int	t_uint;

typedef struct s_entry
{
	char	*key;
	char	*value;
}	t_entry;

typedef struct s_table
{
	int		count;
	int		capacity;
	int		type_size;
	t_entry	*data;
}	t_table;

void	init_table(t_table *table);
t_bool	table_set(t_table *table, char *key, char *value);
t_bool	table_get(t_table *table, char *key, char **value);
t_bool	table_delete(t_table *table, char *key);
void	free_table(t_table *table);
t_entry	*find_entry(t_entry *entries, int capacity, char *key);

#endif
