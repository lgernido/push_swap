/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:40:03 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/18 16:14:34 by lgernido         ###   ########.fr       */
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
	if (argc == 1)
		ft_error_found(&a);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_init_stack(&a, argv + 1);
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
	while (a)
	{
		printf("%d    %d    %d\n", a->content, a->pos, a->high_median);
		a = a->next;
	}
	printf("\n");
	while (b)
	{
		printf("%d    %d     %d    %d    %d    %d\n", b->content, b->pos,
			b->target->content, b->push_price, b->cheapest, b->high_median);
		b = b->next;
	}
	printf("\n");
	ft_stack_clear(&a);
	return (0);
}
