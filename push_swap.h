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

typedef struct s_stack_info
{
	t_stack	*stack;
	int		size;
}	t_stack_info;

typedef struct s_move_cost
{
	int		cost_a;
	int		cost_b;
	int		total_cost;
	int		a_pos;
	int		b_pos;
}	t_move_cost;

int			is_valid_int(const char *str);
int			get_max(int a, int b);
int			get_abs(int x);
t_stack		*get_min_index(t_stack *stack);
int			calculate_cost(int pos, int stack_size);
int			calculate_total_cost(int cost_a, int cost_b);
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
void		rotate_to_min(t_stack **stack_a, int size_a);
void		execute_best_moves(t_stack **stack_a, t_stack **stack_b,
				t_move_cost move_info);
void		execute_a_rotations(t_stack **stack_a, int *cost_a);
void		find_cheapest_move(t_stack_info stack_a_info,
				t_stack_info stack_b_info, int *best_a_pos, int *best_b_pos);

#endif