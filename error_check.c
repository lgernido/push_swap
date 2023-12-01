/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:39:15 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/01 09:18:51 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_double(t_list *a, int nb)
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
	if (!(*argv == '+' || (*argv >= '0' && *argv <= 9) || *argv == '-'))
		return (1);
	return (0);
}

void	ft_clear_stack(t_list **a, char **argv)
{
	ft_lstclear(a);
	write(2, "Error\n", 6);
	exit(1);
}
