/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:19:25 by lgernido          #+#    #+#             */
/*   Updated: 2023/11/30 17:00:09 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	ft_new_stack(int content, int pos, t_list *previous)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (NULL);
	a->content = content;
	a->pos = pos;
	if (pos == 1)
		a->previous = NULL;
	else
	{
		a->previous = previous;
		a->next = NULL;
	}
	b = NULL return (a);
}

void	ft_add_stack(t_list **a, t_list *new)
{
	t_list	**last;

	if (!*a)
	{
		*a = new;
		return ;
	}
	last = ft_lstlast(*a);
	last->next = new;
}

void	ft_init_stack(void)
{
}