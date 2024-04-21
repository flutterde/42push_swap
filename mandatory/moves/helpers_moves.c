/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:48:19 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/05 20:51:09 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_rr(t_node **a, t_node **b, bool isrev, char *msg)
{
	if (isrev)
	{
		_revrotate(a, "");
		_revrotate(b, "");
		ft_putstr_fd(msg, 1);
		return ;
	}
	_rotate(a, "");
	_rotate(b, "");
	ft_putstr_fd(msg, 1);
}

void	_ss(t_node **a, t_node **b, char *msg)
{
	_swap(a, "");
	_swap(b, "");
	ft_putstr_fd(msg, 1);
}
