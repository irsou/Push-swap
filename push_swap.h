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
# include <limits.h>
# include <stdbool.h>

typedef struct s_operations
{
	int pa;
	int sa;
	int sb;
	int ss;
	int pb;
  int ra;
  int rb;
  int rr;
  int rra;
  int rrb;
  int rrr;
	int max_b;
	int min_b;
} t_operations;

typedef struct s_node
{
	int							content;
	int							index;
	int							cost;
	char						*best_moves;
	struct s_node				*next;
	t_operations    operations;
}	t_stack;



int	ft_strncmp(const char *str, const char *str2, size_t n);
int			is_valid_number(char *str);
char		*ft_strdup(const char *s);
size_t ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *ptr, int value, size_t length);
int			ft_atoi(const char *str);
t_stack	*create_node(int value);
int			push_node(t_stack **first, int *size, int value);
void		free_list(t_stack *first);
void		print_list(t_stack *first); //borrar
void		ft_putnbr(int n); //borrar
int			is_sorted(t_stack *list);
int			find_min(t_stack *list);
int			find_max(t_stack *list);
t_stack	*find_max_node(t_stack *list);
t_stack	*find_min_node(t_stack *list);
int			find_position(t_stack *list, int value);
void		assign_node_index(t_stack *stack);
void		sa(t_stack **list_a, int *movements);
void		sb(t_stack **list_b, int *movements);
void		ss(t_stack **list_a, t_stack **list_b, int *movements);
void		pa(t_stack **list_b, t_stack **list_a, int *size_b,
				int *size_a, int *movements);
void		pb(t_stack **list_a, t_stack **list_b, int *size_a,
				int *size_b, int *movements);
void		ra(t_stack **list_a, int *movements);
void		rb(t_stack **list_b, int *movements);
void		rr(t_stack **list_a, t_stack **list_b, int *movements);
void		rra(t_stack **list_a, int *movements);
void		rrb(t_stack **list_b, int *movements);
void		rrr(t_stack **list_a, t_stack **list_b, int *movements);
void		sort_three(t_stack **list_l, int *movements);
void		sort_five(t_stack **list_a, t_stack **list_b, int *size_b,
				int *size_a, int *movements);
// void		chunks_sort(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b, int *movements);
// void	hybrid_sort(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b, int *movements);
void		big_sort(t_stack **list_a, t_stack **list_b, int *size_a, int *size_b, int *movements);
// void optimized_sort(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b, int *movements);
void		push_to(t_stack **list_src, t_stack **list_dest, int *size_src,
				int *size_dest);
void		reverse_rotate_list(t_stack **list_l);
void		rotate_list(t_stack **list_l);
void print_stack_a(t_stack *head);
void		swap(t_stack **list_l);
//void check_moves(t_stack **head_a);
void check_moves(t_stack **head_a, t_stack **head_b, int *movements);
int get_list_size(t_stack *head);
void check_moves_in_a(t_stack *node, t_stack *head_a, int list_size);
void include_sa(t_stack *head_a);
void sort_back_to_a(t_stack **head_a, t_stack **head_b, int *size_a, int *size_b, int *movements);
int find_position_in_b(t_stack *head_b, int value);
void move_expensive_nodes_to_b(t_stack **head_a, t_stack **head_b, int *movements);
void push_and_sort(t_stack **list_a, t_stack **list_b, int *size_a, int *size_b, int *movements);
int get_real_position(t_stack *head_a, t_stack *node);
void evaluate_ra_rra(t_stack **list_a, int current_value, int *movements);
int	find_min_index(t_stack *list);

#endif