/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:29:08 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/18 19:45:52 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_best_move_for_b(t_move_cost *move, t_stack_info stack_a_info,
	t_stack_info stack_b_info)
{
	move->cost_a = calculate_cost(move->a_pos, stack_a_info.size);
	move->cost_b = calculate_cost(move->b_pos, stack_b_info.size);
	move->total_cost = calculate_total_cost(move->cost_a, move->cost_b);
}

int	find_closest_larger_index(t_stack *stack_a, int b_index, int *pos)
{
	t_stack	*current;
	int		target_index;
	int		current_pos;
	int		found;

	current = stack_a;
	target_index = 2147483647;
	current_pos = 0;
	found = 0;
	while (current)
	{
		if (current->index > b_index && current->index < target_index)
		{
			target_index = current->index;
			*pos = current_pos;
			found = 1;
		}
		current = current->next;
		current_pos++;
	}
	return (found);
}

int	find_smallest_index(t_stack *stack_a)
{
	t_stack	*current;
	int		target_index;
	int		target_pos;
	int		current_pos;

	current = stack_a;
	target_index = 2147483647;
	target_pos = 0;
	current_pos = 0;
	while (current)
	{
		if (current->index < target_index)
		{
			target_index = current->index;
			target_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (target_pos);
}

int	find_target_position(t_stack *stack_a, int b_index)
{
	int		target_pos;

	if (!find_closest_larger_index(stack_a, b_index, &target_pos))
		target_pos = find_smallest_index(stack_a);
	return (target_pos);
}

void	find_cheapest_move(t_stack_info stack_a_info, t_stack_info stack_b_info,
	int *best_a_pos, int *best_b_pos)
{
	t_stack				*current_b;
	t_move_cost			current_move;
	int					min_cost;
	int					b_pos;

	current_b = stack_b_info.stack;
	min_cost = 2147483647;
	b_pos = 0;
	*best_a_pos = 0;
	*best_b_pos = 0;
	while (current_b)
	{
		current_move.a_pos = find_target_position(stack_a_info.stack,
				current_b->index);
		current_move.b_pos = b_pos;
		get_best_move_for_b(&current_move, stack_a_info, stack_b_info);
		if (current_move.total_cost < min_cost)
		{
			min_cost = current_move.total_cost;
			*best_a_pos = current_move.a_pos;
			*best_b_pos = current_move.b_pos;
		}
		current_b = current_b->next;
		b_pos++;
	}
}
