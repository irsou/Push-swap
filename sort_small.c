#include "push_swap.h"

void	sort_three(t_stack **list_l, int *movements)
{
	int		a;
	int		b;
	int		c;

	if (is_sorted(*list_l))
		return ;
	a = (*list_l)->content;
	b = (*list_l)->next->content;
	c = (*list_l)->next->next->content;
	if (a < b && b > c && a < c)
	{
		sa(list_l, movements);
		ra(list_l, movements);
	}
	else if (a < b && b > c && c < a)
		rra(list_l, movements);
	else if (a > b && c > a && c > b)
		sa(list_l, movements);
	else if (a > b && c < a && c > b)
		ra(list_l, movements);
	else if (a > b && c < a && c < b)
	{
		sa(list_l, movements);
		rra(list_l, movements);
	}
	return ;
}

void	sort_five(t_stack **list_a, t_stack **list_b, int *size_b, int *size_a, int *movements)
{
	int		min;
	int		pos;
	int		pushed;

	pushed = 0;
	if (is_sorted(*list_a))
		return ;
	while (pushed < 2)
	{
		min = find_min(*list_a);
		pos = find_position(*list_a, min);
		while ((*list_a)->content != min)
		{
			if (pos <= 2)
				ra(list_a, movements);
			else
				rra(list_a, movements);
		}
		pb(list_a, list_b, size_a, size_b, movements);
		pushed++;
	}
	sort_three(list_a, movements);
	while (pushed > 0)
	{
		pa(list_b, list_a, size_b, size_a, movements);
		pushed--;
	}
	return ;
}
