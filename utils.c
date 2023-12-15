/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:27:27 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/15 08:46:19 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *nptr)
{
	long	nb;
	int		sign;
	int		i;

	nb = 0;
	sign = 1;
	i = 0;
	while (nptr[i] && (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f'))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

t_stack	*ft_find_small(t_stack *a)
{
	int		smallest_content;
	t_stack	*smallest_node;

	smallest_node = NULL;
	if (!a)
		return (NULL);
	smallest_content = INT_MAX;
	while (a)
	{
		if (a->content < smallest_content)
		{
			smallest_content = a->content;
			smallest_node = a;
		}
		a = a->next;
	}
	return (smallest_node);
}
t_stack	*ft_find_big(t_stack *a)
{
	int		biggest_content;
	t_stack	*biggest_node;

	biggest_node = NULL;
	if (!a)
		return (NULL);
	biggest_content = INT_MIN;
	while (a)
	{
		if (a->content > biggest_content)
		{
			biggest_content = a->content;
			biggest_node = a;
		}
		a = a->next;
	}
	return (biggest_node);
}
int	ft_stack_size(t_stack *a)
{
	int	size;

	size = 0;
	if (!a)
		return (0);
	while (a)
	{
		size++;
		a = a->next;
	}
	return (size);
}

t_stack	*ft_find_last(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}