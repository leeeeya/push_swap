/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:26:41 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/18 21:26:43 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(char *argv)
{
	t_stack	*list;

	list = (void *)malloc(sizeof (t_stack));
	if (!list)
		return (NULL);
	list -> argv = ft_strdup(argv);
	if (!list->argv)
		return (NULL);
	list -> next = NULL;
	return (list);
}
