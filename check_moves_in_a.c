#include "push_swap.h"
// int calculate_target_position(t_stack *head_b, int index, int size_b);
// void check_double_moves(t_operations *operations);
// void check_cost(t_stack *node);
// void print_stack_a(t_stack *head);
// void get_top_stack_a(t_stack *head, int index, t_stack **out_stack);
// void new_max_or_min_stack_b(t_stack **head_a, t_stack **head_b, t_stack *current_stack);
// void new_num_in_stack_b(t_stack **head_b, int num);
// int ft_listsize_a(t_stack *head);
// int get_stack_size(t_stack *head);
// int calculate_ra_cost(t_stack *node);
// int calculate_rra_cost(t_stack *node, int size_a);
// char	*generate_move_sequence(t_operations *operations);
// void assign_node_index(t_stack *head_a);
// void check_moves(t_stack **head_a, t_stack **head_b);

void append_moves(char **sequence, const char *move, int count) {
	int i = 0;
	char *temp;
	while (i < count) {
		temp = *sequence;
		*sequence = ft_strjoin(*sequence, move);
		free(temp);
		i++;
	}
}

int get_real_position(t_stack *head_a, t_stack *node)
{
	int position = 0;
	t_stack *current = head_a;

	while (current && current != node) {
		position++;
		current = current->next;
	}
	return position;
}

int get_list_size(t_stack *head)
{
	int size = 0;
	t_stack *current = head;

	while (current != NULL) {
		size++;
		current = current->next;
	}
	return size;
}

void include_sa(t_stack *head_a)
{
	if (!head_a || !head_a->next || !head_a->best_moves || !head_a->next->best_moves)
		return;

	if (ft_strncmp(head_a->best_moves, "ra ", 3) == 0 && 
		ft_strncmp(head_a->next->best_moves, "rra ", 4) == 0) {
		
		char *moves1 = head_a->best_moves;
		char *moves2 = head_a->next->best_moves;
		
		head_a->best_moves = ft_strdup("sa ");
		if (ft_strlen(moves1) > 3) {
			char *temp = head_a->best_moves;
			head_a->best_moves = ft_strjoin(temp, moves1 + 3);
			free(temp);
		}
		
		head_a->next->best_moves = ft_strdup("sa ");
		if (ft_strlen(moves2) > 4) {
			char *temp = head_a->next->best_moves;
			head_a->next->best_moves = ft_strjoin(temp, moves2 + 4);
			free(temp);
		}
		
		free(moves1);
		free(moves2);
	}
}

void check_moves_in_a(t_stack *node, t_stack *head_a, int list_size)
{
	int real_position = get_real_position(head_a, node);
	int ideal_position = node->index;
	
	int distance_forward, distance_backward;
	int cost = 0;
	char *sequence_moves = malloc(1 * sizeof(char));
	sequence_moves[0] = '\0';
	
	if (real_position <= ideal_position) {
		distance_forward = ideal_position - real_position;
		distance_backward = list_size - ideal_position + real_position;
	} else {
		distance_forward = list_size - real_position + ideal_position;
		distance_backward = real_position - ideal_position;
	}
	
	if (distance_forward <= distance_backward) {
		cost = distance_forward;
		int i = 0;
		while (i < distance_forward) {
			append_moves(&sequence_moves, "ra ", 1);
			i++;
		}
	} else {
		cost = distance_backward;
		int i = 0;
		while (i < distance_backward) {
			append_moves(&sequence_moves, "rra ", 1);
			i++;
		}
	}
	
	node->cost = cost;
	node->best_moves = sequence_moves;
	
	//printf("Nodo %d: mejores movimientos: %s, costo: %d\n", node->content, sequence_moves, cost);
}

void move_expensive_nodes_to_b(t_stack **head_a, t_stack **head_b, int *movements)
{
	t_stack *current = *head_a;
	t_stack *next = NULL;
	int size_a = get_list_size(*head_a);
	int size_b = get_list_size(*head_b);
	
	while (current != NULL) {
			next = current->next;
			
			if (current->cost > 3) {
					char *moves = current->best_moves;
					char *move_end = moves;
					
					while (*move_end && *move_end != ' ')
							move_end++;
					
					if (*move_end == ' ')
							*move_end = '\0';
							
					int move_count = 0;
					char *temp_moves = moves;
					
					while (move_count < current->cost) {
							if (ft_strncmp(temp_moves, "ra", 2) == 0)
									ra(head_a, movements);
							else if (ft_strncmp(temp_moves, "rra", 3) == 0)
									rra(head_a, movements);
							else if (ft_strncmp(temp_moves, "sa", 2) == 0)
									sa(head_a, movements);
							
							temp_moves += (ft_strlen(temp_moves) + 1);
							move_count++;
							
							if (!*temp_moves)
									break;
					}
					
					if (*move_end)
							*move_end = ' ';
							
						pb(head_a, head_b, &size_a, &size_b, movements);
			}
			
			current = next;
	}
}


// char *generate_move_sequence(t_operations *operations)
// {
//   printf("Generando secuencia: pb=%d, ra=%d, rb=%d, rr=%d, rra=%d, rrb=%d, rrr=%d\n",
// 		operations->pb, operations->ra, operations->rb, operations->rr, operations->rra,
// 		operations->rrb, operations->rrr);

