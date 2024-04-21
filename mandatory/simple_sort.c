/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:53:18 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/14 19:03:46 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_sort3(t_node **a)
{
	t_node	*last;
	t_node	*second;

	last = last_node(*a);
	second = (*a)->next;
	if (!a || !*a || !second || !last)
		return (true);
	if (is_sorted(*a))
		return (true);
	else if ((*a)->val.nbr > second->val.nbr && (*a)->val.nbr > last->val.nbr)
	{
		_rotate(a, "ra\n");
		if (!is_sorted(*a))
			return (_swap(a, "sa\n"), true);
	}
	else if ((*a)->val.nbr < second->val.nbr && (*a)->val.nbr > last->val.nbr)
		return (_revrotate(a, "rra\n"), true);
	else if ((*a)->val.nbr < second->val.nbr && (*a)->val.nbr < last->val.nbr)
		return (_revrotate(a, "rra\n"), _swap(a, "sa\n"), true);
	else
		return (_swap(a, "sa\n"), true);
	return (true);
}

void	pushback2a(t_node **a, t_node **b, int n)
{
	int	i;

	i = -1;
	if (!a || !b)
		return ;
	while (++i < n)
		_push(a, b, "pa\n");
}

void	push_smallest2b(t_node **a, t_node **b)
{
	t_node	*sm;
	int		i;

	sm = smallest_node(*a);
	i = get_smallnbr_index(*a);
	while (*a != sm)
	{
		if (i <= 2)
			_rotate(a, "ra\n");
		else
			_revrotate(a, "rra\n");
	}
	_push(b, a, "pb\n");
	sm = smallest_node(*a);
	i = get_smallnbr_index(*a);
	while (*a != sm)
	{
		if (i <= 1)
			_rotate(a, "ra\n");
		else
			_revrotate(a, "rra\n");
	}
	_push(b, a, "pb\n");
}

bool	ft_sort5(t_node **a, t_node **b)
{
	if (!a || !*a || !b)
		return (true);
	if (is_sorted(*a))
		return (true);
	push_smallest2b(a, b);
	ft_sort3(a);
	pushback2a(a, b, 2);
	return (true);
}

void	simple_sort(t_node **a, t_node **b)
{
	t_node	*sm;

	if (list_size(*a) == 5)
		ft_sort5(a, b);
	else if (list_size(*a) == 4)
	{
		sm = smallest_node(*a);
		while (*a != sm)
			_rotate(a, "ra\n");
		if (*a == sm)
			_push(b, a, "pb\n");
		ft_sort3(a);
		_push(a, b, "pa\n");
	}
	else if (list_size(*a) == 3)
		ft_sort3(a);
	else if (list_size(*a) == 2 && !is_sorted(*a))
		_swap(a, "sa\n");
}
