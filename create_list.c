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

#include "push_swap.h"

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
	node->cost = 0;
	node->best_moves = NULL;
	node->next = NULL;
	return (node);
}

void initialize_operations(t_operations *operations) {
	operations->pb = 0;
	operations->ra = 0;
	operations->rb = 0;
	operations->rr = 0;
	operations->rra = 0;
	operations->rrb = 0;
	operations->rrr = 0;
	operations->max_b = -2147483648;
	operations->min_b = 2147483647;
}

int	push_node(t_stack **first, int *size, int value)
{
	t_stack	*new_node;
	t_stack *current;
    
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
	initialize_operations(&new_node->operations);
	return (1);
}

void assign_node_index(t_stack *stack)
{
	t_stack *current;
	t_stack *temp;
	
	current = stack;
	while (current) {
			int position = 0;
			temp = stack;
			
			while (temp) {
					if (current->content > temp->content)
							position++;
					temp = temp->next;
			}
			
			current->index = position;
			current = current->next;
	}
}

// void assign_node_index(t_stack *head_a) {
// 	int size = 0;
// 	t_stack *temp = head_a;
// 	while (temp) {
// 			size++;
// 			temp = temp->next;
// 	}
// 	int *values = malloc(sizeof(int) * size);
// 	if (!values)
// 			return;
// 	temp = head_a;
// 	for (int i = 0; i < size; i++) {
// 			values[i] = temp->content;
// 			temp = temp->next;
// 	}
// 	for (int i = 0; i < size - 1; i++) {
// 			for (int j = 0; j < size - i - 1; j++) {
// 					if (values[j] > values[j + 1]) {
// 							int swap = values[j];
// 							values[j] = values[j + 1];
// 							values[j + 1] = swap;
// 					}
// 			}
// 	}
// 	temp = head_a;
// 	while (temp) {
// 			for (int i = 0; i < size; i++) {
// 					if (values[i] == temp->content) {
// 							temp->index = i;
// 							values[i] = INT_MIN;
// 							break;
// 					}
// 			}
// 			temp = temp->next;
// 	}
	
// 	free(values);
// }

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
