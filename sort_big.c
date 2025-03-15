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
// int i = 0;
// int max_bits;
// int original_size;
// //printf("stack_b: %p\n", (void *)*stack_b);
// //printf("size_a: %d\n", *size_a);

// //printf("size_b: %d\n", *size_b);

// //printf("movements: %d\n", *movements);


// if (is_sorted(*stack_a)) 
// return;
// assign_node_index(*stack_a);
// print_stack_a(*stack_a);
// print_stack_a(*stack_a);
// original_size = *size_a;
// max_bits = get_max_bits(original_size - 1);
// while (i < max_bits) {
// int j = 0;
// while (j < original_size && *stack_a != NULL) {
// if (((*stack_a)->index >> i) & 1) {
// //evaluate_ra_rra(stack_a, (*stack_a)->content, movements);
// ra(stack_a, movements);
// } else {
// pb(stack_a, stack_b, size_a, size_b, movements);
// }
// j++;
// }
// while (*size_b > 0) {
// pa(stack_b, stack_a, size_b, size_a, movements);
// }
// i++;
// }
// }
// Función para obtener el nodo con el valor más cercano al valor objetivo en stack_b

//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
// AQUÍ ABAJO HASTA **** 750 MOVS ****

// t_stack *get_max_node(t_stack *stack) {
// t_stack *max_node = NULL;
// t_stack *current = stack;

// if (!stack)
// return NULL;

// max_node = stack;
// while (current) {
// if (current->index > max_node->index)
// max_node = current;
// current = current->next;
// }

// return max_node;
// }

// int min(int a, int b) {
// return (a < b) ? a : b;
// }

// int max(int a, int b) {
// return (a > b) ? a : b;
// }

// int abs(int x) {
// return (x < 0) ? -x : x;
// }

// t_stack *get_min_index(t_stack *stack) {
// t_stack *min_node = NULL;
// t_stack *current = stack;

// if (!stack)
// return NULL;

// min_node = stack;
// while (current) {
// if (current->index < min_node->index)
// min_node = current;
// current = current->next;
// }

// return min_node;
// }

// t_stack *get_closest_target(t_stack *stack_b, int target_value) {
// t_stack *closest = NULL;
// t_stack *current = stack_b;
// int min_diff = INT_MAX;

// while (current) {
// int diff = abs(current->index - target_value);
// if (diff < min_diff) {
// min_diff = diff;
// closest = current;
// }
// current = current->next;
// }

// return closest;
// }


// int count_moves_to_top(t_stack *stack, t_stack *node) {
// int count = 0;
// t_stack *current = stack;
// int stack_size = 0;


// while (current) {
// stack_size++;
// current = current->next;
// }

// current = stack;
// while (current && current != node) {
// count++;
// current = current->next;
// }

// if (count > stack_size / 2)
// return -(stack_size - count);
// return count;
// }

// void find_best_moves(t_stack *stack_a, t_stack *stack_b, int *moves_a, int *moves_b) {
// t_stack *current_a = stack_a;
// int best_total = INT_MAX;
// *moves_a = 0;
// *moves_b = 0;


// while (current_a) {
// t_stack *target_b = get_closest_target(stack_b, current_a->index);
// if (target_b) {
// int a_moves = count_moves_to_top(stack_a, current_a);
// int b_moves = count_moves_to_top(stack_b, target_b);


// int total_moves;
// if ((a_moves >= 0 && b_moves >= 0) || (a_moves <= 0 && b_moves <= 0)) {

// total_moves = max(abs(a_moves), abs(b_moves));
// } else {

// total_moves = abs(a_moves) + abs(b_moves);
// }

// if (total_moves < best_total) {
// best_total = total_moves;
// *moves_a = a_moves;
// *moves_b = b_moves;
// }
// }
// current_a = current_a->next;
// }
// }


// void execute_moves(t_stack **stack_a, t_stack **stack_b, int moves_a, int moves_b, int *movements) {
// while (moves_a > 0 && moves_b > 0) {
// rr(stack_a, stack_b, movements);
// moves_a--;
// moves_b--;
// }

// while (moves_a < 0 && moves_b < 0) {
// rrr(stack_a, stack_b, movements);
// moves_a++;
// moves_b++;
// }

// while (moves_a > 0) {
// ra(stack_a, movements);
// moves_a--;
// }

// while (moves_a < 0) {
// rra(stack_a, movements);
// moves_a++;
// }

// while (moves_b > 0) {
// rb(stack_b, movements);
// moves_b--;
// }

// while (moves_b < 0) {
// rrb(stack_b, movements);
// moves_b++;
// }
// }


// void big_sort(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b, int *movements) {
// int chunk_size = 20;
// int chunk_count = (*size_a + chunk_size - 1) / chunk_size;
// int original_size = *size_a;

// if (is_sorted(*stack_a)) {
// return;
// }

