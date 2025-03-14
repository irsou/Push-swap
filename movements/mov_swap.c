/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:55:25 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/14 19:07:06 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **list_a, int *movements)
{
	swap(list_a);
	(*movements)++;
	write(1, "sa\n", 3);
}

void	sb(t_stack **list_b, int *movements)
{
	swap(list_b);
	(*movements)++;
	write(1, "sb\n", 3);
}

void	ss(t_stack **list_a, t_stack **list_b, int *movements)
{
	swap(list_a);
	swap(list_b);
	(*movements)++;
	write(1, "ss\n", 3);
}

void	swap(t_stack **list_l)
{
	t_stack	*first;
	t_stack	*second;

	if (!list_l || !*list_l || !(*list_l)->next)
		return ;
	first = *list_l;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list_l = second;
}