//   char *sequence = ft_strdup("");

// 	append_moves(&sequence, "sa ", operations->sa);
//   append_moves(&sequence, "sb ", operations->sb);
//   append_moves(&sequence, "ss ", operations->ss);
//   append_moves(&sequence, "pa ", operations->pa);
//   append_moves(&sequence, "pb ", operations->pb);
//   append_moves(&sequence, "ra ", operations->ra);
//   append_moves(&sequence, "rb ", operations->rb);
//   append_moves(&sequence, "rr ", operations->rr);
//   append_moves(&sequence, "rra ", operations->rra);
//   append_moves(&sequence, "rrb ", operations->rrb);
//   append_moves(&sequence, "rrr ", operations->rrr);
//   if (sequence[0] == '\0') {
//     free(sequence);
//     sequence = ft_strdup("No moves");
//   }
//   return (sequence);
// }

void print_stack_a(t_stack *head)
{
	//printf("📜 Estado actual de stack_a: ");
	while (head) {
			//printf("%d -> ", head->content);
			head = head->next;
	}
	//printf("NULL\n");
}
// void optimize_first_two_moves(t_stack *node) {
// 	if (node && node->next) {
// 			char *best_moves = node->best_moves;
// 			char *next_best_moves = node->next->best_moves;

// 			if (ft_strncmp(best_moves, "ra ", 3) == 0 && ft_strncmp(next_best_moves, "rra ", 4) == 0) {
// 					// Crear nuevas cadenas para los movimientos restantes
// 					char *remaining_moves_best = ft_strdup(best_moves + 3);
// 					char *remaining_moves_next = ft_strdup(next_best_moves + 4);

// 					// Reemplazar "ra " por "sa " en best_moves
// 					char *new_best_moves = ft_strjoin("sa ", remaining_moves_best);
// 					free(node->best_moves);
// 					node->best_moves = new_best_moves;

// 					// Reemplazar "rra " por "sa " en next_best_moves
// 					char *new_next_best_moves = ft_strjoin("sa ", remaining_moves_next);
// 					free(node->next->best_moves);
// 					node->next->best_moves = new_next_best_moves;

// 					// Liberar memoria de las cadenas temporales
// 					free(remaining_moves_best);
// 					free(remaining_moves_next);
// 			}
// 	}
// }
// void	check_double_moves(t_operations *operations)
// {
// 	operations->rr = 0;
// 	operations->rrr = 0;
// 	while (operations->ra != 0 && operations->rb != 0)
// 	{
// 		operations->ra--;
// 		operations->rb--;
// 		operations->rr++;
// 	}
// 	while (operations->rra != 0 && operations->rrb != 0)
// 	{
// 		operations->rra--;
// 		operations->rrb--;
// 		operations->rrr++;
// 	}
// }

// int	ft_listsize_a(t_stack *head_a)
// {
// 	int size = 0;
// 	t_stack *current = head_a;
// 	while (current)
// 	{
// 		size++;
// 		current = current->next;
// 	}
// 	return (size);
// }

// void new_max_or_min_stack_b(t_stack **head_a, t_stack **head_b, t_stack *current_stack)
// {
// 	printf("🟢 Nuevo max/min encontrado, ajustando operaciones para pb\n");
// 	t_stack *new_node = malloc(sizeof(t_stack));
// 	if (!new_node)
// 		return;

// 	new_node->content = current_stack->content;
// 	new_node->next = NULL;

// 	if (!*head_b)
// 		*head_b = new_node;
// 	else
// 	{
// 		t_stack *current = *head_b;
// 		while (current->next)
// 			current = current->next;
// 		current->next = new_node;
// 	}

// 	*head_a = (*head_a)->next;
// }

// void new_num_in_stack_b(t_stack **head_b, int num)
// {
// 	t_stack *new_node = malloc(sizeof(t_stack));
// 	if (!new_node)
// 		return;

	
// 	new_node->content = num;
// 	new_node->next = NULL;
// 	printf("🔵 Añadiendo número %d a la pila B\n", new_node->content);
// 	if (!*head_b)
// 		*head_b = new_node;
// 	else
// 	{
// 		t_stack *current = *head_b;
// 		while (current->next)
// 			current = current->next;
// 		current->next = new_node;
// 	}
// }

// void get_top_stack_a(t_stack *head, int index, t_stack **out_stack) {
// 	printf("🔍 Buscando nodo en índice %d\n", index);
// 	int i = 0;
// 	*out_stack = head;

// 	while (*out_stack && i < index) {
// 			*out_stack = (*out_stack)->next;
// 			i++;
// 	}

// 	if (*out_stack == NULL) {
// 			printf("⚠️ Error en get_top_stack_a: No se encontró el nodo en índice %d\n", index);
// 	} else {
// 			printf("✅ Nodo obtenido en índice %d: contenido=%d\n", index, (*out_stack)->content);
// 	}
// }


