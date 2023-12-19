/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:40:03 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/19 16:20:52 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		ft_error_found(&a);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_init_stack(&a, argv + 1);
	if (!ft_a_sorted(a))
	{
		if (ft_stack_size(a) == 2)
			ft_make_sa(a);
		else if (ft_stack_size(a) == 3)
			ft_sort_three(&a);
		else
			ft_push_swap(&a, &b);
	}
	free_split(argv);
	ft_stack_clear(&a);
	return (0);
}
