/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:00:00 by cstefany          #+#    #+#             */
/*   Updated: 2022/03/10 12:00:03 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = init_stack(argc, argv);
	for_five(&a);
	if (ft_lstsize(a) > 5)
		big_sort(&a);
	ft_lstclear(&a, free);
	return (0);
}
