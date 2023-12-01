/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:39:15 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/01 13:39:07 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_double(t_stack *a, int nb)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->content == nb)
			return (1);
		a = a->next;
	}
	return (0);
}
int	ft_error_syntax(char **argv)
{
	if (*argv != '+' || *argv != '-' || (!ft_isdigit(argv)))
		return (1);
	return (0);
}

void	ft_error_found(t_stack **a, char **argv)
{
	ft_stack_clear(a);
	write(2, "Error\n", 6);
	exit(1);
}
