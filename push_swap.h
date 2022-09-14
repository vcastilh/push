/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:29:11 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/13 23:46:58 by vcastilh         ###   ########.fr       */
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
int		is_duplicated(t_stack *stack);
int		init_stack(int argc, char *argv[], t_stack *stack);
void	free_stack(t_stack *stack);
void	print_stack(int *stack, int size);
void	swap(int *vector, char stack);
void	rotate(int *vector, int size);
void	reverse_rotate(int *vector, int size);
void	push(int *src, int *dst, t_stack *stack);
int		is_positives(t_stack *stack);
int		find_min(t_stack *stack);
int		turn_positive(t_stack *stack, int pos);
void	re_order(t_stack *stack, int nb_sum);
#endif
