/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:59:49 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/05 20:29:58 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_node(t_val data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->val = data;
	new->next = NULL;
	return (new);
}

void	node2fr(t_node **head, t_node *new)
{
	if (!head || !new)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	new->next = *head;
	*head = new;
}

void	node2end(t_node **head, t_node *new)
{
	t_node	*last;

	last = last_node(*head);
	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	last->next = new;
	new->next = NULL;
}

void	print_list(t_node *head)
{
	if (!head)
		return ;
	while (head)
	{
		ft_printf("NBR: %d , INDEX: %d STRING: %s. \n", 
			head->val.nbr, head->val.index, head->val.str);
		head = head->next;
	}
}
