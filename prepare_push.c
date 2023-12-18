/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:55:46 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/18 16:28:14 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_a(t_stack **a, t_stack *cheapest, int rounds)
{
	int	i;

	i = 0;
	while (i < rounds)
	{
		if (cheapest->target->high_median == true)
			ft_make_ra(a);
		else
			ft_make_rra(a);
		i++;
	}
}
void	ft_move_b(t_stack **b, t_stack *cheapest, int rounds)
{
	int	i;

	i = 0;
	while (i < rounds)
	{
		if (cheapest->high_median == true)
			ft_make_rb(b);
		else
			ft_make_rrb(b);
		i++;
	}
}

void	ft_prepare_push_sequel(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	rounds_a;
	int	rounds_b;

	if (cheapest->target->high_median == true)
		rounds_a = cheapest->target->pos;
	else
		rounds_a = cheapest->push_price;
	if (cheapest->high_median == true)
		rounds_b = cheapest->pos;
	else
		rounds_b = cheapest->push_price - rounds_a;
	ft_move_a(a, cheapest, rounds_a);
	ft_move_b(b, cheapest, rounds_b);
}

void	ft_prepare_push(t_stack **a, t_stack **b)
{
	t_stack	*current;

	current = (*b);
	while (current->cheapest != true)
		current = current->next;
	while ((*a) != (*b)->target)
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
