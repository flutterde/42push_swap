/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:40:18 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/20 16:56:06 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	_mv2topcost(int nbr, int n, t_node *st, t_movedata *m)
{
	int	i;
	int	size;

	size = list_size(st);
	i = 0;
	while (st)
	{
		if (st->val.nbr == nbr)
		{
			i = st->val.index;
			if (n == 1)
				m->a_idx = i;
			else
				m->b_idx = i;
			break ;
		}
		st = st->next;
	}
	if (i <= (size / 2))
		return (i);
	return (size - i);
}

void	set_sizes(t_node *a, t_node *b, t_movedata *mv)
{
	mv->a_size = list_size(a);
	mv->b_size = list_size(b);
}
