/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:36:20 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/14 23:36:20 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SAWP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
	int						content;
	struct s_node	*next;
} t_node;

typedef struct s_list_stack
{
	t_node	*top;
	int			size;
} t_stack;

static int	is_valid_number(char *str);
static int	ft_atoi(const char *str);
t_stack	*initialize_stack(void);
t_node	*create_node(int value);
int	push_node(t_stack *stack, int value);
void	free_stack(t_stack *stack);

#endif