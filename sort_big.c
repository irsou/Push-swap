 #include "push_swap.h"

int get_max_bits(int max_value) {
	int bits = 0;
	
	while (max_value > 0) {
			bits++;
			max_value >>= 1;
	}
	return bits;
}

// void big_sort(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b, int *movements) {
//     int i = 0;
//     int max_bits;
//     int original_size;
//     //printf("stack_b: %p\n", (void *)*stack_b);
//     //printf("size_a: %d\n", *size_a);

//     //printf("size_b: %d\n", *size_b);

//     //printf("movements: %d\n", *movements);


//     if (is_sorted(*stack_a)) 
//         return;
//     assign_node_index(*stack_a);
//     print_stack_a(*stack_a);
//     print_stack_a(*stack_a);
//     original_size = *size_a;
//     max_bits = get_max_bits(original_size - 1);
//     while (i < max_bits) {
//         int j = 0;
//         while (j < original_size && *stack_a != NULL) {
//             if (((*stack_a)->index >> i) & 1) {
//                 //evaluate_ra_rra(stack_a, (*stack_a)->content, movements);
//                 ra(stack_a, movements);
//             } else {
//                 pb(stack_a, stack_b, size_a, size_b, movements);
//             }
//             j++;
//         }
//         while (*size_b > 0) {
//             pa(stack_b, stack_a, size_b, size_a, movements);
//         }
//         i++;
//     }
// }
// Función para obtener el nodo con el valor más cercano al valor objetivo en stack_b

//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
// AQUÍ ABAJO HASTA **** 750 MOVS ****

// t_stack *get_max_node(t_stack *stack) {
//     t_stack *max_node = NULL;
//     t_stack *current = stack;
    
//     if (!stack)
//         return NULL;
    
//     max_node = stack;
//     while (current) {
//         if (current->index > max_node->index)
//             max_node = current;
//         current = current->next;
//     }
    
//     return max_node;
// }

// int min(int a, int b) {
//     return (a < b) ? a : b;
// }

// int max(int a, int b) {
//     return (a > b) ? a : b;
// }

// int abs(int x) {
//     return (x < 0) ? -x : x;
// }

// t_stack *get_min_index(t_stack *stack) {
//     t_stack *min_node = NULL;
//     t_stack *current = stack;
    
//     if (!stack)
//         return NULL;
    
//     min_node = stack;
//     while (current) {
//         if (current->index < min_node->index)
//             min_node = current;
//         current = current->next;
//     }
    
//     return min_node;
// }

// t_stack *get_closest_target(t_stack *stack_b, int target_value) {
//     t_stack *closest = NULL;
//     t_stack *current = stack_b;
//     int min_diff = INT_MAX;
    
//     while (current) {
//         int diff = abs(current->index - target_value);
//         if (diff < min_diff) {
//             min_diff = diff;
//             closest = current;
//         }
//         current = current->next;
//     }
    
//     return closest;
// }


// int count_moves_to_top(t_stack *stack, t_stack *node) {
//     int count = 0;
//     t_stack *current = stack;
//     int stack_size = 0;
    

//     while (current) {
//         stack_size++;
//         current = current->next;
//     }
    
//     current = stack;
//     while (current && current != node) {
//         count++;
//         current = current->next;
//     }
    
//     if (count > stack_size / 2)
//         return -(stack_size - count);
//     return count;
// }

// void find_best_moves(t_stack *stack_a, t_stack *stack_b, int *moves_a, int *moves_b) {
//     t_stack *current_a = stack_a;
//     int best_total = INT_MAX;
//     *moves_a = 0;
//     *moves_b = 0;
    

//     while (current_a) {
//         t_stack *target_b = get_closest_target(stack_b, current_a->index);
//         if (target_b) {
//             int a_moves = count_moves_to_top(stack_a, current_a);
//             int b_moves = count_moves_to_top(stack_b, target_b);
            

//             int total_moves;
//             if ((a_moves >= 0 && b_moves >= 0) || (a_moves <= 0 && b_moves <= 0)) {

//                 total_moves = max(abs(a_moves), abs(b_moves));
//             } else {

//                 total_moves = abs(a_moves) + abs(b_moves);
//             }
            
//             if (total_moves < best_total) {
//                 best_total = total_moves;
//                 *moves_a = a_moves;
//                 *moves_b = b_moves;
//             }
//         }
//         current_a = current_a->next;
//     }
// }


