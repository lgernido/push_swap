/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:40:03 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/02 08:42:45 by lgernido         ###   ########.fr       */
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
	ft_swap(a);
	while (a)
	{
		printf("%d. %d\n", a->pos, a->content);
		a = a->next;
	}
	// ft_small_node(a);
	return (0);
	/*3. Trier */
	/*4. Renvoyer les commandes */
}
