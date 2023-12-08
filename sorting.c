/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:53:55 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/08 18:58:55 by lgernido         ###   ########.fr       */
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
/*Diviser la stack a en mettant toutes les valeurs plus petites que pivot dans b*/
void	ft_init_div(t_stack **a, t_stack **b)
{
	int	pivot;

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
}

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
		else if (last->content > (*b)->content)
			ft_make_rrb(b);
		else
			ft_make_rb(b);
	}
}

/*Sur la stack a, directement trier dans l'ordre croissant*/

void	ft_ascending_sort(t_stack **a)
{
	t_stack	*last;

	while (!ft_a_sorted(*a))
	{
		last = ft_find_last(*a);
		if ((*a)->content > (*a)->next->content)
			ft_make_sa(*a);
		else if (last->content < (*a)->content)
			ft_make_ra(a);
		else
			ft_make_rra(a);
	}
}
