/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:20:42 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/16 12:35:02 by lgernido         ###   ########.fr       */
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

void	ft_prepare_push_sequel(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->target->high_median == true && cheapest->high_median == true)
		ft_make_rr(a, b);
	else if (cheapest->target->high_median == false
		&& cheapest->high_median == false)
		ft_make_rrr(a, b);
	else if (cheapest->target->high_median == true
		&& cheapest->high_median == false)
	{
		ft_make_ra(a);
		ft_make_rrb(b);
	}
	else if (cheapest->target->high_median == false
		&& cheapest->high_median == true)
	{
		ft_make_rb(b);
		ft_make_rra(a);
	}
}

void	ft_prepare_push(t_stack **a, t_stack **b)
{
	while ((*b)->cheapest == false)
		(*b) = (*b)->next;
	while ((*b)->pos != 0 && (*a) != (*b)->target)
	{
		if ((*b)->pos == 0 && (*b)->target->pos != 0)
		{
			if ((*b)->target->high_median == false)
				ft_make_rra(a);
			else
				ft_make_ra(a);
		}
		else if ((*b)->target->pos == 0 && (*b)->pos != 0)
		{
			if ((*b)->high_median == false)
				ft_make_rrb(b);
			else
				ft_make_rb(b);
		}
		else
			ft_prepare_push_sequel(a, b, (*b));
	}
}

void	ft_push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

	smallest = ft_find_small(*a);
	while (ft_stack_size(*b) < 2)
		ft_make_pb(a, b);
	while (ft_stack_size(*a) > 3)
		ft_make_pb(a, b);
	ft_sort_three(a);
	while ((*b) != NULL)
	{
		ft_init_nodes(a, b);
		ft_prepare_push(a, b);
		ft_make_pa(b, a);
	}
	if ((*b) == NULL)
	{
		while (smallest->previous != NULL)
		{
			if (smallest->high_median == true)
				ft_make_ra(a);
			else
				ft_make_rra(a);
		}
	}
}
