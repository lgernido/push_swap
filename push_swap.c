/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:40:03 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/11 11:21:40 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	/*1. Verifier que les arguments sont valides*/
	if (argc == 1)
		ft_error_found(&a);
	/*2. Initialiser la stack a avec les arguments*/
	ft_init_stack(&a, argv + 1);
	/*3. Trier */
	// ft_merge(&a, &b);
	// ft_init_div(&a, &b);
	// ft_descending_sort(&b);
	ft_push_swap(&a, &b);
	printf("\n");
	/*4. Renvoyer les commandes */
	while (a)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	printf("\n");
	while (b)
	{
		printf("%d\n", b->content);
		b = b->next;
	}
	return (0);
}

/*void	ft_merge(t_stack **a, t_stack **b)
{
	ft_init_div(a, b);
	ft_descending_sort(b);
	ft_ascending_sort(a);
	if ((ft_a_sorted(*a) == 1 && ft_b_sorted(*b) == 1))
	{
		while (*b)
			ft_make_pa(b, a);
	}
}*/