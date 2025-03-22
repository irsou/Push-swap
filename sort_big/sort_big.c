/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:11:01 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/22 09:02:41 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_and_execute_best_move(t_stack **stack_a, t_stack **stack_b,
	int *size_a, int *size_b)
{
	int						best_a_pos;
	int						best_b_pos;
	t_move_cost				move_info;
	t_stack_info			stack_a_info;
	t_stack_info			stack_b_info;

	stack_a_info.stack = *stack_a;
	stack_a_info.size = *size_a;
	stack_b_info.stack = *stack_b;
	stack_b_info.size = *size_b;
	find_cheapest_move(stack_a_info, stack_b_info, &best_a_pos, &best_b_pos);
	move_info.a_pos = best_a_pos;
	move_info.b_pos = best_b_pos;
	move_info.cost_a = *size_a;
	move_info.cost_b = *size_b;
	execute_best_moves(stack_a, stack_b, move_info);
	pa(stack_b, stack_a, size_b, size_a);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b)
{
	if (is_sorted(*stack_a))
		return ;
	assign_node_index(*stack_a);
	while (*size_a > 3)
		pb(stack_a, stack_b, size_a, size_b);
	sort_three(stack_a);
	while (*size_b > 0)
		find_and_execute_best_move(stack_a, stack_b, size_a, size_b);
	rotate_to_min(stack_a, *size_a);
}
