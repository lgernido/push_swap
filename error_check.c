/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:39:15 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/18 16:28:15 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_clear(t_stack **a)
{
	t_stack	*curr;
	t_stack	*next;

	if (a == NULL)
		return ;
	curr = *a;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*a = NULL;
}

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
int	ft_error_syntax(char *argv)
{
	if (argv[0] == '-' && argv[1] == '-')
		return (1);
	if (!(*argv == '+' || *argv == '-' || (*argv >= '0' && *argv <= '9')))
		return (1);
	return (0);
}

void	ft_error_found(t_stack **a)
{
	ft_stack_clear(a);
	write(2, "Error\n", 6);
	exit(1);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}