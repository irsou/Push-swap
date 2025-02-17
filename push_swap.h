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
# define PUSH_SAWP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int							content;
	struct s_node			*next;
}	t_node;

int			is_valid_number(char *str);
int			ft_atoi(const char *str);
t_node		*create_node(int value);
int			push_node(t_node **first, int *size, int value);
void		free_list(t_node *first);
void		print_list(t_node *first); //borrar
void		ft_putnbr(int n); //borrar
void		sa(t_node **list_a);
int			is_sorted(t_node *list);
int			find_min(t_node *list);
int			find_position(t_node *list, int value);
void		sa(t_node **list_a);
void		sb(t_node **list_b);
void		ss(t_node **list_a, t_node **list_b);
void		pa(t_node **list_b, t_node **list_a, int *size_b,
				int *size_a);
void		pb(t_node **list_a, t_node **list_b, int *size_a,
				int *size_b);
void		ra(t_node **list_a);
void		rb(t_node **list_b);
void		rr(t_node **list_a, t_node **list_b);
void		rra(t_node **list_a);
void		rrb(t_node **list_b);
void		rrr(t_node **list_a, t_node **list_b);
void		*sort_five(t_node **list_a, t_node **list_b,int *size_b, int *size_a);

#endif