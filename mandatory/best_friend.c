/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_friend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:13:53 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/20 16:41:14 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_maxnbr(t_node *st)
{
	int	nbr;

	nbr = st->val.nbr;
	while (st)
	{
		if (nbr < st->val.nbr)
			nbr = st->val.nbr;
		st = st->next;
	}
	return (nbr);
}

static int	find_minnbr(t_node *st)
{
	int	nbr;

	nbr = st->val.nbr;
	while (st)
	{
		if (nbr > st->val.nbr)
			nbr = st->val.nbr;
		st = st->next;
	}
	return (nbr);
}

void	get_mvdata(t_movedata *mv, t_node *a, t_node *b)
{
	set_index(a, b);
	mv->cost = _mv2topcost(mv->moves_a, 1, a, mv);
	mv->cost += _mv2topcost(mv->moves_b, 0, b, mv);
}

t_movedata	find_mvs(t_node *a, t_node *b, int nbr)
{
	t_movedata	mvs;
	int			mx;
	t_node		*tmp;
	int			tp;

	mx = find_maxnbr(a);
	tmp = a;
	ft_bzero(&mvs, sizeof(t_movedata));
	mvs.moves_b = nbr;
	if (mx < nbr)
	{
		mvs.moves_a = find_minnbr(a);
		return (get_mvdata(&mvs, a, b), mvs);
	}
	while (tmp)
	{
		tp = tmp->val.nbr;
		if (tp > nbr && tp < mx)
			mx = tp;
		tmp = tmp->next;
	}
	mvs.moves_a = mx;
	return (get_mvdata(&mvs, a, b), mvs);
}

t_movedata	cal_cost(t_node *a, t_node *b)
{
	t_movedata	mv;
	t_movedata	tmp;
	t_node		*tt;

	mv = find_mvs(a, b, b->val.nbr);
	tt = b;
	while (b)
	{
		tmp = find_mvs(a, tt, b->val.nbr);
		if (mv.cost > tmp.cost)
			mv = tmp;
		b = b->next;
	}
	return (mv);
}
