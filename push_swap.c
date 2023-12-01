/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:40:03 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/01 08:22:03 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	/*1. Verifier que les arguments sont valides*/
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		write(2, "Error\n", 6);
	/*2. Initialiser la stack a avec les arguments*/
	ft_init_stack(&a, argv + 1)
	/*3. Trier */
	/*4. Renvoyer les commandes */
}
