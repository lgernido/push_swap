/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:16:01 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/19 16:29:20 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Effectue une rotation de la stack , le premier element devient le dernier*/

void	ft_rotate(t_stack **stack)
{
	t_stack	*last;
	int		size;

	size = ft_stack_size(*stack);
	if (size == 1 || size == 0 || !stack)
		return ;
	last = ft_find_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
}

void	ft_make_ra(t_stack **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_make_rb(t_stack **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	ft_make_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
