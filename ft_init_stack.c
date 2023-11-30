/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:19:25 by lgernido          #+#    #+#             */
/*   Updated: 2023/11/30 14:19:04 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	ft_new_stack(int content, int pos)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (NULL);
	a->content = content;
	a->pos = pos;
	a->previous = NULL;
	a->next = NULL;
	return (a);
}

void	ft_add_stack(int content, int pos, t_list **a, t_list *previous)
{
	t_list	*next_a;

	if (!a)
	{
		*a = next_a;
		return ;
	}
	next_a = malloc(sizeof(t_list));
	if (!next_a)
		return ;
	next_a->content = content;
	next_a->pos = pos;
	next_a->previous = previous;
	next_a->next = NULL;
	return (next_a);
}

void	ft_init_stack(int content, int pos)
{
	t_list *a;
	t_list *b;

	if (pos == 1)
		a = ft_new_stack(content, pos);
	else
		a = ft_add_stack(content, pos, a, a[pos - 1]);
	b = NULL;
}