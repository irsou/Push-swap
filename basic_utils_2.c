/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:52:04 by isousa-s          #+#    #+#             */
/*   Updated: 2025/04/05 11:57:38 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t length)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (length--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	is_duplicate(t_stack *list, int num)
{
	while (list)
	{
		if (list->content == num)
			return (1);
		list = list->next;
	}
	return (0);
}

void	error_and_free(t_stack **list_a, t_stack **list_b)
{
	write(2, "Error\n", 6);
	free_list(*list_a);
	free_list(*list_b);
}
