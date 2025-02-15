/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:15:51 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/15 10:15:51 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	is_valid_number(char *str)
{
	int		pos;

	pos = 0;
	if(str[pos] == '-' || str[pos] == '+')
		pos++;
	if(!str[pos])
		return (0);
	while(str[pos])
	{
		if(str[pos] < '0' || str[pos] > '9')
			return (0);
		pos++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		res;
	int		sign;
	int		pos;

	res = 0;
	sign = 1;
	pos = 0;
	if (str[pos]== '-')
	{
		sign = -1;
		pos++;
	}
	else if (str[pos]== '+')
		pos++;
	while(str[pos] >= '0' && str[pos]<= '9')
	{
		res = (res * 10) + (str[pos] - '0');
		pos++;
	}
	return (res * sign);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	if(!node)
		return (NULL);
	node->content = value;
	node->next = NULL;
	return (node);
}

int	push_node(t_node **first, int *size, int value)
{
	t_node	*new_node;

	new_node = create_node(value);
	if(!new_node)
		return (0);
	new_node->next = *first;
	*first = new_node;
	(*size)++;
	return (1);
}

void	free_list(t_node *first)
{
	t_node	*current;
	t_node	*next;

	current = first;
	while(current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
