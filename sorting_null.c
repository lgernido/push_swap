/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:53:55 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/12 14:37:53 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Sur la stack b,
	trier dans l'ordre decroissant pour pouvoir push sur a par la suite*/
void	ft_descending_sort(t_stack **b)
{
	t_stack	*last;

	while (!ft_b_sorted(*b))
	{
		last = ft_find_last(*b);
		if ((*b)->content < (*b)->next->content)
			ft_make_sb(*b);
		else
		{
			while (last->content > (*b)->content)
				ft_make_rrb(b);
		}
	}
}

/*Diviser la stack a en mettant toutes les valeurs plus petites que pivot dans b*/
/*void	ft_init_div(t_stack **a, t_stack **b)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	pivot = (*a)->content;
	while ((*a)->next != NULL)
	{
		if ((*a)->content <= pivot)
			ft_make_pb(a, b);
		else
		{
			ft_make_ra(a);
			*a = (*a)->next;
		}
	}
}*/