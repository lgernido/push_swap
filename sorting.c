/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:20:42 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/15 12:31:22 by lgernido         ###   ########.fr       */
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
	while ((*b)->cheapest == false)
		(*b) = (*b)->next;
	while ((*b)->target->previous != NULL && (*b)->previous != NULL)
	{
		if ((*b)->target->high_median == true && (*b)->high_median == true)
			ft_make_rr(a, b);
		else if ((*b)->target->high_median == false
			&& (*b)->high_median == false)
			ft_make_rrr(a, b);
		else if ((*b)->target->high_median == true
			&& (*b)->high_median == false)
		{
			ft_make_ra(a);
			ft_make_rrb(b);
		}
		else if ((*b)->target->high_median == false
			&& (*b)->high_median == true)
		{
			ft_make_rra(a);
			ft_make_rrb(b);
		}
	}
}
void	ft_push_swap(t_stack **a, t_stack **b)
{
	/*t_stack	*smallest;
	smallest = ft_find_small(*a);*/
	while (ft_stack_size(*b) < 2)
		ft_make_pb(a, b);
	while (ft_stack_size(*a) > 3)
		ft_make_pb(a, b);
	ft_sort_three(a);
	ft_pos_init(a);
	ft_pos_init(b);
	ft_find_target(a, b);
	ft_find_push_price(b);
	/*ft_init_nodes(a, b);
	if (b == NULL)
	{
		while (smallest->previous != NULL)
		{
			if (smallest->high_median == true)
				ft_make_ra(a);
			else
				ft_make_rra(a);
		}
	}
	ft_prepare_push(a, b);
	ft_make_pa(b, a);
	*/
}
