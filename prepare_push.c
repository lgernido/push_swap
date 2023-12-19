/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:55:46 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/19 16:05:13 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_a_sorted(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = ft_find_big(*a);
	if (*a == biggest)
		ft_make_ra(a);
	else if ((*a)->next == biggest)
		ft_make_rra(a);
	if ((*a)->content > (*a)->next->content)
		ft_make_sa(*a);
}

t_stack	*ft_get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		else
			stack = stack->next;
	}
	return (NULL);
}

void	ft_small_top(t_stack **a)
{
	while ((*a)->content != ft_find_small(*a)->content)
	{
		if (ft_find_small(*a)->high_median)
			ft_make_ra(a);
		else
			ft_make_rra(a);
	}
}

void	ft_prepare_push(t_stack **stack, t_stack *cheapest, char stack_name)
{
	while (*stack != cheapest)
	{
		if (stack_name == 'a')
		{
			if (cheapest->high_median)
				ft_make_ra(stack);
			else
				ft_make_rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (cheapest->high_median)
				ft_make_rb(stack);
			else
				ft_make_rrb(stack);
		}
	}
}
