/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:46:24 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/14 20:46:24 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*list_a;
	t_stack	*list_b;
	int		size_a;
	int		size_b;
	int		pos;
	int		movements;

	movements = 0;
	if (argc < 2)
		return (0);
	list_a = NULL;
	list_b = NULL;
	size_a = 0;
	size_b = 0;
	pos = 1;
	while (pos < argc)
	{
		if (!is_valid_number(argv[pos]))
		{
			free_list(list_a);
			free_list(list_b);
			//write(1, "Número inválido\n", 17);
			return (1);
		}
		if (!push_node(&list_a, &size_a, ft_atoi(argv[pos])))
		{
			free_list(list_a);
			free_list(list_b);
			//write(1, "Número inválido\n", 17);
			return (1);
		}
		pos++;
	}

	//print_list(list_a);
	if (is_sorted(list_a))
		return (0);

	if (size_a <= 3)
		sort_three(&list_a, &movements);

	else if (size_a <= 5)
		sort_five(&list_a, &list_b, &size_a, &size_b, &movements);

	// else if(size_a <= 100)
	// 	sort_big_list(&list_a, &list_b, &size_a, &size_b, &movements);
	else
		big_sort(&list_a, &list_b, &size_a, &size_b, &movements);

	//write(1,"\n" ,1);
	write(1,"Movimientos: " ,13);
	ft_putnbr(movements);
	write(1,"\n" ,1);
	write(1,"Lista ordenada: " ,16);
	print_list(list_a);
	print_list(list_b);
	write(1,"\n" ,1);
	free_list(list_a);
	free_list(list_b);

	return (0);
}
