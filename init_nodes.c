/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciegernidos <luciegernidos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:53:20 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/14 18:42:17 by luciegernid      ###   ########.fr       */
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
	t_stack	*current_a;
	t_stack	*target;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = *a;
		while (current_a)
		{
			if (current_a->content > (*b)->content
				&& current_a->content < best_match_index)
			{
				best_match_index = current_a->content;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			(*b)->target = find_smallest(a);
		else
			(*b)->target = target;
		b = (*b)->next;
	}
	/*t_stack	*target;
	t_stack	*current;

	target = *a;
	current = *a;
	while (current != NULL)
	{
		if (current->content < target->content
			&& current->content > (*b)->content)
			target = current;
		else if ((*b)->content > ft_find_big(*a)->content)
		{
			(*b)->target = ft_find_small(*a);
			return ;
		}
		current = current->next;
	}
	(*b)->target = target;*/
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
