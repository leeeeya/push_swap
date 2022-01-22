//
// Created by Claribel Stefany on 1/15/22.
//

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "./lib/libft.h"

typedef struct s_list
{
	int	**stack_a;
	int	**stack_b;
}	t_list;

t_list	check_arguments(int argc, char **argv);
void	arg_error_handler(int str);
void	mem_error_handler(void *mem);
int		main(int argc, char **argv);
void	swap(int **stack, char stack_name);
void	ss(t_list *stack);
int		stacksize(int **stack);
int		*pop(int **stack);
void	push(int **src, int **dst, char dst_stack);
void	rotate(int **stack, char stack_name);
void	rr(t_list *stack);
void	rev_rotate(int **stack, char stack_name);
void	rrr(t_list *stack);
#endif //PUSH_SWAP_H
