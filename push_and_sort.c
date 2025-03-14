#include "push_swap.h"



void evaluate_rb_rrb(t_stack **list_b, int current_value, int *movements) {
	if (*list_b == NULL) return;
	
	// Determinar el tamaño de la lista y la posición objetivo
	t_stack *temp = *list_b;
	int list_size = 0;
	int target_pos = 0;
	int found = 0;
	
	// Primer paso: contar nodos
	while (temp) {
			list_size++;
			temp = temp->next;
	}
	
	if (list_size == 0) return;
	
	// Buscar dónde insertar (para orden ascendente en la lista final)
	temp = *list_b;
	//int prev_val = temp ? temp->content : 0;
	t_stack *last = NULL;
	
	// Encontrar el nodo después del cual insertar
	int pos = 0;
	int max_val = INT_MIN;
	int max_pos = 0;
	int min_val = INT_MAX;
	int min_pos = 0;
	
	// Primero identificar el mínimo y máximo
	temp = *list_b;
	pos = 0;
	while (temp) {
			if (temp->content > max_val) {
					max_val = temp->content;
					max_pos = pos;
			}
			if (temp->content < min_val) {
					min_val = temp->content;
					min_pos = pos;
			}
			temp = temp->next;
			pos++;
	}
	
	// Decidir dónde insertar basado en el valor
	if (list_size == 1) {
			target_pos = 0; // Con un solo elemento, no hay rotación
	} else if (current_value > max_val) {
			// Si es el mayor, colocar después del máximo actual
			target_pos = (max_pos + 1) % list_size;
	} else if (current_value < min_val) {
			// Si es el menor, colocar en la posición del mínimo
			target_pos = min_pos;
	} else {
			// Buscar la posición correcta entre elementos
			temp = *list_b;
			last = NULL;
			pos = 0;
			while (temp) {
					if (last) {
							// Buscar un hueco donde current_value esté entre los dos valores
							if ((last->content < current_value && current_value < temp->content) ||
									(last->content > temp->content && (current_value > last->content || current_value < temp->content))) {
									target_pos = pos;
									found = 1;
									break;
							}
					}
					last = temp;
					temp = temp->next;
					pos++;
			}
			
			// Si no encontró posición, colocar al final
			if (!found) {
					target_pos = 0;
			}
	}
	
	// Calcular la rotación más eficiente
	int forward_moves = target_pos;
	int backward_moves = list_size - target_pos;
	
	// Aplicar la rotación
	if (forward_moves <= backward_moves) {
			while (forward_moves-- > 0) {
					rb(list_b, movements);
			}
	} else {
			while (backward_moves-- > 0) {
					rrb(list_b, movements);
			}
	}
}

void evaluate_ra_rra(t_stack **list_a, int current_value, int *movements) {
	if (*list_a == NULL) return;

	t_stack *temp = *list_a;
	int list_size = 0;
	int pos = 0, target_pos = 0;
	int min_val = INT_MAX, max_val = INT_MIN;
	int min_pos = 0, max_pos = 0;

	// Recorrer la lista una sola vez para contar nodos y encontrar min/max
	while (temp) {
			if (temp->content > max_val) {
					max_val = temp->content;
					max_pos = pos;
			}
			if (temp->content < min_val) {
					min_val = temp->content;
					min_pos = pos;
			}
			list_size++;
			temp = temp->next;
			pos++;
	}

	// Si solo hay un elemento, no se necesita rotación
	if (list_size == 1) return;

	// Determinar posición de inserción
	if (current_value > max_val) {
			target_pos = max_pos + 1;
			if (target_pos >= list_size) target_pos = 0; // Evita ir fuera de rango
	} 
	else if (current_value < min_val) {
			target_pos = min_pos; // Insertar en la posición del menor
	} 
	else {
			// Buscar la posición correcta en la lista
			temp = *list_a;
			t_stack *last = NULL;
			pos = 0;
			while (temp) {
					if (last && ((last->content < current_value && current_value < temp->content) ||
											 (last->content > temp->content && (current_value > last->content || current_value < temp->content)))) {
							target_pos = pos;
							break;
					}
					last = temp;
					temp = temp->next;
					pos++;
			}
	}

	// Si target_pos ya está en 0, no rotar
	if (target_pos == 0) return;

	// Calcular rotaciones más eficientes
	int forward_moves = target_pos;
	int backward_moves = list_size - target_pos;

	if (forward_moves <= backward_moves) {
			while (forward_moves-- > 0) {
					ra(list_a, movements);  // Ejecutar `ra`
			}
	} else {
			while (backward_moves-- > 0) {
					rra(list_a, movements);  // Ejecutar `rra`
			}
	}
}
void push_and_sort(t_stack **list_a, t_stack **list_b, int *size_a, int *size_b, int *movements) {
	while (*size_a > 0) {
			if (*size_b > 0) {
					//evaluate_rb_rrb(list_b, (*list_a)->content, movements);
					rb(list_b, movements);
			}
			pb(list_a, list_b, size_a, size_b, movements);
	}
				//print_list(*list_a);
			//print_list(*list_b);
	while (*size_b > 0) {
			pa(list_b, list_a, size_b, size_a, movements);
	}
}

