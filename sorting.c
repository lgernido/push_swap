/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:20:42 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/20 08:53:19 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		ft_make_rr(a, b);
	ft_pos_init(*a);
	ft_pos_init(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		ft_make_rrr(a, b);
	ft_pos_init(*a);
	ft_pos_init(*b);
}

static void	ft_divide(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_get_cheapest(*a);
	if (cheapest_node->high_median && cheapest_node->target->high_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->high_median)
		&& !(cheapest_node->target->high_median))
		rev_rotate_both(a, b, cheapest_node);
	ft_prepare_push(a, cheapest_node, 'a');
	ft_prepare_push(b, cheapest_node->target, 'b');
	ft_make_pb(a, b);
}

void	ft_push_swap(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = ft_stack_size(*a);
	if (size_a-- > 3 && !ft_a_sorted(*a))
		ft_make_pb(a, b);
	if (size_a-- > 3 && !ft_a_sorted(*a))
		ft_make_pb(a, b);
	while (size_a-- > 3 && !ft_a_sorted(*a))
	{
		ft_init_nodes_a(*a, *b);
		ft_divide(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_init_nodes_b(*a, *b);
		ft_merge(a, b);
		ft_pos_init(*a);
	}
	ft_small_top(a);
}
