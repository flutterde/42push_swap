/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:01:07 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/21 20:08:16 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_val{
	int		nbr;
	int		index;
	char	*str;
}	t_val;

typedef struct s_movedata
{
	int	moves_a;
	int	moves_b;
	int	cost;
	int	a_idx;
	int	b_idx;
	int	a_size;
	int	b_size;
}	t_movedata;

typedef struct s_node
{
	t_val			val;
	struct s_node	*next;
}	t_node;

/* UTILS */
char		**split_w(char const *s);
void		ft_free(void **ptr);
void		ft_exit(int fd, int status, char *msg);
/* HANDLERS */
void		_handler(int ac, char **av);
/* LINKEDLIST */
t_node		*create_node(t_val data);
void		node2fr(t_node **head, t_node *new);
t_node		*last_node(t_node *head);
t_node		*secondlast(t_node *head);
void		node2end(t_node **head, t_node *new);
void		delete_node(t_node *node);
void		free_list(t_node **head);
size_t		list_size(t_node *head);
t_node		*smallest_node(t_node *a);
void		print_list(t_node *head);
/* MOVES */
void		_swap(t_node **head, char *msg);
void		_rotate(t_node **head, char *msg);
void		_revrotate(t_node **head, char *msg);
void		_push(t_node **to, t_node **from, char *msg);
void		_rr(t_node **a, t_node **b, bool isrev, char *msg);
void		_ss(t_node **a, t_node **b, char *msg);
/* CHECK */
bool		is_sorted(t_node *st);
bool		is_sorted_inv(t_node *st);
/* SORT ALGOS */
double		cal_average(t_node *st);
void		ft_algo1st(t_node **st_a, t_node **st_b);
bool		ft_sort3(t_node **a);
bool		ft_sort5(t_node **a, t_node **b);
void		push_smallest2b(t_node **a, t_node **b);
void		pushback2a(t_node **a, t_node **b, int n);
t_movedata	cal_cost(t_node *a, t_node *b);
void		putnbrs_up(t_node **a, t_node **b);
void		_fsort(t_node **a);
void		simple_sort(t_node **a, t_node **b);
void		set_index(t_node *a, t_node *b);
int			get_smallnbr_index(t_node *a);
int			_mv2topcost(int nbr, int n, t_node *st, t_movedata *m);
void		set_sizes(t_node *a, t_node *b, t_movedata *mv);
/* VALIDATE DATA */
int			check_valid_sign(char *str);
bool		is_duplicated(t_node *lst);
void		ft_validate(t_node *stk);

#endif