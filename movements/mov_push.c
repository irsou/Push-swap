/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:55:15 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/15 20:34:37 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **list_b, t_stack **list_a, int *size_b,
	int *size_a)
{
	push_to(list_b, list_a, size_b, size_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **list_a, t_stack **list_b, int *size_a,
	int *size_b)
{
	push_to(list_a, list_b, size_a, size_b);
	write(1, "pb\n", 3);
}

void	push_to(t_stack **list_src, t_stack **list_dest, int *size_src,
	int *size_dest)
{
	t_stack	*temp;

	if (!list_src || !(*list_src))
		return ;
	temp = *list_src;
	*list_src = (*list_src)->next;
	temp->next = *list_dest;
	*list_dest = temp;
	(*size_src)--;
	(*size_dest)++;
}
