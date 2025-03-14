#include "push_swap.h"

void check_moves(t_stack **head_a, t_stack **head_b, int *movements)
{
	t_stack *current = *head_a;
	int list_size = get_list_size(*head_a);
	
	while (current != NULL) {
		check_moves_in_a(current, *head_a, list_size);
		current = current->next;
	}
	
	include_sa(*head_a);
	
	//printf("\nMovimientos optimizados:\n");
	current = *head_a;
	while (current != NULL) {
		current = current->next;
	}

	move_expensive_nodes_to_b(head_a, head_b, movements);
	
	//printf("Tamaño de stack B: %d\n", get_list_size(*head_b));
}