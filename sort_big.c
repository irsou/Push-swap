 #include "push_swap.h"

int get_max_bits(int max_value) {
	int bits = 0;
	
	while (max_value > 0) {
			bits++;
			max_value >>= 1;
	}
	return bits;
}

void big_sort(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b, int *movements) {
    int i = 0;
    int max_bits;
    int original_size;
    //printf("stack_b: %p\n", (void *)*stack_b);
    //printf("size_a: %d\n", *size_a);

    //printf("size_b: %d\n", *size_b);

    //printf("movements: %d\n", *movements);


    if (is_sorted(*stack_a)) 
        return;
    assign_node_index(*stack_a);
    print_stack_a(*stack_a);
    print_stack_a(*stack_a);
    original_size = *size_a;
    max_bits = get_max_bits(original_size - 1);
    while (i < max_bits) {
        int j = 0;
        while (j < original_size && *stack_a != NULL) {
            if (((*stack_a)->index >> i) & 1) {
                //evaluate_ra_rra(stack_a, (*stack_a)->content, movements);
                ra(stack_a, movements);
            } else {
                pb(stack_a, stack_b, size_a, size_b, movements);
            }
            j++;
        }
        while (*size_b > 0) {
            pa(stack_b, stack_a, size_b, size_a, movements);
        }
        i++;
    }
}
