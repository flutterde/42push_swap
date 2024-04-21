/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:57:53 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/20 17:03:18 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	cal_average(t_node *st)
{
	double	sum;
	double	i;

	sum = 0;
	i = 0;
	while (st)
	{
		sum += st->val.nbr;
		i++;
		st = st->next;
	}
	return (sum / i);
}
