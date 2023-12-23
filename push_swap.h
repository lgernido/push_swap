/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciegernidos <luciegernidos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:39:56 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/23 16:29:58 by luciegernid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				pos;
	int				push_price;
	bool			cheapest;
	bool			high_median;
	struct s_stack	*target;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

int					main(int argc, char **argv);

/*Initialisation des stacks*/

void				ft_add_stack(t_stack **a, int nb);
void				ft_init_stack(t_stack **a, char **argv);

/*Check et gestion des erreurs*/

int					ft_error_double(t_stack *a, int nb);
int					ft_error_syntax(char *argv);
void				ft_error_found(t_stack **a);
void				ft_stack_clear(t_stack **a);

/*Instructions*/

void				ft_swap(t_stack *stack);
void				ft_push(t_stack **from, t_stack **to);
void				ft_rotate(t_stack **stack);
void				ft_reverse_rotate(t_stack **stack);

/*Affichage instructions*/

void				ft_make_sa(t_stack *a);
void				ft_make_sb(t_stack *b);
void				ft_make_ss(t_stack *a, t_stack *b);
void				ft_make_pa(t_stack **b, t_stack **a);
void				ft_make_pb(t_stack **a, t_stack **b);
void				ft_make_ra(t_stack **a);
void				ft_make_rb(t_stack **b);
void				ft_make_rr(t_stack **a, t_stack **b);
void				ft_make_rra(t_stack **a);
void				ft_make_rrb(t_stack **b);
void				ft_make_rrr(t_stack **a, t_stack **b);

/*Utilitaires*/

long				ft_atol(char *nptr);
int					ft_stack_size(t_stack *a);
void				free_split(char **split_array);
char				**ft_split(char *s, char c);
t_stack				*ft_find_big(t_stack *a);
t_stack				*ft_find_small(t_stack *a);
t_stack				*ft_find_last(t_stack *a);
void				ft_small_top(t_stack **a);
size_t				ft_strlen(char *str);

/*Initialisation des elements de chaque node*/

void				ft_pos_init(t_stack *stack);
void				ft_find_cheapest(t_stack *stack);
void				ft_init_nodes_a(t_stack *a, t_stack *b);
void				ft_init_nodes_b(t_stack *a, t_stack *b);

/*Algorithme de tri*/

int					ft_a_sorted(t_stack *a);
void				ft_sort_three(t_stack **a);
t_stack				*ft_get_cheapest(t_stack *stack);
void				ft_merge(t_stack **a, t_stack **b);
void				ft_prepare_push(t_stack **stack, t_stack *cheapest,
						char stack_name);
void				ft_push_swap(t_stack **a, t_stack **b);
#endif