// int get_stack_size(t_stack *head) {
// 	int size = 0;
// 	t_stack *current_stack = head;
// 	while (current_stack != NULL) {
// 			size++;
// 			current_stack = current_stack->next;
// 	}
// 	return size;
// }
// int calculate_target_position(t_stack *head_b, int index, int size_b) {
// 	printf("%dsize_b sobra\n", size_b);
// 	if (!head_b)
// 		return 0;
// 	t_stack *current = head_b;
// 	int position = 0;
// 	int smallest_index = INT_MAX;
// 	int smallest_pos = 0;
// 	int found = 0;
// 	int i = 0;

// 	while (current) {
// 		if (current->index < smallest_index) {
// 				smallest_index = current->index;
// 				smallest_pos = i;
// 		}
// 		if (current->index < index) {
// 				position = i;
// 				found = 1;
// 				break;
// 		}
// 		current = current->next;
// 		i++;
// }
// 	if (!found) {	
// 		position = smallest_pos;
// 	}
// 	return position;
// }

// void check_cost(t_stack *node) {
// 	printf("🔍 Evaluando costos para nodo con índice %d\n", node->index);

// 	node->cost = node->operations.pa + 
// 		node->operations.pb + 
// 		node->operations.sa + 
// 		node->operations.sb +
// 		node->operations.ss +
// 		node->operations.ra + 
// 		node->operations.rb + 
// 		node->operations.rr +
// 		node->operations.rra + 
// 		node->operations.rrb + 
// 		node->operations.rrr;
	
// 	printf("⚡ Costo final: %d\n", node->cost);
// }

// t_stack* find_cheapest_move(t_stack *head_a) {
// 	t_stack *current = head_a;
// 	t_stack *cheapest = NULL;
// 	int min_cost = INT_MAX;
	
// 	while (current) {
// 			if (current->cost < min_cost) {
// 					min_cost = current->cost;
// 					cheapest = current;
// 			}
// 			current = current->next;
// 	}
	
// 	return cheapest;
// }

// void execute_repeated_operation(void (*operation)(t_stack **, int *), t_stack **stack, int *movements, int *count) {
// 	while (*count > 0) {
// 			operation(stack, movements);
// 			(*count)--;
// 	}
// }

// void execute_repeated_operation_two_stacks(void (*operation)(t_stack **, t_stack **, int *), t_stack **stack_a, t_stack **stack_b, int *movements, int *count) {
// 	while (*count > 0) {
// 			operation(stack_a, stack_b, movements);
// 			(*count)--;
// 	}
// }

// void execute_best_move(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b, int *movements) {
// 	t_stack *best_stack = find_cheapest_move(*stack_a);
// 	if (!best_stack) return;

// 	printf("🚀 Executing best move for node %d with cost %d: %s\n", 
// 							 best_stack->content, best_stack->cost, best_stack->best_moves);

// 	execute_repeated_operation(sa, stack_a, movements, &best_stack->operations.sa);
// 	execute_repeated_operation(sb, stack_b, movements, &best_stack->operations.sb);
// 	execute_repeated_operation_two_stacks(ss, stack_a, stack_b, movements, &best_stack->operations.ss);
// 	execute_repeated_operation(ra, stack_a, movements, &best_stack->operations.ra);
// 	execute_repeated_operation(rra, stack_a, movements, &best_stack->operations.rra);
// 	execute_repeated_operation(rb, stack_b, movements, &best_stack->operations.rb);
// 	execute_repeated_operation(rrb, stack_b, movements, &best_stack->operations.rrb);
// 	execute_repeated_operation_two_stacks(rr, stack_a, stack_b, movements, &best_stack->operations.rr);
// 	execute_repeated_operation_two_stacks(rrr, stack_a, stack_b, movements, &best_stack->operations.rrr);

// 	if (best_stack->operations.pb > 0) {
// 			pb(stack_a, stack_b, size_a, size_b, movements);
// 	}

// 	if (best_stack->operations.pa > 0) {
// 			pa(stack_b, stack_a, size_b, size_a, movements);
// 	}
// }




// void check_moves(t_stack **head_a, t_stack **head_b) {
// 	t_stack *current = *head_a;
// 	int size_a = get_stack_size(*head_a);
// 	int size_b = get_stack_size(*head_b);
	
// 	while (current != NULL) {
// 		ft_memset(&current->operations, 0, sizeof(t_operations));
			
// 			current->operations.pb = 1;
			
// 			if (current->index <= size_a / 2) {
// 					current->operations.ra = current->index;
// 			} else {
// 					current->operations.rra = size_a - current->index;
// 			}
			
// 			if (size_b > 0) {
// 					int b_pos = calculate_target_position(*head_b, current->index, size_b);
					
// 					if (b_pos <= size_b / 2) {
// 							current->operations.rb = b_pos;
// 					} else {
// 							current->operations.rrb = size_b - b_pos;
// 					}
// 			}
// 			current->operations.pa = 1;
// 			check_double_moves(&current->operations);
			
// 			check_cost(current);
			
// 			if (current->best_moves) {
// 					free(current->best_moves);
// 			}
// 			current->best_moves = generate_move_sequence(&current->operations);
			
// 			current = current->next;
// 	}
// }