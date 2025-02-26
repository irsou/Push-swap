/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:55:25 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/17 19:22:00 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **list_a)
{
	swap(list_a);
	write(1, "sa\n", 3);
}

void	sb(t_node **list_b)
{
	swap(list_b);
	write(1, "sb\n", 3);
}

void	ss(t_node **list_a, t_node **list_b)
{
	swap(list_a);
	swap(list_b);
	write(1, "ss\n", 3);
}

void	swap(t_node **list_l)
{
	t_node	*first;
	t_node	*second;

	if (!list_l || !*list_l || !(*list_l)->next)
		return ;
	first = *list_l;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list_l = second;
}
