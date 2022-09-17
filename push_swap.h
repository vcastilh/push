/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:29:11 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/17 07:19:23 by coder            ###   ########.fr       */
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
	long long	*a;
	long long	*b;
	int			size_a;
	int			size_b;
	int			src_len;
	int			dst_len;
}	t_stack;

int				is_number(char *numb);
int				is_valid_numbers(char *argv[]);
int				is_duplicated(t_stack *stack);
int				init_stack(int argc, char *argv[], t_stack *stack);
void			free_stack(t_stack *stack);
void			print_stack(long long *stack, int size);
void			swap(long long *vector, char stack);
void			rotate(long long *vector, int size, char stack);
void			reverse_rotate(long long *vector, int size, char stack);
void			push(long long *dst, long long *src, t_stack *stack, char move);
int				is_sorted(t_stack *stack);
int				is_positives(t_stack *stack);
int				find_min(t_stack *stack);
long long		turn_positive(t_stack *stack, int pos);
void			re_order(t_stack *stack, long long nb_sum);
void			sort_three(t_stack *stack);
void			small_sort(t_stack *stack);
void			radix(t_stack *stack);
void			set_mem_len(t_stack *stack, int dst, int src);
#endif
