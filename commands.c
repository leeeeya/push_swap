#include "push_swap.h"

int stacksize (int **stack)
{
	int i;

	i = 0;
	while (stack[i] != NULL)
		i++;
	return i;
}

void add_front(int **stack, int buf)
{
	int i;

	i = stacksize(stack) - 1;
	while (i != 0)
	{
		*stack[i] = *stack[i - 1];
		i--;
	}
	*stack[0] = buf;
}


int *pop(int **stack)
{
	int *buf;
	int i;

	i = 0;
	buf = NULL;
	if (stack[0] != NULL)
	{
		buf = (int *) ft_calloc(1, sizeof(int));
		mem_error_handler(buf);
		*buf = *stack[0];
		while (stack[i + 1] != NULL)
		{
			*stack[i] = *stack[i + 1];
			i++;
		}
		free(stack[i]);
		stack[i] = NULL;
	}
	return (buf);
}

void push(int **src, int **dst, char dst_stack)
{
	int *buf;
//	int i;

	buf = pop(src);
	if (buf)
	{
		dst[stacksize(dst)] = (int *)malloc(sizeof(int));
		mem_error_handler(dst[stacksize(dst)] - 1);
		dst[stacksize(dst) + 1] = NULL;
		add_front(dst, *buf);
	}
	free(buf);
	buf = NULL;
	if (dst_stack == 'a')
		write(1, "pa\n", 3);
	else if (dst_stack == 'b')
		write(1, "pb\n", 3);
}

void	swap(int **stack, char stack_name)
{
	int buf;

	if (stack[1] != NULL)
	{
		buf = *stack[0];
		*stack[0] = *stack[1];
		*stack[1] = buf;
		if (stack_name == 'a')
			write(1, "sa\n", 3);
		else if (stack_name == 'b')
			write(1, "sb\n", 3);
	}
}

void ss(t_list *stack)
{
	swap(stack->stack_a, 'w');
	swap(stack->stack_b, 'w');
	write (1, "ss\n", 3);
}

void rotate(int **stack, char stack_name)
{
	int buf;
	int i;

	i = 0;
	if(stack[1] != NULL)
	{
		buf = *stack[0];
		while (stack[i + 1] != NULL)
		{
			*stack[i] = *stack[i + 1];
			i++;
		}
		*stack[i] = buf;
		if (stack_name == 'a')
			write(1, "ra\n", 3);
		else if (stack_name == 'b')
			write(1, "rb\n", 3);
	}
}

void rr(t_list *stack)
{
	rotate(stack->stack_a, 'w');
	rotate(stack->stack_b, 'w');
	write (1, "rr\n", 3);
}

void rev_rotate(int **stack, char stack_name)
{
	int buf;
	int i;

	if (stack[1] != NULL)
	{
		i = stacksize(stack) - 1;
		buf = *stack[i];
		add_front(stack, buf);
	}
	if (stack_name == 'a')
		write(1, "rra\n", 4);
	else if (stack_name == 'b')
		write(1, "rrb\n", 4);
}

void rrr(t_list *stack)
{
	rev_rotate(stack->stack_a, 'w');
	rev_rotate(stack->stack_b, 'w');
	write (1, "rrr\n", 4);
}