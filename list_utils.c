/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:23:38 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/01 17:00:11 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *list)
{
	while (list && list->next)
	{
		if ((list->content) > (list->next->content))
			return (0);
		list = list->next;
	}
	return (1);
}

int	find_min(t_node *list)
{
	int		min;

	if (!list)
		return (0);
	min = list->content;
	while (list)
	{
		if (list->content < min)
			min = list->content;
		list = list->next;
	}
	return (min);
}

/*int	find_min_max(t_node *list, int *min, int *max)
{
	int		min_num;

	if (!list)
		return (0);
		min_num = list->content;
	while (list)
	{
		if (list->content < min_num)
		min_num = list->content;
		list = list->next;
	}
	return (min_num);
}*/


int	find_position(t_node *list, int value)
{
	int		pos;

	pos = 0;
	while (list)
	{
		if (list->content == value)
			return (pos);
		pos++;
		list = list->next;
	}
	return (-1);
}

void	sort_three(t_node **list_l, int *movements)
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
		sa(list_l, movements);
		ra(list_l, movements);
	}
	else if (a < b && b > c && c < a)
		rra(list_l, movements);
	else if (a > b && c > a && c > b)
		sa(list_l, movements);
	else if (a > b && c < a && c > b)
		ra(list_l, movements);
	else if (a > b && c < a && c < b)
	{
		sa(list_l, movements);
		rra(list_l, movements);
	}
	return ;
}

void	sort_five(t_node **list_a, t_node **list_b, int *size_b, int *size_a, int *movements)
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
				ra(list_a, movements);
			else
				rra(list_a, movements);
		}
		pb(list_a, list_b, size_a, size_b, movements);
		pushed++;
	}
	sort_three(list_a, movements);
	while (pushed > 0)
	{
		pa(list_b, list_a, size_b, size_a, movements);
		pushed--;
	}
	return ;
}
