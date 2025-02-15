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

# include "push_swap.h"

static int	is_valid_number(char *str)
{
	int		pos;

	pos = 0;
	if(str[pos] == '-' || str[pos] == '+')
		pos++;
	if(!str[pos])
		return (0);
	while(str[pos])
	{
		if(str[pos] < '0' || str[pos] > '9')
			return (0);
		pos++;
	}
	return (1);
}

static int	ft_atoi(const char *str)
{
	int		res;
	int		sign;
	int		pos;

	res = 0;
	sign = 1;
	pos = 0;
	if (str[pos]== '-')
	{
		sign = -1;
		pos++;
	}
	else if (str[pos]== '+')
		pos++;
	while(str[pos] >= '0' && str[pos]<= '9')
	{
		res = (res * 10) + (str[pos] - '0');
		pos++;
	}
	return (res * sign);
}

t_stack	*initialize_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if(!stack)
		return (NULL);
	stack ->top = NULL;
	stack ->size = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	if(!node)
		return (NULL);
	node->content = value;
	node->next = NULL;
	return (node);
}

int	push_node(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = create_node(value);
	if(!new_node)
		return (0);
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if(!stack)
		return;
	current = stack->top;
	while(current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int			pos;

	if(argc < 2)
		return (0);
	stack_a = initialize_stack();
	stack_b = initialize_stack();
	if (!stack_a || !stack_b)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		write(1, "Error al inicializar\n", 22);
		return (1);
	}
	while(pos < argc)
	{
		if(!is_valid_number(argv[pos]))
		{
			free_stack(stack_a);
			free_stack(stack_b);
			write(1, "Número inválido\n", 17);
		}
		if(!push_node(stack_a, ft_atoi(argv[pos])))
		{
			free_stack(stack_a);
			free_stack(stack_b);
			write(1, "Número inválido\n", 17);
		}
		pos++;
	}
	write(1, "Números guardados falta ordenarlos\n", 36);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}