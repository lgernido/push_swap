/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:10:17 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/08 08:10:32 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	size;
	int	tmp;

	size = ft_stack_size(stack);
	if (size == 1 || size == 0 || !stack)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	stack->next->previous = NULL;
	stack->previous = stack->next;
}

void	ft_make_sa(t_stack *a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_make_sb(t_stack *b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ft_make_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}