// void execute_moves(t_stack **stack_a, t_stack **stack_b, int moves_a, int moves_b, int *movements) {
//     while (moves_a > 0 && moves_b > 0) {
//         rr(stack_a, stack_b, movements);
//         moves_a--;
//         moves_b--;
//     }
    
//     while (moves_a < 0 && moves_b < 0) {
//         rrr(stack_a, stack_b, movements);
//         moves_a++;
//         moves_b++;
//     }
    
//     while (moves_a > 0) {
//         ra(stack_a, movements);
//         moves_a--;
//     }
    
//     while (moves_a < 0) {
//         rra(stack_a, movements);
//         moves_a++;
//     }
    
//     while (moves_b > 0) {
//         rb(stack_b, movements);
//         moves_b--;
//     }
    
//     while (moves_b < 0) {
//         rrb(stack_b, movements);
//         moves_b++;
//     }
// }


// void big_sort(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b, int *movements) {
//     int chunk_size = 20;
//     int chunk_count = (*size_a + chunk_size - 1) / chunk_size;
//     int original_size = *size_a;
    
//     if (is_sorted(*stack_a)) {
//         return;
//     }
    
//     assign_node_index(*stack_a);
    
//     for (int chunk = 0; chunk < chunk_count; chunk++) {
//         int chunk_start = chunk * chunk_size;
//         int chunk_end = min((chunk + 1) * chunk_size - 1, original_size - 1);
        
//         while (*stack_a && *size_b < (chunk + 1) * chunk_size && *size_b < original_size) {
//             if ((*stack_a)->index >= chunk_start && (*stack_a)->index <= chunk_end) {
//                 pb(stack_a, stack_b, size_a, size_b, movements);
//             } else {
//                 ra(stack_a, movements);
//             }
//         }
//     }
    
//     while (*size_b > 0) {

//         int moves_a = 0, moves_b = 0;
        
//         t_stack *max_node = get_max_node(*stack_b);
//         moves_b = count_moves_to_top(*stack_b, max_node);
//         execute_moves(stack_a, stack_b, moves_a, moves_b, movements);
//         pa(stack_b, stack_a, size_b, size_a, movements);
//     }
    
//     t_stack *min_node = get_min_index(*stack_a);
//     int min_moves = count_moves_to_top(*stack_a, min_node);
    
//     while (min_moves != 0) {
//         if (min_moves > 0) {
//             ra(stack_a, movements);
//             min_moves--;
//         } else {
//             rra(stack_a, movements);
//             min_moves++;
//         }
//     }
// }
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** ç



