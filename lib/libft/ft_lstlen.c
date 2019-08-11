/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 21:18:17 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/19 21:18:19 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list **alst)
{
	int		i;
	t_list	*point;

	i = 0;
	point = *alst;
	while (point->next != NULL)
	{
		point = point->next;
		i++;
	}
	return (i);
}
