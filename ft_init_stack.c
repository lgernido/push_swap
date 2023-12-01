/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:19:25 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/01 09:18:56 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	ft_new_stack(int content, int pos, t_list *previous)
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
}

void	ft_add_stack(t_list **a, int nb)
{
	t_list	*new;
	t_list	*last;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->content = nb;
	if (!*a)
	{
		*a = new;
		new->previous = NULL;
	}
	else
	{
		last = ft_lstlast(*a);
		last->next = new;
		new->previous = last;
	}
}

void	ft_init_stack(t_list **a, char **argv)
{
	int i;
	int nb;

	i = 0;
	while (argv[i])
	{
		if (ft_error_syntax(argv[i]))
			ft_clean_stack(*a, argv);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_clean_stack(a, argv);
		if (ft_error_double(*a, (int)nb))
			ft_clean_stack(a, argv);
		ft_add_stack(a, (int)nb);
		i++;
	}
}