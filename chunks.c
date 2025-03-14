#include "push_swap.h"

int	find_position_in_range(t_stack *stack, int start, int end)
{
	t_stack	*current;
	int		pos;
	int		min_pos;
	int		found;
	
	current = stack;
	pos = 0;
	min_pos = -1;
	found = 0;
	
	while (current)
	{
		if (current->index >= start && current->index <= end)
		{
			if (!found || current->index < stack[min_pos].index)
			{
				min_pos = pos;
				found = 1;
			}
		}
		current = current->next;
		pos++;
	}
	
	return (found ? min_pos : -1);
}

// Mueve un elemento a la parte superior del stack
void	move_to_top(t_stack **stack, int pos, int size, int *movements)
{
	// Si está en la mitad superior, usamos ra
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(stack, movements);
			pos--;
		}
	}
	// Si está en la mitad inferior, usamos rra
	else
	{
		while (pos < size)
		{
			rra(stack, movements);
			pos++;
		}
	}
}

// Encuentra la posición del elemento con el índice más alto
int	find_max_position_chunks(t_stack *stack)
{
	t_stack	*current;
	int		pos;
	int		max_pos;
	int		max_index;
	
	if (!stack)
		return (-1);
		
	current = stack;
	pos = 0;
	max_pos = 0;
	max_index = current->index;
	
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	
	return (max_pos);
}

void	chunks_sort(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b, int *movements)
{
	int	chunk_size;
	int	chunk_count;
	int	i;
	int	pos;
	int	max_pos;
	int	total;
	
	// Tamaño total original
	total = *size_a;
	
	// Determinar número y tamaño de chunks
	if (total <= 100)
		chunk_count = 5;
	else
		chunk_count = 11;
	
	chunk_size = (total + chunk_count - 1) / chunk_count; // Ceil division
	
	// Procesar cada chunk
	for (i = 0; i < chunk_count; i++)
	{
		int start = i * chunk_size;
		int end = (i + 1) * chunk_size - 1;
		
		// Ajustar el último chunk
		if (end >= total)
			end = total - 1;
			
		// Mover todos los elementos del chunk actual a stack_b
		while (1)
		{
			pos = find_position_in_range(*stack_a, start, end);
			if (pos == -1) // No más elementos en este chunk
				break;
				
			move_to_top(stack_a, pos, *size_a, movements);
			pb(stack_a, stack_b, size_a, size_b, movements);
		}
	}
	
	// Devolver elementos ordenados a stack_a
	while (*size_b > 0)
	{
		max_pos = find_max_position_chunks(*stack_b);
		
		// Mover el máximo a la parte superior
		if (max_pos <= *size_b / 2)
		{
			while (max_pos > 0)
			{
				rb(stack_b, movements);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < *size_b)
			{
				rrb(stack_b, movements);
				max_pos++;
			}
		}
		
		// Push a stack_a
		pa(stack_b, stack_a, size_b, size_a, movements);
	}
}