// void push_and_sort(t_stack **list_a, t_stack **list_b, int *size_a, int *size_b, int *movements) {
// 	// Primero hacemos push del primer elemento
// 	if (*size_a > 0) {
// 			pb(list_a, list_b, size_a, size_b, movements);
// 	}
	
// 	// Luego procesamos el resto
// 	while (*size_a > 0) {
// 			// Rotar lista B para colocar en posición correcta
// 			evaluate_rb_rrb(list_b, (*list_a)->content, movements);
			
// 			// Push el elemento actual
// 			pb(list_a, list_b, size_a, size_b, movements);
// 	}
	
// 	// Ahora rotamos lista B para que el elemento mínimo esté en la parte superior
// 	t_stack *temp = *list_b;
// 	int min_val = temp ? temp->content : 0;
// 	int min_pos = 0;
// 	int pos = 0;
// 	int list_size = *size_b;
	
// 	// Encontrar la posición del mínimo
// 	while (temp) {
// 			if (temp->content < min_val) {
// 					min_val = temp->content;
// 					min_pos = pos;
// 			}
// 			temp = temp->next;
// 			pos++;
// 	}
	
// 	// Rotar para poner el mínimo arriba
// 	int forward_moves = min_pos;
// 	int backward_moves = list_size - min_pos;
	
// 	if (forward_moves <= backward_moves) {
// 			while (forward_moves-- > 0) {
// 					rb(list_b, movements);
// 			}
// 	} else {
// 			while (backward_moves-- > 0) {
// 					rrb(list_b, movements);
// 			}
// 	}
	
// 	// Hacer pa para todos los elementos
// 	while (*size_b > 0) {
// 			pa(list_b, list_a, size_b, size_a, movements);
// 	}
// }


// void push_and_sort(t_stack **list_a, t_stack **list_b, int *size_a, int *size_b, int *movements) {
// 	while (*size_a > 0) {
// 			int value_to_push = (*list_a)->content; // Guardamos el valor antes de pushear
// 			pb(list_a, list_b, size_a, size_b, movements);

// 			if (*size_b > 1) {
// 					evaluate_rb_rrb(list_b, value_to_push, movements);
// 			}

// 			print_list(*list_a);
// 			print_list(*list_b);
// 	}

// 	while (*size_b > 0) {
// 			pa(list_b, list_a, size_b, size_a, movements);
// 	}
// }

// void evaluate_rb_rrb(t_stack **list_b, int current_value, int *movements) {
// 	int best_position = 0;
// 	int position = 0;
// 	int list_size = 0;
// 	t_stack *temp = *list_b;

// 	if (*list_b == NULL || (*list_b)->next == NULL) return;

// 	while (temp) {
// 			list_size++;
// 			temp = temp->next;
// 	}

// 	temp = *list_b;
// 	while (temp && temp->next) {
// 			if (current_value < temp->content && current_value > temp->next->content) {
// 					best_position = position + 1;
// 					break;
// 			}
// 			temp = temp->next;
// 			position++;
// 	}

// 	if (position == list_size - 1) {
// 			t_stack *min_node = *list_b;
// 			t_stack *max_node = *list_b;
// 			int min_pos = 0, max_pos = 0;

// 			temp = *list_b;
// 			position = 0;
// 			while (temp) {
// 					if (temp->content < min_node->content) {
// 							min_node = temp;
// 							min_pos = position;
// 					}
// 					if (temp->content > max_node->content) {
// 							max_node = temp;
// 							max_pos = position;
// 					}
// 					temp = temp->next;
// 					position++;
// 			}

// 			if (current_value < min_node->content) {
// 					best_position = min_pos;
// 			}
// 			else if (current_value > max_node->content) {
// 					best_position = max_pos + 1;
// 			}
// 	}

// 	int forward_moves = best_position;
// 	int backward_moves = list_size - best_position;

// 	if (forward_moves <= backward_moves) {
// 			while (forward_moves-- > 0) {
// 					rb(list_b, movements);
// 			}
// 	} else {
// 			while (backward_moves-- > 0) {
// 					rrb(list_b, movements);
// 			}
// 	}
// }


