/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciegernidos <luciegernidos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:40:03 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/01 17:03:33 by luciegernid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	/*1. Verifier que les arguments sont valides*/
	if (argc == 1)
		ft_error_found(a, argv);
	/*2. Initialiser la stack a avec les arguments*/
	ft_init_stack(&a, *argv + 1);
	printf("%d->", a->content);
	return (0);
	/*3. Trier */
	/*4. Renvoyer les commandes */
}
