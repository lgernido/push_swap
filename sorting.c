/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:20:42 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/14 09:29:26 by lgernido         ###   ########.fr       */
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
void	ft_prepare_push(t_stack **a, t_stack **b)
{
	while (*b)
	{
		if (b->cheapest = true && b->pos == b->target->pos)
		{
			while (b->previous != NULL)
			{
				if (b->high_median == true)
					ft_make_rr(a, b);
				else
					ft_make_rrr(a, b);
			}
		}
	}
}

void	ft_push_swap(t_stack **a, t_stack **b)
{
	while (!ft_a_sorted(*a))
	{
		while (ft_stack_size(*b) < 2)
			ft_make_pb(a, b);
		while (ft_stack_size(*a) > 3)
			ft_make_pb(a, b);
		ft_sort_three(a);
		ft_init_nodes(a, b);
	}
}