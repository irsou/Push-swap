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

#include "../push_swap.h"

int	is_valid_number(char *str)
{
	int		pos;

	pos = 0;
	if (str[pos] == '-' || str[pos] == '+')
		pos++;
	if (!str[pos])
		return (0);
	while (str[pos])
	{
		if (str[pos] < '0' || str[pos] > '9')
			return (0);
		pos++;
	}
	return (1);
}

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

int	push_node(t_stack **first, int *size, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = create_node(value);
	if (!new_node)
		return (0);
	new_node->next = NULL;
	if (*first == NULL)
		*first = new_node;
	else
	{
		current = *first;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	(*size)++;
	return (1);
}

void	assign_node_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;
	int		position;

	current = stack;
	while (current)
	{
		position = 0;
		temp = stack;
		while (temp)
		{
			if (current->content > temp->content)
				position++;
			temp = temp->next;
		}
		current->index = position;
		current = current->next;
	}
}

void	free_list(t_stack *first)
{
	t_stack	*current;
	t_stack	*next;

	current = first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
