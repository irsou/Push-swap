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
# include <unistd.h> //write
# include <stdlib.h> //malloc & free

typedef struct s_node
{
	int							content;
	int							index;
	struct s_node				*next;
}	t_stack;

int			is_valid_number(char *str);
int			get_max(int a, int b);
int			get_abs(int x);
t_stack		*get_min_index(t_stack *stack);
t_stack		*get_closest_to_target(t_stack *stack_b, int target_value);
int			count_moves_to_top(t_stack *stack, t_stack *node);
int			calculate_cost(int pos, int stack_size);
int			find_target_position(t_stack *stack_a, int b_index);
int			ft_atoi(const char *str);
t_stack		*create_node(int value);
int			push_node(t_stack **first, int *size, int value);
void		free_list(t_stack *first);
void		print_list(t_stack *first);
void		ft_putnbr(int n);
int			is_sorted(t_stack *list);
int			find_min(t_stack *list);
int			find_position(t_stack *list, int value);
void		assign_node_index(t_stack *stack);
void		sa(t_stack **list_a);
void		sb(t_stack **list_b);
void		ss(t_stack **list_a, t_stack **list_b);
void		pa(t_stack **list_b, t_stack **list_a, int *size_b,
				int *size_a);
void		pb(t_stack **list_a, t_stack **list_b, int *size_a,
				int *size_b);
void		ra(t_stack **list_a);
void		rb(t_stack **list_b);
void		rr(t_stack **list_a, t_stack **list_b);
void		rra(t_stack **list_a);
void		rrb(t_stack **list_b);
void		rrr(t_stack **list_a, t_stack **list_b);
void		sort_three(t_stack **list_l);
void		sort_five(t_stack **list_a, t_stack **list_b, int *size_b,
				int *size_a);
void		big_sort(t_stack **list_a, t_stack **list_b, int *size_a,
				int *size_b);
void		push_to(t_stack **list_src, t_stack **list_dest, int *size_src,
				int *size_dest);
void		reverse_rotate_list(t_stack **list_l);
void		rotate_list(t_stack **list_l);
void		swap(t_stack **list_l);
int			get_real_position(t_stack *head_a, t_stack *node);

#endif