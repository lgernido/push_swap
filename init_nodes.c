/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:53:20 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/14 10:42:02 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pos_init(t_stack **stack)
{
	int	pos;

	pos = 0;
	while (*stack)
	{
		(*stack)->pos = pos;
		(*stack) = (*stack)->next;
	}
}
void	ft_find_target(t_stack **a, t_stack **b)
{
	t_stack	*target;

	target = *a;
	while ((*a)->next != NULL)
	{
		if ((*b)->content < (*a)->content && (*a)->content < target->content)
			target = *a;
		else if (ft_find_big(*b)->content > ft_find_big(*a)->content)
		{
			(*b)->target = ft_find_small(*a);
			break ;
		}
		(*a) = (*a)->next;
	}
	(*b)->target = target;
}

void	ft_find_push_price(t_stack **b)
{
	int	push_price;

	push_price = 0;
	while (*b)
	{
		(*b)->push_price = (*b)->pos + (*b)->target->pos;
		(*b) = (*b)->next;
	}
}
void	ft_find_cheapest(t_stack **b)
{
	while (*b)
	{
		if ((*b)->push_price < (*b)->next->push_price)
			(*b)->cheapest = true;
		else
			(*b)->cheapest = false;
		(*b) = (*b)->next;
	}
}

void	ft_init_median(t_stack **stack)
{
	int	median;

	median = ft_stack_size(*stack) / 2;
	while (*stack)
	{
		if ((*stack)->pos > median)
			(*stack)->high_median = true;
		else
			(*stack)->high_median = false;
	}
}
void	ft_init_nodes(t_stack **a, t_stack **b)
{
	ft_find_target(a, b);
	ft_pos_init(a);
	ft_pos_init(b);
	ft_init_median(a);
	ft_init_median(b);
	ft_find_push_price(b);
	ft_find_cheapest(b);
}
