/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:35:56 by isousa-s          #+#    #+#             */
/*   Updated: 2025/04/22 19:35:12 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **list_l)
{
	if (is_sorted(*list_l))
		return ;
	sa(list_l);
}

void	sort_three(t_stack **list_l)
{
	int		a;
	int		b;
	int		c;

	if (is_sorted(*list_l))
		return ;
	a = (*list_l)->content;
	b = (*list_l)->next->content;
	c = (*list_l)->next->next->content;
	if (a < b && b > c && a < c)
	{
		sa(list_l);
		ra(list_l);
	}
	else if (a < b && b > c && c < a)
		rra(list_l);
	else if (a > b && c > a && c > b)
		sa(list_l);
	else if (a > b && c < a && c > b)
		ra(list_l);
	else if (a > b && c < a && c < b)
	{
		sa(list_l);
		rra(list_l);
	}
}

void	sort_four(t_stack **list_a, t_stack **list_b, int *size_a, int *size_b)
{
	int		min;
	int		pos;

	if (is_sorted(*list_a))
		return ;
	min = find_min(*list_a);
	pos = find_position(*list_a, min);
	if (pos == 1)
		ra(list_a);
	else if (pos == 2)
	{
		ra(list_a);
		ra(list_a);
	}
	else if (pos == 3)
		rra(list_a);
	pb(list_a, list_b, size_a, size_b);
	sort_three(list_a);
	pa(list_b, list_a, size_b, size_a);
}

void	sort_five(t_stack **list_a, t_stack **list_b, int *size_b, int *size_a)
{
	int		min;
	int		pos;
	int		pushed;

	pushed = 0;
	if (is_sorted(*list_a))
		return ;
	while (pushed < 2)
	{
		min = find_min(*list_a);
		pos = find_position(*list_a, min);
		while ((*list_a)->content != min)
		{
			if (pos <= 2)
				ra(list_a);
			else
				rra(list_a);
		}
		pb(list_a, list_b, size_a, size_b);
		pushed++;
	}
	sort_three(list_a);
	while (*list_b)
		pa(list_b, list_a, size_b, size_a);
}