// assign_node_index(*stack_a);

// for (int chunk = 0; chunk < chunk_count; chunk++) {
// int chunk_start = chunk * chunk_size;
// int chunk_end = min((chunk + 1) * chunk_size - 1, original_size - 1);

// while (*stack_a && *size_b < (chunk + 1) * chunk_size && *size_b < original_size) {
// if ((*stack_a)->index >= chunk_start && (*stack_a)->index <= chunk_end) {
// pb(stack_a, stack_b, size_a, size_b, movements);
// } else {
// ra(stack_a, movements);
// }
// }
// }

// while (*size_b > 0) {

// int moves_a = 0, moves_b = 0;

// t_stack *max_node = get_max_node(*stack_b);
// moves_b = count_moves_to_top(*stack_b, max_node);
// execute_moves(stack_a, stack_b, moves_a, moves_b, movements);
// pa(stack_b, stack_a, size_b, size_a, movements);
// }

// t_stack *min_node = get_min_index(*stack_a);
// int min_moves = count_moves_to_top(*stack_a, min_node);

// while (min_moves != 0) {
// if (min_moves > 0) {
// ra(stack_a, movements);
// min_moves--;
// } else {
// rra(stack_a, movements);
// min_moves++;
// }
// }
// }
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  **** 
//  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****  ****

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

void find_best_moves(t_stack *stack_a, t_stack *stack_b, int *moves_a, int *moves_b) {
t_stack *current_a = stack_a;
int best_total = INT_MAX;
*moves_a = 0;
*moves_b = 0;

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
}
}
current_a = current_a->next;
}
}
int is_sa_beneficial(t_stack *stack_a) {
if (!stack_a || !stack_a->next)
return 0;
if (stack_a->index > stack_a->next->index && stack_a->index - stack_a->next->index == 1)
return 1;

return 0;
}
int is_sb_beneficial(t_stack *stack_b) {
if (!stack_b || !stack_b->next)
return 0;
if (stack_b->index < stack_b->next->index && stack_b->next->index - stack_b->index == 1)
return 1;

return 0;
}
int is_ss_beneficial(t_stack *stack_a, t_stack *stack_b) {
return (is_sa_beneficial(stack_a) && is_sb_beneficial(stack_b));
}
void apply_swaps_if_beneficial(t_stack **stack_a, t_stack **stack_b, int *movements) {
if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next &&
is_ss_beneficial(*stack_a, *stack_b)) {
ss(stack_a, stack_b, movements);
return;
}

if (*stack_a && (*stack_a)->next && is_sa_beneficial(*stack_a)) {
sa(stack_a, movements);
return;
}

