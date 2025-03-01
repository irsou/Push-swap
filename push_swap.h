/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:36:12 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/15 18:36:12 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int							content;
	struct s_node				*next;
}	t_node;

int			is_valid_number(char *str);
int			ft_atoi(const char *str);
t_node		*create_node(int value);
int			push_node(t_node **first, int *size, int value);
void		free_list(t_node *first);
void		print_list(t_node *first); //borrar
void		ft_putnbr(int n); //borrar
int			is_sorted(t_node *list);
int			find_min(t_node *list);
int			find_position(t_node *list, int value);
void		sa(t_node **list_a, int *movements);
void		sb(t_node **list_b, int *movements);
void		ss(t_node **list_a, t_node **list_b, int *movements);
void		pa(t_node **list_b, t_node **list_a, int *size_b,
				int *size_a, int *movements);
void		pb(t_node **list_a, t_node **list_b, int *size_a,
				int *size_b, int *movements);
void		ra(t_node **list_a, int *movements);
void		rb(t_node **list_b, int *movements);
void		rr(t_node **list_a, t_node **list_b, int *movements);
void		rra(t_node **list_a, int *movements);
void		rrb(t_node **list_b, int *movements);
void		rrr(t_node **list_a, t_node **list_b, int *movements);
void		sort_three(t_node **list_l, int *movements);
void		sort_five(t_node **list_a, t_node **list_b, int *size_b,
				int *size_a, int *movements);
void		push_to(t_node **list_src, t_node **list_dest, int *size_src,
				int *size_dest);
void		reverse_rotate_list(t_node **list_l);
void		rotate_list(t_node **list_l);
void		swap(t_node **list_l);

#endif