//
// Created by Claribel Stefany on 1/15/22.
//

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "./lib/libft.h"

typedef struct s_struct
{
	int	**stack_a;
	int	**stack_b;
}	t_struct;

t_struct	check_arguments(int argc, char **argv);
void	arg_error_handler(int str);
void	mem_error_handler(void *mem);
int		main(int argc, char **argv);
void	swap(int **stack, char stack_name);
void	ss(t_struct *stack);
int		stacksize(int **stack);
int		*pop(int **stack);
void	push(int **src, int **dst, char dst_stack);
void	rotate(int **stack, char stack_name);
void	rr(t_struct *stack);
void	rev_rotate(int **stack, char stack_name);
void	rrr(t_struct *stack);
void	for_five(t_struct stack);
void	for_three(int **stack_a);
int		check_sorted_a (int ** stack_a);
int		search_max (int **stack);
void 	big_sort(t_struct stack);
#endif //PUSH_SWAP_H
