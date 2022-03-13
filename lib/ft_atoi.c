/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:01:14 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/04 22:04:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check(const char *str, int *p_i, int *p_minus)
{
	if (str[*p_i] == '+' && str[*p_i + 1] > 47 && str[*p_i + 1] < 58)
		*p_i += 1;
	if (str[*p_i] == '-' && (str[*p_i + 1] > 47 && str[*p_i + 1] < 58))
	{
		*p_minus *= -1;
		*p_i += 1;
	}
}

void	error(int str)
{
	write(2, "ERROR: atoi\n", 12);
	exit(str);
}

int	ft_atoi(const char *s)
{
	int						i;
	unsigned long long int	res;
	int						minus;

	i = 0;
	minus = 1;
	res = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if ((s[i] < 48 || s[i] > 57) && (s[i] != '-' && s[i] != '+'))
		error(44);
	ft_check(s, &i, &minus);
	while (s[i] > 47 && s[i] < 58)
	{
		res = res * 10 + s[i] - 48;
		i++;
	}
	if (res == 2147483648 && minus < 0)
		return ((int)res * minus);
	if (res > 2147483647)
		error(54);
	return ((int)res * minus);
}
