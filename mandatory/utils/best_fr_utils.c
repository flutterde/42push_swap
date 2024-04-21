/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_fr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:42:52 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/20 16:54:58 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	putnbrs_up(t_node **a, t_node **b)
{
	t_movedata	mv;

	mv = cal_cost(*a, *b);
	set_sizes(*a, *b, &mv);
	if (mv.a_idx <= (mv.a_size / 2) && mv.b_idx <= (mv.b_size / 2))
		while (mv.a_idx != (*a)->val.index && mv.b_idx != (*b)->val.index)
			_rr(a, b, false, "rr\n");
	else if (mv.a_idx > (mv.a_size / 2) && mv.b_idx > (mv.b_size / 2))
		while (mv.a_idx != (*a)->val.index && mv.b_idx != (*b)->val.index)
			_rr(a, b, true, "rrr\n");
	while (mv.a_idx != (*a)->val.index)
	{
		if (mv.a_idx <= (mv.a_size / 2))
			_rotate(a, "ra\n");
		else
			_revrotate(a, "rra\n");
	}
	while (mv.b_idx != (*b)->val.index)
	{
		if (mv.b_idx <= (mv.b_size / 2))
			_rotate(b, "rb\n");
		else
			_revrotate(b, "rrb\n");
	}
	_push(a, b, "pa\n");
}

void	set_index(t_node *a, t_node *b)
{
	int	i;

	i = 0;
	while (a)
	{
		a->val.index = i++;
		a = a->next;
	}
	i = 0;
	while (b)
	{
		b->val.index = i++;
		b = b->next;
	}
}

static int	get_max_nbr(t_node *a)
{
	int	mx;

	mx = INT_MIN;
	while (a)
	{
		if (a->val.nbr > mx)
			mx = a->val.nbr;
		a = a->next;
	}
	return (mx);
}

int	get_max_index(t_node *a)
{
	int	mx;

	set_index(a, NULL);
	mx = get_max_nbr(a);
	while (a)
	{
		if (a->val.nbr == mx)
			return (a->val.index);
		a = a->next;
	}
	return (-1);
}

void	_fsort(t_node **a)
{
	int		mx_i;
	int		size;

	mx_i = get_max_index(*a);
	size = list_size(*a);
	while (!is_sorted(*a))
	{
		if (mx_i <= size / 2)
			_rotate(a, "ra\n");
		else
			_revrotate(a, "rra\n");
	}
}
