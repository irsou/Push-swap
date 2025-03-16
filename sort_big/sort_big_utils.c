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

t_stack	*get_closest_to_target(t_stack *stack_b, int target_value)
{
	t_stack	*closest;
	t_stack	*current;
	int		min_diff;
	int		diff;

	min_diff = 2147483647;
	closest = NULL;
	current = stack_b;
	while (current)
	{
		diff = get_abs(current->index - target_value);
		if (diff < min_diff)
		{
			min_diff = diff;
			closest = current;
		}
		current = current->next;
	}
	return (closest);
}

int	count_moves_to_top(t_stack *stack, t_stack *node)
{
	int		count;
	t_stack	*current;
	int		stack_size;

	count = 0;
	current = stack;
	stack_size = 0;
	while (current)
	{
		if (current == node)
			count = stack_size;
		stack_size++;
		current = current->next;
	}
	if (count > (stack_size / 2))
		return (-(stack_size - count));
	return (count);
}

int	calculate_cost(int pos, int stack_size)
{
	if (pos <= stack_size / 2)
		return (pos);
	else
		return (-(stack_size - pos));
}

int calculate_total_cost(int cost_a, int cost_b)
{
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
		return get_max(get_abs(cost_a), get_abs(cost_b));
	else
		return get_abs(cost_a) + get_abs(cost_b);
}

int calculate_move_cost(int pos, int stack_size)
{
	if (pos <= stack_size / 2)
			return pos;
	else
			return -(stack_size - pos);
}




int	find_target_position(t_stack *stack_a, int b_index)
{
	t_stack	*current;
	int		target_index;
	int		target_pos;
	int		current_pos;
	int		found;
	int		min_index;

	current = stack_a;
	target_index = 2147483647;
	target_pos = 0;
	current_pos = 0;
	found = 0;
	while (current)
	{
		if (current->index > b_index && current->index < target_index)
		{
			target_index = current->index;
			target_pos = current_pos;
			found = 1;
		}
		current = current->next;
		current_pos++;
	}
	if (!found)
	{
		current = stack_a;
		current_pos = 0;
		min_index = 2147483647;
		while (current)
		{
			if (current->index < min_index)
			{
				min_index = current->index;
				target_pos = current_pos;
			}
			current = current->next;
			current_pos++;
		}
	}
	return (target_pos);
}
