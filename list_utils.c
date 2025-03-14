/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:23:38 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/10 20:06:22 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *list)
{
	while (list && list->next)
	{
		if ((list->content) > (list->next->content))
			return (0);
		list = list->next;
	}
	return (1);
}

int	find_min(t_stack *list)
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

int	find_max(t_stack *list)
{
	int		max;

	if (!list)
		return (0);
	max = list->content;
	while (list)
	{
		if (list->content > max)
			max = list->content;
		list = list->next;
	}
	return (max);
}

t_stack	*find_min_node(t_stack *list)
{
	t_stack	*min_node;

	if (!list)
		return (NULL);
	min_node = list;
	while (list)
	{
		if ((list->content) < (min_node->content))
			min_node = list;
		list = list->next;
	}
	return (min_node);
}

t_stack	*find_max_node(t_stack *list)
{
	t_stack	*max_node;

	if (!list)
		return (NULL);
	max_node = list;
	while (list)
	{
		if ((list->content) > (max_node->content))
			max_node = list;
		list = list->next;
	}
	return (max_node);
}


/*int	find_min_max(t_stack *list, int *min, int *max)
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


int	find_position(t_stack *list, int value)
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

