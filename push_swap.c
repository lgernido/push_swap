/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:40:03 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/15 12:31:03 by lgernido         ###   ########.fr       */
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
	/*else if (argc == 2)
		argv = ft_split(argv[1], ' ');*/
	/*2. Initialiser la stack a avec les arguments*/
	ft_init_stack(&a, argv + 1);
	/*3. Trier */
	if (!ft_a_sorted(a))
	{
		if (ft_stack_size(a) == 2)
			ft_make_sa(a);
		else if (ft_stack_size(a) == 3)
			ft_sort_three(&a);
		else
			ft_push_swap(&a, &b);
	}
	printf("\n");
	/*4. Renvoyer les commandes */
	while (a)
	{
		printf("%d    %d\n", a->content, a->pos);
		a = a->next;
	}
	printf("\n");
	while (b)
	{
		printf("%d    %d     %d    %d\n", b->content, b->pos,
			b->target->content, b->push_price);
		b = b->next;
	}
	printf("\n");
	return (0);
}
