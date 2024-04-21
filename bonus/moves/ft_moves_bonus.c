/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:42:42 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/14 18:40:24 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
/* ********************************* MOVES ********************************* */

void	_swap(t_node **head, char *msg)
{
	t_val	tmp;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = (*head)->val;
	(*head)->val = (*head)->next->val;
	(*head)->next->val = tmp;
	ft_putstr_fd(msg, 1);
}

void	_rotate(t_node **head, char *msg)
{
	t_node	*tmp;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = NULL;
	last_node(*head)->next = tmp;
	ft_putstr_fd(msg, 1);
}

void	_revrotate(t_node **head, char *msg)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = last_node(*head);
	tmp2 = secondlast(*head);
	tmp2->next = NULL;
	tmp->next = *head;
	*head = tmp;
	ft_putstr_fd(msg, 1);
}

void	_push(t_node **a, t_node **b, char *msg)
{
	t_node	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	node2fr(a, tmp);
	ft_putstr_fd(msg, 1);
}
