/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:29:11 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/12 11:43:38 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;


int		is_number(char *numb);
int		is_valid_numbers(char *argv[]);
int		is_duplicated(t_stack **stack);
int		init_stack(int argc, char *argv[], t_stack *stack);
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);
#endif
