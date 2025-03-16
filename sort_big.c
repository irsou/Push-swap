/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:11:01 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/15 22:11:05 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cheapest_move(t_stack *stack_a, t_stack *stack_b, int size_a,
	int size_b, int *best_a_pos, int *best_b_pos)
{
	t_stack	*current_b;
	int		best_cost;
	int		b_pos;

	current_b = stack_b;
	best_cost = 2147483647;
	b_pos = 0;
	*best_a_pos = 0;
	*best_b_pos = 0;
	while (current_b)
	{
		int	target_pos = find_target_position(stack_a, current_b->index);
		int	cost_a = calculate_cost(target_pos, size_a);
		int	cost_b = calculate_cost(b_pos, size_b);
		int	total_cost;
		if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
			total_cost = get_max(get_abs(cost_a), get_abs(cost_b));
		else
			total_cost = get_abs(cost_a) + get_abs(cost_b);
		if (total_cost < best_cost)
		{
			best_cost = total_cost;
			*best_a_pos = target_pos;
			*best_b_pos = b_pos;
		}
		current_b = current_b->next;
		b_pos++;
	}
}

void	execute_best_moves(t_stack **stack_a, t_stack **stack_b, int best_a_pos,
	int best_b_pos, int size_a, int size_b)
{
	int		cost_a;
	int		cost_b;

	cost_a = calculate_cost(best_a_pos, size_a);
	cost_b = calculate_cost(best_b_pos, size_b);
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack_a, stack_b);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		ra(stack_a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(stack_a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(stack_b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(stack_b);
		cost_b++;
	}
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
	{
		int	best_a_pos, best_b_pos;
		find_cheapest_move(*stack_a, *stack_b, *size_a, *size_b, &best_a_pos,
			&best_b_pos);
		execute_best_moves(stack_a, stack_b, best_a_pos, best_b_pos, *size_a,
			*size_b);
		pa(stack_b, stack_a, size_b, size_a);
	}
	t_stack	*min_node = get_min_index(*stack_a);
	int		min_pos = 0;
	t_stack	*current = *stack_a;
	while (current != min_node)
	{
		min_pos++;
		current = current->next;
	}
	int	min_cost = calculate_cost(min_pos, *size_a);
	while (min_cost != 0)
	{
		if (min_cost > 0)
		{
			ra(stack_a);
			min_cost--;
		}
		else
		{
			rra(stack_a);
			min_cost++;
		}
	}
}
