/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:39:56 by lgernido          #+#    #+#             */
/*   Updated: 2023/11/30 14:36:33 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typdef struct s_list
{
	int content;
	int pos;
	struct s_list *previous;
	struct s_list *next;
}			t_list;

t_list	ft_new_stack(int content, int pos);
void	ft_add_stack(int content, int pos, t_list **a, t_list *previous);
void	ft_init_stack(int content, int pos);
void	push_swap(int argc, char **argv);

#endif