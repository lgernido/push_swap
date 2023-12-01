/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:27:27 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/01 13:37:43 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	write_nb(const char *nptr, int *i)
{
	int	nb;

	nb = 0;
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		nb = nb * 10 + (nptr[*i] - '0');
		(*i)++;
	}
	return (nb);
}

long	ft_atol(char *nptr)
{
	int		i;
	int		neg;
	int		sign;
	long	nb;

	i = 0;
	sign = 0;
	neg = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg++;
		sign++;
		i++;
	}
	nb = write_nb(nptr, &i);
	if (neg == 1)
		nb = -nb;
	if (sign > 1)
		return (0);
	return (nb);
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
		free(curr->content);
		free(curr->pos);
		free(curr);
		curr = next;
	}
	*a = NULL;
}

t_stack	*ft_find_last(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (&a);
}
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
