/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:00:13 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/14 15:48:47 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* in this files the functions that check my stack if it's sorted or not */
bool	is_sorted(t_node *st)
{
	t_node	*tmp;

	tmp = st;
	if (!st)
		return (true);
	while (tmp->next)
	{
		if (tmp->val.nbr > tmp->next->val.nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	is_sorted_inv(t_node *st)
{
	t_node	*tmp;

	tmp = st;
	if (!st)
		return (true);
	while (tmp->next)
	{
		if (tmp->val.nbr < tmp->next->val.nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
