/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:53:20 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/16 09:18:18 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pos_init(t_stack **stack)
{
	int		i;
	int		median;
	t_stack	*current;

	i = 0;
	median = ft_stack_size(*stack) / 2;
	current = *stack;
	while (current != NULL)
	{
		current->pos = i;
		if (i <= median)
			current->high_median = true;
		else
			current->high_median = false;
		current = current->next;
		i++;
	}
}
void	ft_find_target(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*current_b;
	t_stack	*target;
	int		best_match;

	current_b = *b;
	while (current_b != NULL)
	{
		best_match = INT_MAX;
		current = *a;
		while (current != NULL)
		{
			if (current->content < best_match
				&& current->content > current_b->content)
			{
				target = current;
				best_match = current->content;
			}
			current = current->next;
		}
		if (best_match == INT_MAX)
			(current_b)->target = ft_find_small(*a);
		else
			(current_b)->target = target;
		(current_b) = (current_b)->next;
	}
}

void	ft_find_push_price(t_stack **a, t_stack **b)
{
	int		size_a;
	int		size_b;
	t_stack	*current;

	size_a = ft_stack_size(*a);
	size_b = ft_stack_size(*b);
	current = *b;
	while (current != NULL)
	{
		current->push_price = current->pos;
		if (!(current->high_median))
			current->push_price = size_b - (current->pos);
		if (current->target->high_median)
			current->push_price += current->target->pos;
		else
			current->push_price += size_a - (current->target->pos);
		current = current->next;
	}
}
void	ft_find_cheapest(t_stack **b)
{
	int		cheapest_value;
	t_stack	*cheapest_node;
	t_stack	*current;

	current = *b;
	cheapest_value = INT_MAX;
	while (current != NULL)
	{
		if (current->push_price < cheapest_value)
		{
			cheapest_value = current->push_price;
			cheapest_node = current;
		}
		current = current->next;
	}
	cheapest_node->cheapest = true;
}

void	ft_init_nodes(t_stack **a, t_stack **b)
{
	ft_pos_init(a);
	ft_pos_init(b);
	ft_find_target(a, b);
	ft_find_push_price(a, b);
	ft_find_cheapest(b);
}
