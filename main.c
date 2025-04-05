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
		sort_big(list_a, list_b, size_a, size_b);
}

int	process_arguments(int argc, char **argv, t_stack_info *a_stack_info,
	t_stack **list_b)
{
	int		pos;
	int		num;
	int		err;

	pos = 1;
	err = 0;
	while (pos < argc)
	{
		if (!is_valid_int(argv[pos]))
			err = 1;
		num = ft_atoi(argv[pos]);
		if (is_duplicate(a_stack_info->stack, num))
			err = 1;
		if (!push_node(&(a_stack_info->stack), &(a_stack_info->size),
				ft_atoi(argv[pos])))
			err = 1;
		pos++;
	}
	if (err == 1)
	{
		error_and_free(&(a_stack_info->stack), list_b);
		return (0);
	}
	return (1);
}

int	process_split_args(char **split_args, t_stack_info *a_stack_info)
{
	int		pos;
	int		num;

	pos = 0;
	while (split_args[pos])
	{
		if (!is_valid_int(split_args[pos]))
			return (0);
		num = ft_atoi(split_args[pos]);
		if (is_duplicate(a_stack_info->stack, num))
			return (0);
		if (!push_node(&(a_stack_info->stack), &(a_stack_info->size), num))
			return (0);
		pos++;
	}
	return (1);
}

int	process_one_arg(char *arg, t_stack_info *a_stack_info)
{
	char	**split_args;

	split_args = ft_split(arg, ' ');
	if (!split_args)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!process_split_args(split_args, a_stack_info))
	{
		write(2, "Error\n", 6);
		free_split(split_args);
		free_list(a_stack_info->stack);
		return (0);
	}
	free_split(split_args);
	return (1);
}

int	main(int argc, char **argv)
{
	int				size_b;
	t_stack			*list_b;
	t_stack_info	a_stack_info;

	a_stack_info.stack = NULL;
	a_stack_info.size = 0;
	if (argc < 2)
		return (0);
	list_b = NULL;
	size_b = 0;
	if (argc == 2)
	{
		if (!process_one_arg(argv[1], &a_stack_info))
			return (1);
	}
	else
	{
		if (!process_arguments(argc, argv, &a_stack_info, &list_b))
			return (1);
	}
	if (is_sorted(a_stack_info.stack))
		return (0);
	assign_sort_type(&(a_stack_info.stack), &list_b, &(a_stack_info.size),
		&size_b);
	return (0);
}
