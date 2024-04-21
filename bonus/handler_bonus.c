/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:05:58 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/14 22:40:15 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static void	check_str(t_node **a, t_node **b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		_swap(a, "");
	else if (!ft_strncmp(str, "sb\n", 3))
		_swap(b, "");
	else if (!ft_strncmp(str, "ss\n", 3))
		_ss(a, b, "");
	else if (!ft_strncmp(str, "pa\n", 3))
		_push(a, b, "");
	else if (!ft_strncmp(str, "pb\n", 3))
		_push(b, a, "");
	else if (!ft_strncmp(str, "ra\n", 3))
		_rotate(a, "");
	else if (!ft_strncmp(str, "rb\n", 3))
		_rotate(b, "");
	else if (!ft_strncmp(str, "rr\n", 3))
		_rr(a, b, false, "");
	else if (!ft_strncmp(str, "rrr\n", 4))
		_rr(a, b, true, "");
	else if (!ft_strncmp(str, "rra\n", 4))
		_revrotate(a, "");
	else if (!ft_strncmp(str, "rrb\n", 4))
		_revrotate(b, "");
	else
		ft_exit(2, 1, "Error\n");
}

static void	_handle_check(t_node **a)
{
	t_node	*b;
	char	*str;

	b = NULL;
	str = get_next_line(0);
	while (str)
	{
		check_str(a, &b, str);
		free(str);
		str = get_next_line(0);
	}
	if (!list_size(b) && is_sorted(*a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_list(a);
	free_list(&b);
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
	_handle_check(&st_a);
}
