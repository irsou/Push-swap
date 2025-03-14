#include "push_swap.h"

int find_position_in_b(t_stack *head_b, int value)
{
	if (!head_b)
			return 0;
			
	t_stack *current = head_b;
	int position = 0;
	int best_position = 0;
	int min_diff = INT_MAX;
	//int list_size = get_list_size(head_b);
	
	while (current) {
			int diff = current->content - value;
			if (diff < 0)
					diff = -diff;
					
			if (diff < min_diff) {
					min_diff = diff;
					best_position = position;
			}
			position++;
			current = current->next;
	}
	return best_position;
}

void move_to_position_in_b(t_stack **head_b, int position, int *movements) {
	int list_size = get_list_size(*head_b);
	
	if (position <= list_size / 2) {
			int i = 0;
			while (i < position) {
					rb(head_b, movements);
					i++;
			}
	} else {
			int i = 0;
			int moves_needed = list_size - position;
			while (i < moves_needed) {
					rrb(head_b, movements);
					i++;
			}
	}
}

void sort_back_to_a(t_stack **head_a, t_stack **head_b, int *size_a, int *size_b, int *movements) {
	while (*head_b) {
			t_stack *max_node = *head_b;
			t_stack *current = (*head_b)->next;
			int max_position = 0;
			int current_position = 1;
			
			while (current) {
					if (current->content > max_node->content) {
							max_node = current;
							max_position = current_position;
					}
					current_position++;
					current = current->next;
			}
			
			move_to_position_in_b(head_b, max_position, movements);
			pa(head_b, head_a, size_b, size_a, movements);
	}
}