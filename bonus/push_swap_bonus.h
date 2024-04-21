/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:01:07 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/21 20:07:59 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"

typedef struct s_val{
	int		nbr;
	int		index;
	char	*str;
}	t_val;

typedef struct s_node
{
	t_val			val;
	struct s_node	*next;
}	t_node;

/* UTILS */
char	**split_w(char const *s);
void	ft_free(void **ptr);
void	ft_exit(int fd, int status, char *msg);
/* HANDLERS */
void	_handler(int ac, char **av);
/* LINKEDLIST */
t_node	*create_node(t_val data);
void	node2fr(t_node **head, t_node *new);
t_node	*last_node(t_node *head);
t_node	*secondlast(t_node *head);
void	node2end(t_node **head, t_node *new);
void	delete_node(t_node *node);
void	free_list(t_node **head);
size_t	list_size(t_node *head);
t_node	*smallest_node(t_node *a);
void	print_list(t_node *head);
/* MOVES */
void	_swap(t_node **head, char *msg);
void	_rotate(t_node **head, char *msg);
void	_revrotate(t_node **head, char *msg);
void	_push(t_node **to, t_node **from, char *msg);
void	_rr(t_node **a, t_node **b, bool isrev, char *msg);
void	_ss(t_node **a, t_node **b, char *msg);
/* CHECK */
bool	is_sorted(t_node *st);
/* VALIDATE DATA */
int		check_valid_sign(char *str);
bool	is_duplicated(t_node *lst);
void	ft_validate(t_node *stk);

#endif