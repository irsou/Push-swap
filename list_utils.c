/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:23:38 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/16 11:23:38 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// void *sort_three(t_node **list_l){

// 	int		a;
// 	int		b;
// 	int		c;

// 	if (is_sorted(*list_l))
// 		return ;
// 	a = (*list_l)->content;
// 	b = (*list_l)->next->content;
// 	c = (*list_l)->next->next->content;
// 	if (a < b)
// 	{
// 		if (c < b && c >a)
// 		{
// 			ra(list_l);
// 			sa(list_l);
// 			rra(list_l);
// 		}
// 		if (c < a)
// 			rra(list_l);
// 	}
// 	else
// 	{
// 		sa(list_l);
// 		sort_three(list_l);
// 	}

// return ;
// }

void	*sort_three(t_node **list_l)
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
	return ;
}
