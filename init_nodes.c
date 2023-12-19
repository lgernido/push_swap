/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:53:20 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/19 14:47:46 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pos_init(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_size(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= median)
			stack->high_median = true;
		else
			stack->high_median = false;
		stack = stack->next;
		i++;
	}
}

static void	ft_find_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	int		best_match;

	while (a)
	{
		best_match = INT_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->content < a->content
				&& current_b->content > best_match)
			{
				best_match = current_b->content;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == INT_MIN)
			a->target = ft_find_big(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	ft_find_push_price(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_stack_size(a);
	size_b = ft_stack_size(b);
	while (a)
	{
		a->push_price = a->pos;
		if (!(a->high_median))
			a->push_price = size_a - (a->pos);
		if (a->target->high_median)
			a->push_price += a->target->pos;
		else
			a->push_price += size_b - (a->target->pos);
		a = a->next;
	}
}

void	ft_find_cheapest(t_stack *stack)
{
	int		cheapest_value;
	t_stack	*cheapest_node;

	cheapest_value = INT_MAX;
	while (stack != NULL)
	{
		if (stack->push_price < cheapest_value)
		{
			cheapest_value = stack->push_price;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	ft_init_nodes_a(t_stack *a, t_stack *b)

{
	ft_pos_init(a);
	ft_pos_init(b);
	ft_find_target_a(a, b);
	ft_find_push_price(a, b);
	ft_find_cheapest(a);
}
