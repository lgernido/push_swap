/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciegernidos <luciegernidos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:40:03 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/19 19:02:07 by luciegernid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void process_arguments(int argc, char **argv, t_stack **a, t_stack **b)
{
	bool split;

	*a = NULL;
	*b = NULL;
	split = false;

	if (argc == 1)
		exit(1);
	else if (argc == 2) 
	{
		argv = ft_split(argv[1], ' ');
		split = true;
	}
	ft_init_stack(a, argv + 1);
	if (split)
		free_split(argv);
}

static void execute_sorting(t_stack *a, t_stack *b)
{
	if (!ft_a_sorted(a)) 
	{
		if (ft_stack_size(a) == 2)
			ft_make_sa(a);
		else if (ft_stack_size(a) == 3)
			ft_sort_three(&a);
		else
			ft_push_swap(&a, &b);
	}
	ft_stack_clear(&a);
}

int main(int argc, char **argv) 
{
	t_stack *a;
	t_stack *b;

	process_arguments(argc, argv, &a, &b);
	execute_sorting(a, b);
	return (0);
}
