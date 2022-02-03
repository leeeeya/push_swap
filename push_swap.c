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

	if (stack_a[0] != NULL)
	{
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
	}
	return 1;
}

int main(int argc, char **argv)
{
	t_struct stack;
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

//	printf("%d\n", search_max(stack.stack_a));

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
	for_three(stack.stack_a);
//	if (argc <= 6)
		for_five(stack);
//	print(stack.stack_a, 1);
	return 0;
}
