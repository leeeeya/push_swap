#include "push_swap.h"

void	for_three(int **stack_a)
{
	int size;

	size = stacksize(stack_a);
	if (size <= 3)
	{
		while (check_sorted_a(stack_a) != 1)
		{
			if (*stack_a[0] < *stack_a[1])
				rev_rotate(stack_a, 'a');
			if ((*stack_a[0] > *stack_a[1])
				&& (*stack_a[size - 1] > *stack_a[0]))
				swap(stack_a, 'a');
			if (*stack_a[0] > *stack_a[1])
				rotate(stack_a, 'a');
		}
	}
}

int search_min(int **stack)
{
	int i;
	int j;

	i = 0;
	while (stack[i])
	{
		j = i + 1;
		while (stack[j] && *stack[i] < *stack[j])
			j++;
		if (stack[j] == NULL)
			break;
		i++;
	}
	return *stack[i];
}

int	search_max (int **stack)
{
	int i;
	int j;

	i = 0;
	while (stack[i])
	{
		j = i + 1;
		while (stack[j] && *stack[i] > *stack[j])
			j++;
		if (stack[j] == NULL)
			break;
		i++;
	}
	return *stack[i];
}

int	search_mid(int max, int min)
{
	int i;

	i = (min + max) / 2;
	return i;
}

int search_index(int **stack, int digit)
{
	int i;

	i = 0;
	while (*stack[i] != digit)
		i++;
	return i;
}

void for_five(t_struct stack)
{
	int size_a;
	int less;

	size_a = stacksize(stack.stack_a);
	while (size_a != 3)
	{
		less = search_min(stack.stack_a);
		while (*stack.stack_a[0] != less)
		{
			if (*stack.stack_a[1] == less)
				swap(stack.stack_a, 'a');
			else if (search_index(stack.stack_a, less) <= size_a / 2)
				rotate(stack.stack_a, 'a');
			else
				rev_rotate(stack.stack_a, 'a');
		}
		if (!check_sorted_a(stack.stack_a))
		{
			push(stack.stack_a, stack.stack_b, 'b');
			size_a = stacksize(stack.stack_a);
		}
		else
			break;
	}
	for_three(stack.stack_a);
	if (stack.stack_b[1] && *stack.stack_b[0] < *stack.stack_b[1])
		swap(stack.stack_b, 'b');
	while (*stack.stack_b != NULL)
		push(stack.stack_b, stack.stack_a, 'a');
}

void	big_sort(t_struct stack)
{
	int size_a;
	int	size_b;
	int min;
	int max;
	int mid;
	int mid_less;
	int dig_count = 0;
	int i = 0;

//	size_a = stacksize(stack.stack_a);
//	size_b = stacksize(stack.stack_b);
	min = search_min(stack.stack_a);
	max = search_max(stack.stack_a);
	mid = search_mid(max, min);
	mid_less = search_mid(mid, min);

	while (stack.stack_a[i])
	{
		if (*stack.stack_a[i] <= mid_less)
			dig_count++;
		i++;
	}
	while (stacksize(stack.stack_b) != dig_count)
	{
//		min = search_min(stack.stack_a);


//		while (*stack.stack_a[0] != min)
//		{
//		if (*stack.stack_a[1] == min)
//			swap(stack.stack_a, 'a');
		if (search_index(stack.stack_a, min) <= size_a / 2)
			rotate(stack.stack_a, 'a');
		else
				rev_rotate(stack.stack_a, 'a');
//		}
		if (check_sorted_a(stack.stack_a))
			break;
		push(stack.stack_a, stack.stack_b, 'b');
		size_a = stacksize(stack.stack_a);
	}

}