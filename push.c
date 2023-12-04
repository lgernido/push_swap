/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:12:17 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/04 11:15:34 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **from, t_stack **to)
{
	if (!from || !(*from))
		return ;
	*from = (*from)->next;
	if (*from)
	{
		(*from)->previous = NULL;
		if (!to || !(*to))
		{
			*to = *from;
			(*from)->next = NULL;
		}
		else
		{
			(*from)->next = *to;
			(*from)->next->previous = *from;
			*to = *from;
		}
	}
}

void	ft_make_pa(t_stack **b, t_stack **a)
{
	ft_push(b, a);
	write(1, "pa\n", 3);
}

void	ft_make_pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	write(1, "pb\n", 3);
}