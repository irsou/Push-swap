/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:55:12 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/14 19:06:44 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **list_a, int *movements)
{
	reverse_rotate_list(list_a);
	(*movements)++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **list_b, int *movements)
{
	reverse_rotate_list(list_b);
	(*movements)++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **list_a, t_stack **list_b, int *movements)
{
	reverse_rotate_list(list_a);
	reverse_rotate_list(list_b);
	(*movements)++;
	write(1, "rrr\n", 4);
}

void	reverse_rotate_list(t_stack **list_l)
{
	t_stack	*prev;
	t_stack	*last;

	if (!list_l || !(*list_l) || !(*list_l)->next)
		return ;
	prev = NULL;
	last = *list_l;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *list_l;
	*list_l = last;
}
