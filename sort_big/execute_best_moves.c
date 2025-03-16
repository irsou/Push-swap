/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_best_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:20:29 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/16 16:20:29 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute_both_rotations(t_stack **stack_a, t_stack **stack_b,
	int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	execute_a_rotations(t_stack **stack_a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(stack_a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(stack_a);
		(*cost_a)++;
	}
}

void	execute_b_rotations(t_stack **stack_b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(stack_b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(stack_b);
		(*cost_b)++;
	}
}

void	execute_best_moves(t_stack **stack_a, t_stack **stack_b,
	t_move_cost move_info)
{
	int		cost_a;
	int		cost_b;

	cost_a = calculate_cost(move_info.a_pos, move_info.cost_a);
	cost_b = calculate_cost(move_info.b_pos, move_info.cost_b);
	execute_both_rotations(stack_a, stack_b, &cost_a, &cost_b);
	execute_a_rotations(stack_a, &cost_a);
	execute_b_rotations(stack_b, &cost_b);
}
