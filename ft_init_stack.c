/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciegernidos <luciegernidos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:19:25 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/23 16:26:43 by luciegernid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	new->cheapest = false;
}

void	ft_init_stack(t_stack **a, char **argv)
{
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11)
			ft_error_found(a);
		if (ft_error_syntax(argv[i]))
			ft_error_found(a);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error_found(a);
		if (ft_error_double(*a, (int)nb))
			ft_error_found(a);
		ft_add_stack(a, (int)nb);
		i++;
	}
}
