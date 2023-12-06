/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:27:27 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/06 11:00:03 by lgernido         ###   ########.fr       */
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

t_stack	*ft_find_small(t_stack *a)
{
	int		smallest_content;
	t_stack	*smallest_node;

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
int	ft_stack_size(t_stack *a)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
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
