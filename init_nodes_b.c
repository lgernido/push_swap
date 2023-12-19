/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:39:35 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/19 16:08:37 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_merge(t_stack **a, t_stack **b)
{
	ft_prepare_push(a, (*b)->target, 'a');
	ft_make_pa(b, a);
}

static void	ft_find_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match;

	while (b)
	{
		best_match = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->content > b->content
				&& current_a->content < best_match)
			{
				best_match = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == INT_MAX)
			b->target = ft_find_small(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	ft_init_nodes_b(t_stack *a, t_stack *b)
{
	ft_pos_init(a);
	ft_pos_init(b);
	ft_find_target_b(a, b);
}