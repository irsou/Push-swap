/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:55:22 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/15 20:33:42 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **list_a)
{
	rotate_list(list_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **list_b)
{
	rotate_list(list_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **list_a, t_stack **list_b)
{
	rotate_list(list_a);
	rotate_list(list_b);
	write(1, "rr\n", 3);
}

void	rotate_list(t_stack **list_l)
{
	t_stack	*first;
	t_stack	*last;

	if (!list_l || !(*list_l) || !(*list_l)->next)
		return ;
	first = *list_l;
	last = *list_l;
	while (last->next)
		last = last->next;
	*list_l = first->next;
	first->next = NULL;
	last->next = first;
}
