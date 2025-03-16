/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:37:50 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/15 21:37:50 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_min_index(t_stack *stack)
{
	t_stack	*min_node;
	t_stack	*current;

	min_node = NULL;
	current = stack;
	if (!stack)
		return (NULL);
	min_node = stack;
	while (current)
	{
		if (current->index < min_node->index)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

int	calculate_cost(int pos, int stack_size)
{
	if (pos <= stack_size / 2)
		return (pos);
	else
		return (-(stack_size - pos));
}

int	calculate_total_cost(int cost_a, int cost_b)
{
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
		return (get_max(get_abs(cost_a), get_abs(cost_b)));
	else
		return (get_abs(cost_a) + get_abs(cost_b));
}

void	rotate_to_min(t_stack **stack_a, int size_a)
{
	t_stack	*min_node;
	int		min_pos;
	int		min_cost;
	t_stack	*current;

	min_pos = 0;
	min_node = get_min_index(*stack_a);
	current = *stack_a;
	while (current != min_node)
	{
		min_pos++;
		current = current->next;
	}
	min_cost = calculate_cost(min_pos, size_a);
	execute_a_rotations(stack_a, &min_cost);
}
