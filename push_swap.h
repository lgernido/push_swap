/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:39:56 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/01 09:19:52 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typdef struct s_list
{
	int content;
	int pos;
	struct s_list *previous;
	struct s_list *next;
}		t_list;

void	push_swap(int argc, char **argv);

/*Initialisation des stacks*/

t_list	ft_new_stack(int content, int pos, t_list *previous);
void	ft_add_stack(t_list **a, int nb);
void	ft_init_stack(t_list **a, char **argv);

/*Check et gestion des erreurs*/

int		ft_error_double(t_list *a, int nb);
int		ft_error_syntax(char **argv);
void	ft_clear_stack(t_list **a, char **argv);

/*Utilitaires*/

long	ft_atol(char *nptr);

#endif