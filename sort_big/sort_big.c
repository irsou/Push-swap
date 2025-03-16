/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:11:01 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/16 16:08:33 by isousa-s         ###   ########.fr       */
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

void	initialize_move_search(t_move_cost *best_move, int *b_pos,
	int *best_a_pos, int *best_b_pos)
{
	best_move->total_cost = 2147483647;
	*b_pos = 0;
	*best_a_pos = 0;
	*best_b_pos = 0;
}

void	find_cheapest_move(t_stack_info stack_a_info, t_stack_info stack_b_info,
	int *best_a_pos, int *best_b_pos)
{
	t_stack				*current_b;
	t_move_cost			current_move;
	t_move_cost			best_move;
	int					b_pos;

	current_b = stack_b_info.stack;
	initialize_move_search(&best_move, &b_pos, best_a_pos, best_b_pos);
	while (current_b)
	{
		current_move.a_pos = find_target_position(stack_a_info.stack,
				current_b->index);
		current_move.b_pos = b_pos;
		get_best_move_for_b(&current_move, stack_a_info, stack_b_info);
		if (current_move.total_cost < best_move.total_cost)
		{
			best_move = current_move;
			*best_a_pos = current_move.a_pos;
			*best_b_pos = current_move.b_pos;
		}
		current_b = current_b->next;
		b_pos++;
	}
}

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

void	big_sort(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b)
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
