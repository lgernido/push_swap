/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciegernidos <luciegernidos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:39:56 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/01 16:53:38 by luciegernid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				pos;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

int					main(int argc, char **argv);

/*Initialisation des stacks*/

// t_list				ft_new_stack(int content, int pos, t_list *previous);
void				ft_add_stack(t_stack **a, int nb);
void				ft_init_stack(t_stack **a, char **argv);

/*Check et gestion des erreurs*/

int					ft_error_double(t_stack *a, int nb);
int					ft_error_syntax(char *argv);
void				ft_error_found(t_stack **a, char **argv);

/*Utilitaires*/

long				ft_atol(char *nptr);
void				ft_stack_clear(t_stack **a);
t_stack				*ft_find_last(t_stack *a);

#endif