/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:32:00 by cstefany          #+#    #+#             */
/*   Updated: 2022/01/05 19:32:04 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void arg_error_handler(int str)
{
	write(2, "ERROR: Invalid arguments\n ", 24);
	exit(str);
}

void	mem_error_handler(void *mem)
{
	if (!mem)
	{
		write(2, "ERROR: Memory allocation error\n", 31);
		exit(12);
	}
}