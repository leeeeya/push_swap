#include "push_swap.h"

void check_duplicates(int **stack)
{
	int i;
	int j;

	i = 0;
	while (stack[i] != NULL)
	{
		j = i + 1;
		while (stack[j])
		{
			if(*stack[i] == *stack[j])
				arg_error_handler(15);
			j++;
		}
		i++;
	}
}

void check_digits (char **argv)
{
	int i;
	int j;

	i = 1;
	while(argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' && (argv[i][j + 1] > 48 && argv[i][j + 1] < 58))
			j++;
		if (argv[i][0] == '0' && argv[i][1] != '\0')
			arg_error_handler(34);
		while (argv[i][j])
		{
			if (argv[i][j] > 47 && argv[i][j] < 58)
				j++;
			else
				arg_error_handler(40);
		}
		i++;
	}
}

//int	count_arg(char *argv)
//{
//
//}

int count_all(char **argv)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_strchr(argv[i], ' '))
			count += ft_word_count(argv[i], ' ');
		else
			count++;
		i++;
	}
	return (count);
}


t_struct check_arguments(int argc, char *argv[])
{
	int i;
	t_struct stack;

	i = 0;


	while (argv[i] != NULL)
	{
		if (ft_strchr(argv[i], ' '))
		{
			write (1, "There are ARG\n", 14);
			exit (0);
		}
		i++;
	}


	check_digits(argv);
	stack.stack_a = (int **)ft_calloc(argc, sizeof(int *));
	mem_error_handler(stack.stack_a);
	while (i != argc - 1)
	{
		stack.stack_a[i] = (int *)ft_calloc(1, sizeof (int));
		mem_error_handler(stack.stack_a[i]);
		i++;
	}
	i = 0;
	stack.stack_b = (int **)ft_calloc(argc, sizeof(int *));
	mem_error_handler(stack.stack_b);
	i = 1;
	while(argv[i] != NULL)
	{
		*(stack.stack_a[i - 1]) = ft_atoi(argv[i]);
		i++;
	}
	check_duplicates(stack.stack_a);
	return (stack);
}
