/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:37:30 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/15 18:37:30 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	print_list(t_stack *first)
{
	t_stack	*current;

	current = first;
	write(1, "Números: ", 9);
	while (current)
	{
		ft_putnbr(current->content);
		write(1, " ", 1);
		current = current->next;
	}
	write(1, "\n", 1);

	// current = first;
	// write(1, "Índices: ", 9);
	// while (current)
	// {
	// 	ft_putnbr(current->index);
	// 	write(1, " ", 1);
	// 	current = current->next;
	// }
	// write(1, "\n", 1);

	// current = first;
	// write(1, "Costos: ", 8);
	// while (current)
	// {
	// 	ft_putnbr(current->cost);
	// 	write(1, " ", 1);
	// 	current = current->next;
	// }
	// write(1, "\n", 1);

	// current = first;
	// write(1, "Mejores movimientos:\n", 21);
	// while (current)
	// {
	// 	if (current->best_moves)
	// 		write(1, current->best_moves, ft_strlen(current->best_moves));
	// 	else
	// 		write(1, "(sin movimientos)", 17);
	// 	write(1, "\n", 1);
	// 	current = current->next;
	// }
}
