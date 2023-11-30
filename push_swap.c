/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:40:03 by lgernido          #+#    #+#             */
/*   Updated: 2023/11/30 13:56:09 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	int	pos;

	/*1. Verifier que les arguments sont valides*/
	// Si argv pas un int || plus grans que int max || doublons
	write(2, "Error\n", 6);
	/*2. Initialiser la stack a avec les arguments*/
	pos = 1;
	while (argv)
	{
		ft_init_stack(argv[1], pos);
		argv++;
		pos++;
	}
	/*3. Trier */
	/*4. Renvoyer les commandes */
}