t_stack *get_max_node(t_stack *stack) {
    t_stack *max_node = NULL;
    t_stack *current = stack;
    
    if (!stack)
        return NULL;
    
    max_node = stack;
    while (current) {
        if (current->index > max_node->index)
            max_node = current;
        current = current->next;
    }
    
    return max_node;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int abs(int x) {
    return (x < 0) ? -x : x;
}

t_stack *get_min_index(t_stack *stack) {
    t_stack *min_node = NULL;
    t_stack *current = stack;
    
    if (!stack)
        return NULL;
    
    min_node = stack;
    while (current) {
        if (current->index < min_node->index)
            min_node = current;
        current = current->next;
    }
    
    return min_node;
}

t_stack *get_closest_target(t_stack *stack_b, int target_value) {
    t_stack *closest = NULL;
    t_stack *current = stack_b;
    int min_diff = INT_MAX;
    
    while (current) {
        int diff = abs(current->index - target_value);
        if (diff < min_diff) {
            min_diff = diff;
            closest = current;
        }
        current = current->next;
    }
    
    return closest;
}


int count_moves_to_top(t_stack *stack, t_stack *node) {
    int count = 0;
    t_stack *current = stack;
    int stack_size = 0;
    

    while (current) {
        stack_size++;
        current = current->next;
    }
    
    current = stack;
    while (current && current != node) {
        count++;
        current = current->next;
    }
    
    if (count > stack_size / 2)
        return -(stack_size - count);
    return count;
}


void find_best_moves(t_stack *stack_a, t_stack *stack_b, int *moves_a, int *moves_b, int *use_sa, int *use_sb, int *use_ss) {
    t_stack *current_a = stack_a;
    int best_total = INT_MAX;
    *moves_a = 0;
    *moves_b = 0;
    *use_sa = 0;
    *use_sb = 0;
    *use_ss = 0;

    while (current_a) {
        t_stack *target_b = get_closest_target(stack_b, current_a->index);
        if (target_b) {
            int a_moves = count_moves_to_top(stack_a, current_a);
            int b_moves = count_moves_to_top(stack_b, target_b);

            int total_moves;
            if ((a_moves >= 0 && b_moves >= 0) || (a_moves <= 0 && b_moves <= 0)) {
                total_moves = max(abs(a_moves), abs(b_moves));
            } else {
                total_moves = abs(a_moves) + abs(b_moves);
            }

            if (total_moves < best_total) {
                best_total = total_moves;
                *moves_a = a_moves;
                *moves_b = b_moves;
                *use_sa = 0;
                *use_sb = 0;
                *use_ss = 0;
            }

            if (current_a->next && current_a->index > current_a->next->index) {
                int sa_moves = count_moves_to_top(stack_a, current_a->next);
                if (sa_moves < best_total) {
                    best_total = sa_moves;
                    *moves_a = sa_moves;
                    *moves_b = b_moves;
                    *use_sa = 1;
                    *use_sb = 0;
                    *use_ss = 0;
                }
            }

            if (target_b->next && target_b->index > target_b->next->index) {
                int sb_moves = count_moves_to_top(stack_b, target_b->next);
                if (sb_moves < best_total) {
                    best_total = sb_moves;
                    *moves_a = a_moves;
                    *moves_b = sb_moves;
                    *use_sa = 0;
                    *use_sb = 1;
                    *use_ss = 0;
                }
            }

            if (current_a->next && current_a->index > current_a->next->index &&
                target_b->next && target_b->index > target_b->next->index) {
                int ss_moves = max(count_moves_to_top(stack_a, current_a->next), count_moves_to_top(stack_b, target_b->next));
                if (ss_moves < best_total) {
                    best_total = ss_moves;
                    *moves_a = ss_moves;
                    *moves_b = ss_moves;
                    *use_sa = 0;
                    *use_sb = 0;
                    *use_ss = 1;
                }
            }
        }
        current_a = current_a->next;
    }
}

void execute_moves(t_stack **stack_a, t_stack **stack_b, int moves_a, int moves_b, int *movements, int use_sa, int use_sb, int use_ss) {
    if (use_ss) {
        ss(stack_a, stack_b, movements);
        return;
    }

    if (use_sa) {
        sa(stack_a, movements);
        return;
    }

    if (use_sb) {
        sb(stack_b, movements);
        return;
    }

    while (moves_a > 0 && moves_b > 0) {
        rr(stack_a, stack_b, movements);
        moves_a--;
        moves_b--;
    }

    while (moves_a < 0 && moves_b < 0) {
        rrr(stack_a, stack_b, movements);
        moves_a++;
        moves_b++;
    }

    while (moves_a > 0) {
        ra(stack_a, movements);
        moves_a--;
    }

    while (moves_a < 0) {
        rra(stack_a, movements);
        moves_a++;
    }

    while (moves_b > 0) {
        rb(stack_b, movements);
        moves_b--;
    }

    while (moves_b < 0) {
        rrb(stack_b, movements);
        moves_b++;
    }
}

void big_sort(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b, int *movements) {
    int chunk_size = 20;
    int chunk_count = (*size_a + chunk_size - 1) / chunk_size;
    int original_size = *size_a;

    if (is_sorted(*stack_a)) {
        return;
    }

    assign_node_index(*stack_a);

    for (int chunk = 0; chunk < chunk_count; chunk++) {
        int chunk_start = chunk * chunk_size;
        int chunk_end = min((chunk + 1) * chunk_size - 1, original_size - 1);

        while (*stack_a && *size_b < (chunk + 1) * chunk_size && *size_b < original_size) {
            if ((*stack_a)->index >= chunk_start && (*stack_a)->index <= chunk_end) {
                pb(stack_a, stack_b, size_a, size_b, movements);
            } else {
                ra(stack_a, movements);
            }
        }
    }

    while (*size_b > 0) {
        int moves_a = 0, moves_b = 0;
        int use_sa = 0, use_sb = 0, use_ss = 0;

        find_best_moves(*stack_a, *stack_b, &moves_a, &moves_b, &use_sa, &use_sb, &use_ss);
        execute_moves(stack_a, stack_b, moves_a, moves_b, movements, use_sa, use_sb, use_ss);
        pa(stack_b, stack_a, size_b, size_a, movements);
    }

    t_stack *min_node = get_min_index(*stack_a);
    int min_moves = count_moves_to_top(*stack_a, min_node);

    while (min_moves != 0) {
        if (min_moves > 0) {
            ra(stack_a, movements);
            min_moves--;
        } else {
            rra(stack_a, movements);
            min_moves++;
        }
    }
}