/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:46:30 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/06 00:55:32 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo1st(t_node **st_a, t_node **st_b)
{
	double	avg;

	while (*st_a && (list_size(*st_a) > 5))
	{
		avg = cal_average(*st_a);
		if ((double)((*st_a)->val.nbr) <= avg)
			_push(st_b, st_a, "pb\n");
		else
			_rotate(st_a, "ra\n");
	}
	ft_sort5(st_a, st_b);
}
