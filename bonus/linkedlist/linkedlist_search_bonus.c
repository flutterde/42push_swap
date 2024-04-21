/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_search_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:05:57 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/14 18:39:03 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

t_node	*smallest_node(t_node *a)
{
	t_node	*sm;

	sm = a;
	while (a->next)
	{
		if (sm->val.nbr > a->next->val.nbr)
			sm = a->next;
		a = a->next;
	}
	return (sm);
}

t_node	*last_node(t_node *head)
{
	t_node	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_node	*secondlast(t_node *head)
{
	t_node	*tmp;

	if (!head || !head->next)
		return (NULL);
	tmp = head;
	while (tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}

size_t	list_size(t_node *head)
{
	size_t	i;

	i = 0;
	if (!head)
		return (0);
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
