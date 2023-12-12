/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:20:42 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/12 15:30:02 by lgernido         ###   ########.fr       */
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

int	ft_b_sorted(t_stack *b)
{
	if (!b)
		return (0);
	while (b->next != NULL)
	{
		if (b->content < b->next->content)
			return (0);
		b = b->next;
	}
	return (1);
}

void	ft_sort_two_three(t_stack **a)
{
	if (ft_stack_size(*a) == 2)
		ft_make_sa(*a);
	else
	{
		if (ft_find_last(*a) == ft_find_small(*a) && (*a) == ft_find_big(*a))
		{
			ft_make_sa(*a);
			ft_make_rra(a);
		}
		else if ((*a)->content == ft_find_small(*a)->content
			&& (*a)->next->content == ft_find_big(*a)->content)
		{
			ft_make_sa(*a);
			ft_make_ra(a);
		}
		else if ((*a)->content == ft_find_big(*a)->content
			&& (*a)->next->content == ft_find_small(*a)->content)
			ft_make_ra(a);
		else if ((*a)->next->content == ft_find_small(*a)->content)
			ft_make_sa(*a);
		else if (ft_find_last(*a) == ft_find_small(*a))
			ft_make_rra(a);
	}
}
void	ft_push_swap(t_stack **a, t_stack **b)
{
	while (!ft_a_sorted(*a))
	{
		if (ft_stack_size(*a) == 2 || ft_stack_size(*a) == 3)
			ft_sort_two_three(a);
		else
		{
			while (ft_stack_size(*b) < 2)
				ft_make_pb(a, b);
			while (ft_stack_size(*a) > 3)
			{
				if ((*b)->content < (*a)->content)
					ft_make_pb(a, b);
				else
					ft_make_rb(b);
			}
			ft_sort_two_three(a);
			ft_descending_sort(b);
		}
	}
}

void	ft_merge(t_stack **a, t_stack **b)
{
	ft_push_swap(a, b);
	while (ft_stack_size(*b) > 0)
	{
		if ((*b)->content > ft_find_big(*a)->content)
		{
			ft_make_pa(b, a);
			while (!ft_a_sorted(*a))
				ft_make_ra(a);
		}
		if ((*b)->content < (*a)->content)
			ft_make_pa(b, a);
		else
			ft_make_ra(a);
	}
}
