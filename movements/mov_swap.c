/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:55:25 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/15 16:55:25 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sa(t_node **list_a)
{
	swap(list_a);
}

void	sb(t_node **list_b)
{
	swap(list_b);
}

void	ss(t_node **list_a, t_node **list_b)
{
	swap(list_a);
	swap(list_b);
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
