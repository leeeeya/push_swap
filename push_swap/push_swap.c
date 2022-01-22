# include "push_swap.h"

void print(t_list stack, int no)
{
	int i = 0;
	printf("stack a%d:\n", no);
	while(stack.stack_a[i] != NULL)
	{
		printf("%d\n", *stack.stack_a[i]);
		i++;
	}
	write (1, "\n", 1);
	printf("stack a%d size: %d\n\n", no, stacksize(stack.stack_a));
	i = 0;
	printf("stack b%d:\n", no);
	while (stack.stack_b[i] != NULL)
	{
		printf("%d\n", *stack.stack_b[i]);
		i++;
	}
	write (1, "\n", 1);
	printf("stack b%d size: %d\n\n", no, stacksize(stack.stack_b));
}

int check_sorted_b(int **stack_b)
{
	int i = 0;
	int j = 1;
	if (stack_b[0] != NULL)
	{
		while (stack_b[i] && stack_b[j]) {
			if (*stack_b[i] > *stack_b[j]) {
				i++;
				j++;
			} else
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

int main(int argc, char **argv)
{
	t_list stack;
	int i;
	int size_a;
	int size_b = 0;

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
		while (stack.stack_a[i] != NULL) {
			free(stack.stack_a[i]);
			i++;
		}
		free(stack.stack_a);
		return 0;
	}

//	print(stack, 1);


	while (stack.stack_a[1] != NULL)
	{
		size_a = stacksize(stack.stack_a);
		size_b = stacksize(stack.stack_b);

		if (stack.stack_a[1]
			&& *stack.stack_a[0] > *stack.stack_a[1]
			&& *stack.stack_a[0] > *stack.stack_a[size_a - 1])
		{
			rotate(stack.stack_a, 'a');
//			print(stack, 5);
			if (check_sorted_a(stack.stack_a))
				break;
			continue;
		}
		if (stack.stack_b[1]
			&& *stack.stack_b[0] < *stack.stack_b[1]
			&& *stack.stack_b[0] < *stack.stack_b[size_b - 1])
		{
			rotate(stack.stack_b, 'b');
			continue;
		}
		if ((stack.stack_a[1]
			&& *stack.stack_a[0] > *stack.stack_a[1]
			&& *stack.stack_a[0] > *stack.stack_a[size_a - 1]
			&& (stack.stack_b[1]
			&& *stack.stack_b[0] < *stack.stack_b[1]
			&& *stack.stack_b[0] < *stack.stack_b[size_b - 1])))
		{
			rr(&stack);
			continue;
		}


		if (stack.stack_a[1]
			&& *stack.stack_a[size_a - 1] < *stack.stack_a[0]
			&& *stack.stack_a[size_a - 1] < *stack.stack_a[1])
		{
			rev_rotate(stack.stack_a, 'a');
			if (check_sorted_a(stack.stack_a))
				break;
			continue;
		}
		if (stack.stack_b[1]
			&& *stack.stack_b[size_b - 1] > *stack.stack_b[0]
			&& *stack.stack_b[size_b - 1] > *stack.stack_b[1])
		{
			rev_rotate(stack.stack_b, 'b');
			continue;
		}
		if ((stack.stack_a[1]
			&& *stack.stack_a[size_a - 1] < *stack.stack_a[0]
			 && *stack.stack_a[size_a - 1] < *stack.stack_a[1])
			 && (stack.stack_b[1]
			 && *stack.stack_b[size_b - 1] > *stack.stack_b[0]
			 && *stack.stack_b[size_b - 1] > *stack.stack_b[1]))
		{
			rrr(&stack);
			continue;
		}


		if (stack.stack_a[1]
			&& *stack.stack_a[0] > *stack.stack_a[1]
			&& *stack.stack_a[0] < *stack.stack_a[size_a - 1])
		{
			swap(stack.stack_a, 'a');
			if (check_sorted_a(stack.stack_a) && *stack.stack_a[0] > *stack.stack_b[0])
				break;
			continue;
		}
		if (stack.stack_b[1]
			&& *stack.stack_b[0] < *stack.stack_b[1]
			&& *stack.stack_b[0] > *stack.stack_b[size_b - 1])
		{
			swap(stack.stack_b, 'b');
			continue;
		}
		if ((stack.stack_a[1] && *stack.stack_a[0] > *stack.stack_a[1] &&
			 *stack.stack_a[0] < *stack.stack_a[size_a - 1]
			 && (stack.stack_b[1]
			 && *stack.stack_b[0] < *stack.stack_b[1]
			 && *stack.stack_b[0] > *stack.stack_b[size_b - 1])))
		{
			ss(&stack);
			continue;
		}

		if (*stack.stack_a[0] < *stack.stack_a[1]
			&& *stack.stack_a[0] < *stack.stack_a[size_a - 1])
		{
			push(stack.stack_a, stack.stack_b, 'b');
			continue;
		}
		if (check_sorted_a(stack.stack_a))
			break;

	}
//	write (1, "\n", 1);
//	print(stack, 2);
//	write (1, "\n", 1);
	size_b = stacksize(stack.stack_b);
	while(size_b != 0)
	{
		size_b = stacksize(stack.stack_b);
//		size_b--;
		if (!stack.stack_b[1] || (*stack.stack_b[0] < *stack.stack_a[0] && *stack.stack_b[0] > *stack.stack_b[1]))
		{
			push(stack.stack_b, stack.stack_a, 'a');
			size_b--;
			continue;
		}
		if (stack.stack_b[1] && *stack.stack_b[0] < *stack.stack_b[1])
		{
			swap(stack.stack_b, 'b');
			continue;
		}
		if (stack.stack_a[1]
			&& *stack.stack_a[0] > *stack.stack_a[1]
			&& *stack.stack_a[0] < *stack.stack_a[size_a - 1])
		{
			swap(stack.stack_a, 'a');
			continue;
		}
	}
	print(stack, 2);
	free(stack.stack_b);
	while (stack.stack_a[i] != NULL)
	{
		free (stack.stack_a[i]);
		i++;
	}
	free (stack.stack_a);

}