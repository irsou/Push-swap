/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:55:22 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/01 09:47:47 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **list_a, int *movements)
{
	rotate_list(list_a);
	(*movements)++;
	write(1, "ra\n", 3);
}

void	rb(t_node **list_b, int *movements)
{
	rotate_list(list_b);
	(*movements)++;
	write(1, "rb\n", 3);
}

void	rr(t_node **list_a, t_node **list_b, int *movements)
{
	rotate_list(list_a);
	rotate_list(list_b);
	(*movements)++;
	write(1, "rr\n", 3);
}

void	rotate_list(t_node **list_l)
{
	t_node	*first;
	t_node	*last;

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
