/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:41:50 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/14 14:47:34 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_valid_sign(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && ft_isdigit(str[i + 1]))
		i++;
	i++;
	if (str[i] == '+' || str[i] == '-')
		return (ft_exit(2, 1, "Error\n"), 0);
	return (1);
}

bool	is_duplicated(t_node *lst)
{
	t_node	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (tmp->val.nbr == lst->val.nbr)
				return (ft_exit(2, 1, "Error\n"), 1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}