if (*stack_b && (*stack_b)->next && is_sb_beneficial(*stack_b)) {
sb(stack_b, movements);
return;
}
}
void execute_moves(t_stack **stack_a, t_stack **stack_b, int moves_a, int moves_b, int *movements) {
if (moves_a == 0 && moves_b == 0) {
if (is_ss_beneficial(*stack_a, *stack_b)) {
ss(stack_a, stack_b, movements);
return;
} else if (is_sa_beneficial(*stack_a)) {
sa(stack_a, movements);
return;
} else if (is_sb_beneficial(*stack_b)) {
sb(stack_b, movements);
return;
}
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

if (is_ss_beneficial(*stack_a, *stack_b)) {
ss(stack_a, stack_b, movements);
} else if (is_sa_beneficial(*stack_a)) {
sa(stack_a, movements);
} else if (is_sb_beneficial(*stack_b)) {
sb(stack_b, movements);
}
}

typedef struct s_cost {
int a_idx;
int b_idx;
int cost_a;
int cost_b;
int total_cost;
} t_cost;

void calculate_optimal_moves(t_stack *stack_a, t_stack *stack_b, int size_a, int size_b, t_cost *cost) {
t_stack *current_b = stack_b;
int b_pos = 0;

cost->total_cost = INT_MAX;

while (current_b) {
t_stack *target_a = NULL;
int target_pos = 0;
int found = 0;


int min_greater = INT_MAX;
t_stack *current_a = stack_a;
int a_pos = 0;

while (current_a) {
if (current_a->index > current_b->index && current_a->index < min_greater) {
min_greater = current_a->index;
target_a = current_a;
target_pos = a_pos;
found = 1;
}
current_a = current_a->next;
a_pos++;
}

if (!found) {
current_a = stack_a;
a_pos = 0;
int min_index = INT_MAX;

while (current_a) {
if (current_a->index < min_index) {
min_index = current_a->index;
target_pos = a_pos;
}
current_a = current_a->next;
a_pos++;
}
}

int cost_a = target_pos;
if (cost_a > size_a / 2)
cost_a = -(size_a - cost_a);

int cost_b = b_pos;
if (cost_b > size_b / 2)
cost_b = -(size_b - cost_b);

int total_cost;
if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
total_cost = max(abs(cost_a), abs(cost_b));
else
total_cost = abs(cost_a) + abs(cost_b);
if (total_cost < cost->total_cost) {
cost->a_idx = target_pos;
cost->b_idx = current_b->index;
cost->cost_a = cost_a;
cost->cost_b = cost_b;
cost->total_cost = total_cost;
}

current_b = current_b->next;
b_pos++;
}
}


void execute_optimal_moves(t_stack **stack_a, t_stack **stack_b, t_cost *cost, int *movements) {
while (cost->cost_a > 0 && cost->cost_b > 0) {
rr(stack_a, stack_b, movements);
cost->cost_a--;
cost->cost_b--;
}

while (cost->cost_a < 0 && cost->cost_b < 0) {
rrr(stack_a, stack_b, movements);
cost->cost_a++;
cost->cost_b++;
}

while (cost->cost_a > 0) {
ra(stack_a, movements);
cost->cost_a--;
}

while (cost->cost_a < 0) {
rra(stack_a, movements);
cost->cost_a++;
}

while (cost->cost_b > 0) {
rb(stack_b, movements);
cost->cost_b--;
}

while (cost->cost_b < 0) {
rrb(stack_b, movements);
cost->cost_b++;
}
}


int find_target_position(t_stack *stack_a, int b_index, int size_a) {
t_stack *current = stack_a;
	printf("%d", size_a);
int target_index = INT_MAX;
int target_pos = 0;
int current_pos = 0;
int found = 0;


while (current) {
if (current->index > b_index && current->index < target_index) {
target_index = current->index;
target_pos = current_pos;
found = 1;
}
current = current->next;
current_pos++;
}

if (!found) {
current = stack_a;
current_pos = 0;
int min_index = INT_MAX;

while (current) {
if (current->index < min_index) {
min_index = current->index;
target_pos = current_pos;
}
current = current->next;
current_pos++;
}
}

return target_pos;
}

int calculate_cost(int pos, int stack_size) {
if (pos <= stack_size / 2)
return pos;
else
return -(stack_size - pos);
}

void find_cheapest_move(t_stack *stack_a, t_stack *stack_b, int size_a, int size_b, int *best_a_pos, int *best_b_pos) {
t_stack *current_b = stack_b;
int best_cost = INT_MAX;
int b_pos = 0;

*best_a_pos = 0;
*best_b_pos = 0;

while (current_b) {
int target_pos = find_target_position(stack_a, current_b->index, size_a);
int cost_a = calculate_cost(target_pos, size_a);
int cost_b = calculate_cost(b_pos, size_b);

int total_cost;
if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
total_cost = max(abs(cost_a), abs(cost_b));
else
total_cost = abs(cost_a) + abs(cost_b);

if (total_cost < best_cost) {
best_cost = total_cost;
*best_a_pos = target_pos;
*best_b_pos = b_pos;
}

current_b = current_b->next;
b_pos++;
}
}

void execute_best_moves(t_stack **stack_a, t_stack **stack_b, int best_a_pos, int best_b_pos, int size_a, int size_b, int *movements) {
int cost_a = calculate_cost(best_a_pos, size_a);
int cost_b = calculate_cost(best_b_pos, size_b);

while (cost_a > 0 && cost_b > 0) {
rr(stack_a, stack_b, movements);
cost_a--;
cost_b--;
}

while (cost_a < 0 && cost_b < 0) {
rrr(stack_a, stack_b, movements);
cost_a++;
cost_b++;
}

while (cost_a > 0) {
ra(stack_a, movements);
cost_a--;
}
while (cost_a < 0) {
rra(stack_a, movements);
cost_a++;
}

while (cost_b > 0) {
rb(stack_b, movements);
cost_b--;
}
while (cost_b < 0) {
rrb(stack_b, movements);
cost_b++;
}
}

void big_sort(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b, int *movements) {
if (is_sorted(*stack_a)) {
return;
}

assign_node_index(*stack_a);

while (*size_a > 3) {
pb(stack_a, stack_b, size_a, size_b, movements);
}
sort_three(stack_a, movements);

while (*size_b > 0) {
int best_a_pos, best_b_pos;
find_cheapest_move(*stack_a, *stack_b, *size_a, *size_b, &best_a_pos, &best_b_pos);
execute_best_moves(stack_a, stack_b, best_a_pos, best_b_pos, *size_a, *size_b, movements);
pa(stack_b, stack_a, size_b, size_a, movements);
}

t_stack *min_node = get_min_index(*stack_a);
int min_pos = 0;
t_stack *current = *stack_a;

while (current != min_node) {
min_pos++;
current = current->next;
}

int min_cost = calculate_cost(min_pos, *size_a);

while (min_cost != 0) {
if (min_cost > 0) {
ra(stack_a, movements);
min_cost--;
} else {
rra(stack_a, movements);
min_cost++;
}
}
}