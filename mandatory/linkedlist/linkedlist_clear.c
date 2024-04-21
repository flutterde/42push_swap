/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:05:40 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/14 17:54:25 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	delete_node(t_node *node)
{
	if (!node)
		return ;
	ft_free((void **)&node->val.str);
	node->val.str = NULL;
	ft_free((void **)&node);
}

void	free_list(t_node **head)
{
	t_node	*tmp;

	if (!head || !*head)
		return ;
	tmp = *head;
	while (tmp)
	{
		tmp = (*head)->next;
		delete_node(*head);
		*head = tmp;
	}
	*head = NULL;
}
