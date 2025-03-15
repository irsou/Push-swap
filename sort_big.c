 #include "push_swap.h"

int get_max(int a, int b) {
return (a > b) ? a : b;
}

int get_abs(int x) {
return (x < 0) ? -x : x;
}

t_stack *get_min_index(t_stack *stack)
{
	t_stack *min_node;
	t_stack *current;

	min_node = NULL;
	current = stack;
	if (!stack)
		return NULL;
	min_node = stack;
	while (current)
	{
		if (current->index < min_node->index)
		min_node = current;
		current = current->next;
	}
	return min_node;
}

t_stack *get_closest_to_target(t_stack *stack_b, int target_value)
{
	t_stack *closest;
	t_stack *current;
	int min_diff;
	int diff;

	min_diff = 2147483647;
	closest = NULL;
	current = stack_b;
	while (current) {
		diff = get_abs(current->index - target_value);
		if (diff < min_diff)
		{
			min_diff = diff;
			closest = current;
		}
		current = current->next;
	}
	return closest;
}

int count_moves_to_top(t_stack *stack, t_stack *node)
{
	int count;
	t_stack *current;
	int stack_size;

	count = 0;
	current = stack;
	stack_size = 0;
	while (current)
	{
		if (current == node)
			count = stack_size;
		stack_size++;
		current = current->next;
	}
	if (count > (stack_size / 2))
		return -(stack_size - count);
	return count;
}

int calculate_moves(t_stack *stack_a,  t_stack *stack_b, t_stack *current_a,
	int *a_moves, int *b_moves)
{
	t_stack *target_b;

	target_b = get_closest_to_target(stack_b, current_a->index);
	*a_moves = count_moves_to_top(stack_a, current_a);
	*b_moves = count_moves_to_top(stack_b, target_b);
	if ((*a_moves >= 0 && *b_moves >= 0) || (*a_moves <= 0 && *b_moves <= 0))
		return get_max(get_abs(*a_moves), get_abs(*b_moves));
	return get_abs(*a_moves) + get_abs(*b_moves);
}

void find_best_moves(t_stack *stack_a, t_stack *stack_b, int *moves_a, int *moves_b)
{
	t_stack *current_a;
	int best_total;
	int a_moves;
	int b_moves;
	int total_moves;

	current_a = stack_a;
	best_total = 2147483647;
	*moves_a = 0;
	*moves_b = 0;
	while (current_a)
	{
		total_moves = calculate_moves(stack_a, stack_b, current_a, &a_moves, &b_moves);
		if (total_moves < best_total)
		{
			best_total = total_moves;
			*moves_a = a_moves;
			*moves_b = b_moves;
		}
		current_a = current_a->next;
	}
}

int find_target_position(t_stack *stack_a, int b_index)
{
	t_stack *current = stack_a;
	int target_index = 2147483647;
	int target_pos = 0;
	int current_pos = 0;
	int found = 0;

	while (current)
	{
		if (current->index > b_index && current->index < target_index)
		{
			target_index = current->index;
			target_pos = current_pos;
			found = 1;
		}
		current = current->next;
		current_pos++;
	}
	if (!found)
	{
		current = stack_a;
		current_pos = 0;
		int min_index = 2147483647;
		while (current)
		{
			if (current->index < min_index)
			{
				min_index = current->index;
				target_pos = current_pos;
			}
			current = current->next;
			current_pos++;
		}
	}
	return target_pos;
}

int calculate_cost(int pos, int stack_size)
{
	if (pos <= stack_size / 2)
		return pos;
	else
		return -(stack_size - pos);
}

void find_cheapest_move(t_stack *stack_a, t_stack *stack_b, int size_a, int size_b, int *best_a_pos, int *best_b_pos)
{
	t_stack *current_b = stack_b;
	int best_cost = 2147483647;
	int b_pos = 0;

	*best_a_pos = 0;
	*best_b_pos = 0;
	while (current_b)
	{
		int target_pos = find_target_position(stack_a, current_b->index);
		int cost_a = calculate_cost(target_pos, size_a);
		int cost_b = calculate_cost(b_pos, size_b);
		int total_cost;
		if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
		total_cost = get_max(get_abs(cost_a), get_abs(cost_b));
		else
		total_cost = get_abs(cost_a) + get_abs(cost_b);
		if (total_cost < best_cost)
		{
			best_cost = total_cost;
			*best_a_pos = target_pos;
			*best_b_pos = b_pos;
		}
		current_b = current_b->next;
		b_pos++;
	}
}

void execute_best_moves(t_stack **stack_a, t_stack **stack_b, int best_a_pos, int best_b_pos, int size_a, int size_b)
{
	int cost_a = calculate_cost(best_a_pos, size_a);
	int cost_b = calculate_cost(best_b_pos, size_b);

	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack_a, stack_b);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		ra(stack_a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(stack_a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(stack_b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(stack_b);
		cost_b++;
	}
}

void big_sort(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b)
{
	if (is_sorted(*stack_a))
		return;
	assign_node_index(*stack_a);
	while (*size_a > 3)
		pb(stack_a, stack_b, size_a, size_b);
	sort_three(stack_a);
	while (*size_b > 0)
	{
		int best_a_pos, best_b_pos;
		find_cheapest_move(*stack_a, *stack_b, *size_a, *size_b, &best_a_pos, &best_b_pos);
		execute_best_moves(stack_a, stack_b, best_a_pos, best_b_pos, *size_a, *size_b);
		pa(stack_b, stack_a, size_b, size_a);
	}
	t_stack *min_node = get_min_index(*stack_a);
	int min_pos = 0;
	t_stack *current = *stack_a;
	while (current != min_node)
	{
		min_pos++;
		current = current->next;
	}
	int min_cost = calculate_cost(min_pos, *size_a);
	while (min_cost != 0)
	{
		if (min_cost > 0)
		{
			ra(stack_a);
			min_cost--;
		}
		else
		{
			rra(stack_a);
			min_cost++;
		}
	}
}
