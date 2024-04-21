/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:37:40 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/14 15:50:43 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_smallnbr_index(t_node *a)
{
	int	mn;
	int	i;

	mn = INT_MAX;
	i = 0;
	set_index(a, NULL);
	while (a)
	{
		if (a->val.nbr < mn)
		{
			mn = a->val.nbr;
			i = a->val.index;
		}
		a = a->next;
	}
	return (i);
}
