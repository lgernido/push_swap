/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:53:20 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/15 18:35:23 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pos_init(t_stack **stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = *stack;
	while (current != NULL)
	{
		current->pos = i;
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

void	ft_find_push_price(t_stack **b)
{
	int		push_price;
	t_stack	*current;

	push_price = 0;
	current = *b;
	while (current != NULL)
	{
		current->push_price = current->pos + current->target->pos;
		current = current->next;
	}
}
void	ft_find_cheapest(t_stack **b)
{
	t_stack	*current;

	current = *b;
	while (current != NULL)
	{
		if (current->push_price < current->next->push_price)
			current->cheapest = true;
		else
			current->cheapest = false;
		current = current->next;
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
