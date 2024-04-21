/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_clear_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:05:40 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/14 18:39:00 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	delete_node(t_node *node)
{
	if (!node)
		return ;
	ft_free((void **)&node->val.str);
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
