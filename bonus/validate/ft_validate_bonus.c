/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:07:15 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/14 21:41:23 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static int	is_one_sign(t_node *lst)
{
	char	*str;

	while (lst)
	{
		str = lst->val.str;
		if (ft_strlen(str) == 1 && (str[0] == '-' || str[0] == '+'))
			return (ft_exit(2, 1, "Error\n"), 0);
		lst = lst->next;
	}
	return (1);
}

static int	is_int_range(char *str)
{
	long	num;
	int		i;

	i = 0;
	while (str && str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (i > 1)
		return (0);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (check_valid_sign(str));
}

static int	check_is_int(t_node *lst)
{
	int		i;
	int		j;
	char	*str;

	while (lst)
	{
		j = 0;
		i = 0;
		str = lst->val.str;
		while (str[j] && (str[j] == '+' || str[j] == '-'))
			j++;
		while (str[j] && str[j] == '0')
			j++;
		while (str[j] && ft_isdigit(str[j++]))
			i++;
		if (i > 10 || !is_int_range(str))
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int	check_is_digits(t_node *lst)
{
	int		j;
	char	*str;
	t_node	*tmp;

	tmp = lst;
	while (lst)
	{
		j = 0;
		str = lst->val.str;
		while (str[j] && (ft_isdigit(str[j]) || str[j] == '-' || str[j] == '+'))
			j++;
		if (str[j])
			return (ft_exit(2, 1, "Error\n"), 0);
		lst = lst->next;
	}
	if (!is_one_sign(tmp))
		return (ft_exit(2, 1, "Error\n"), 0);
	if (!check_is_int(tmp))
		return (ft_exit(2, 1, "Error\n"),
			0);
	return (is_duplicated(tmp), 1);
}

void	ft_validate(t_node *stk)
{
	if (check_is_digits(stk))
	{
		while (stk)
		{
			free(stk->val.str);
			stk->val.str = NULL;
			stk = stk->next;
		}
	}
}
