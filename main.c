/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   push_swap.c:+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: isousa-s <isousa-s@student.42urduliz.co+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2025/02/14 20:46:24 by isousa-s  #+##+# */
/*   Updated: 2025/02/14 20:46:24 by isousa-s ###   ########.fr   */
/**/
/* ************************************************************************** */

#include "push_swap.h"

void	assign_sort_type(t_stack **list_a, t_stack **list_b, int *size_a,
	int *size_b)
{
	assign_node_index(*list_a);
	if (*size_a <= 3)
		sort_three(list_a);
	else if (*size_a <= 5)
		sort_five(list_a, list_b, size_a, size_b);
	else
		big_sort(list_a, list_b, size_a, size_b);
}

int	process_arguments(int argc, char **argv, t_stack **list_a, int *size_a)
{
	int		pos;

	pos = 1;
	while (pos < argc)
	{
		if (!is_valid_number(argv[pos]))
			return (0);
		if (!push_node(list_a, size_a, ft_atoi(argv[pos])))
			return (0);
		pos++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*list_a;
	t_stack	*list_b;
	int		size_a;
	int		size_b;

	if (argc < 2)
		return (0);
	list_a = NULL;
	list_b = NULL;
	size_a = 0;
	size_b = 0;
	if (!process_arguments(argc, argv, &list_a, &size_a))
	{
		free_list(list_a);
		free_list(list_b);
		return (1);
	}
	if (is_sorted(list_a))
		return (0);
	assign_sort_type(&list_a, &list_b, &size_a, &size_b);
	return (0);
}
