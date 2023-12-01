/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:19:25 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/01 13:52:56 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_stack(t_stack **a, int nb)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->next = NULL;
	new->content = nb;
	if (!*a)
	{
		*a = new;
		new->pos = 1;
		new->previous = NULL;
	}
	else
	{
		last = ft_find_last(*a);
		last->next = new;
		new->pos = last->pos + 1;
		new->previous = last;
	}
}

void	ft_init_stack(t_stack **a, char **argv)
{
	int		i;
	long	nb;

	i = 1;
	while (argv[i])
	{
		/**Verifier qu'il n'y a pas d'erreur*/
		if (ft_error_syntax(argv[i]))
			ft_error_found(a, argv);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error_found(a, argv);
		if (ft_error_double(*a, (int)nb))
			ft_error_found(a, argv);
		/*Initialisation de la stack a*/
		ft_add_stack(a, (int)nb);
		i++;
	}
}
/*t_list	ft_new_stack(int content, int pos, t_list *previous)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (NULL);
	a->content = content;
	a->pos = pos;
	if (pos == 1)
		a->previous = NULL;
	else
	{
		a->previous = previous;
		a->next = NULL;
	}
	b = NULL;
	return (a);
}*/