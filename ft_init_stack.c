/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:19:25 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/06 11:51:26 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_stack(t_stack **a, int content)
{
	t_stack	*new;
	t_stack	*last;

	if (!a)
		return ;
	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->next = NULL;
	new->content = content;
	if (!*a)
	{
		*a = new;
		new->previous = NULL;
	}
	else
	{
		last = ft_find_last(*a);
		last->next = new;
		new->previous = last;
	}
}

void	ft_init_stack(t_stack **a, char **argv)
{
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		/**Verifier qu'il n'y a pas d'erreur*/
		if (ft_error_syntax(argv[i]))
			ft_error_found(a);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error_found(a);
		if (ft_error_double(*a, (int)nb))
			ft_error_found(a);
		/*Initialisation de la stack a*/
		ft_add_stack(a, (int)nb);
		i++;
	}
}
