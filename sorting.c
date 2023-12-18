/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:20:42 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/18 13:33:01 by lgernido         ###   ########.fr       */
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

void	ft_push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

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
	smallest = ft_find_small(*a);
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
