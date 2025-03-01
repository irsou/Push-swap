/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:55:25 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/01 09:47:35 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **list_a, int *movements)
{
	swap(list_a);
	(*movements)++;
	write(1, "sa\n", 3);
}

void	sb(t_node **list_b, int *movements)
{
	swap(list_b);
	(*movements)++;
	write(1, "sb\n", 3);
}

void	ss(t_node **list_a, t_node **list_b, int *movements)
{
	swap(list_a);
	swap(list_b);
	(*movements)++;
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
