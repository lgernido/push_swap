/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 08:03:19 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/02 09:46:34 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Chaque fonction execute une commande comme decrite dans le sujet.
Ici, 4 commande donc 4 fonctions (swap, push, rotate et reverse rotate).
La 5eme fonction appelle les commandes sur les differentes stacks et les nomment
conformement au sujet*/

void	ft_swap(t_stack *stack)
{
	int	size;
	int	tmp;

	size = ft_stack_size(stack);
	if (size == 1 || !stack)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	ft_push(t_stack *from, t_stack *to)
{
	t_stack *tmp;

	if (!from)
		return ;
	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
}