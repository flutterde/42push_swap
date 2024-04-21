/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:05:58 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/20 16:29:28 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	store_inlst(t_node **a, char **sp)
{
	int		i;
	t_val	val;

	i = -1;
	while (sp && sp[++i])
	{
		val.nbr = ft_atoi(sp[i]);
		val.str = sp[i];
		val.index = 0;
		node2end(a, create_node(val));
	}
}

static void	_handle_sort(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
	{
		free_list(a);
		return ;
	}
	if (list_size(*a) <= 5)
	{
		simple_sort(a, &b);
		free_list(a);
		return ;
	}
	ft_algo1st(a, &b);
	while (list_size(b))
		putnbrs_up(a, &b);
	_fsort(a);
	free_list(a);
}

void	_handler(int ac, char **av)
{
	char	**split;
	t_node	*st_a;
	int		i;

	st_a = NULL;
	i = 0;
	while (++i < ac)
	{
		split = split_w(av[i]);
		if (!ft_split_size(split))
			ft_exit(2, 1, "Error\n");
		store_inlst(&st_a, split);
		free(split);
	}
	ft_validate(st_a);
	_handle_sort(&st_a);
}
