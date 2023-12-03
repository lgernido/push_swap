/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 08:03:19 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/03 08:16:33 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Chaque fonction execute une commande comme decrite dans le sujet.
Ici, 4 commande donc 4 fonctions (swap, push, rotate et reverse rotate).
La 5eme fonction appelle les commandes sur les differentes stacks et les nomment
conformement au sujet*/

void	ft_swap(t_stack *stack)
{
	int	size;
	int	tmp;

	size = ft_stack_size(stack);
	if (size == 1 || size == 0 || !stack)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	stack->next->previous = NULL;
	stack->previous = stack->next;
}

void	ft_push(t_stack **from, t_stack **to)
{
	if (!from)
		return ;
	*from = (*from)->next;
	(*from)->previous = NULL;
	*from->previous = NULL;
	if (!to)
	{
		*to = *from;
		*from->next = NULL;
	}
	else
	{
		*from->next = *to;
		*from->next->previous = *from;
		*to = *from;
	}
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*last;
	int		size;

	size = ft_stack_size(*stack);
	if (size == 1 || size == 0 || !stack)
		return ;
	last = ft_find_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int		size;

	size = ft_stack_size(*stack);
	if (size == 1 || size == 0 || !stack)
		return ;
	last = ft_find_last(*stack);
	last->previous->next = NULL;
	last->next = *stack;
	last->previous = NULL;
	*stack = last;
	last->next->previous = last;
}
/*void	ft_execute_command(char *command)
{
	if (command == "sa")
	{
		ft_swap(a);
		write(1, "sa\n", 3);
	}
	else if (command == "sb")
	{
		ft_swap(b);
		write(1, "sb\n", 3);
	}
	else if (command == "ss")
	{
		ft_swap(a);
		ft_swap(b);
		write(1, "ss\n", 3);
	}
}*/
