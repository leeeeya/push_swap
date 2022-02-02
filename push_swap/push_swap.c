# include "push_swap.h"

void print(int **stack_a, int no)
{
	int i = 0;
	printf("stack a%d:\n", no);
	while(stack_a[i] != NULL)
	{
		printf("%d\n", *stack_a[i]);
		i++;
	}
	write (1, "\n", 1);
	printf("stack a%d size: %d\n\n", no, stacksize(stack_a));
//	i = 0;
//	printf("stack b%d:\n", no);
//	while (stack_b[i] != NULL)
//	{
//		printf("%d\n", *stack_b[i]);
//		i++;
//	}
//	write (1, "\n", 1);
//	printf("stack b%d size: %d\n\n", no, stacksize(stack_b));
}

int check_sorted_b(int **stack_b)
{
	int i = 0;
	int j = 1;
	if (stack_b[0] != NULL)
	{
		while (stack_b[i] && stack_b[j]) {
			if (*stack_b[i] > *stack_b[j])
			{
				i++;
				j++;
			}
			else
				return 0;
		}
		return 1;
	}
	return 0;
}

int check_sorted_a (int ** stack_a)
{
	int i = 0;
	int j = 1;

	while (stack_a[i] && stack_a[j])
	{
		if (*stack_a[i] < *stack_a[j])
		{
			i++;
			j++;
		}
		else
			return 0;
	}
	return 1;
}

void	for_three(int **stack_a)
{
	int size;

	size = stacksize(stack_a);
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

int search_less (int **stack_a)
{
	int i;
	int j;

	i = 0;
	while (stack_a[i])
	{
		j = i + 1;
		while (stack_a[j] && *stack_a[i] < *stack_a[j])
			j++;
		if (stack_a[j] == NULL)
			break;
		i++;
	}
	return *stack_a[i];
}

int search_index(int **stack)
{
	int i;
	int small;

	i = 0;
	small = search_less(stack);
	while (*stack[i] != small)
		i++;
	return i;
}

void for_five(t_list stack)
{
	int size_a;
	int less;

	size_a = stacksize(stack.stack_a);
	while (size_a != 3)
	{
		less = search_less(stack.stack_a);
		while (*stack.stack_a[0] != less)
		{
			if (search_index(stack.stack_a) <= size_a / 2)
				rotate(stack.stack_a, 'a');
			else
				rev_rotate(stack.stack_a, 'a');
		}
		push(stack.stack_a, stack.stack_b, 'b');
		size_a = stacksize(stack.stack_a);
	}
	for_three(stack.stack_a);
	if (stack.stack_b[1] && *stack.stack_b[0] < *stack.stack_b[1])
		swap(stack.stack_b, 'b');
	while (*stack.stack_b != NULL)
		push(stack.stack_b, stack.stack_a, 'a');
}


int main(int argc, char **argv)
{
	t_list stack;
	int i;
//	int size_a;
//	int size_b = 0;

	i = 0;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return 0;
	}
	stack = check_arguments(argc, argv);

	if (check_sorted_a(stack.stack_a))
	{
		free(stack.stack_b);
		while (stack.stack_a[i] != NULL)
		{
			free(stack.stack_a[i]);
			i++;
		}
		free(stack.stack_a);
		write(1, "Stack is already sorted\n", 24);
		return 1;
	}
	if (argc <= 4)
		for_three(stack.stack_a);
	if (argc <= 6)
		for_five(stack);
	print(stack.stack_a, 1);
	return 0;
}
