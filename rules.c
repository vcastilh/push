/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:09:37 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/14 18:24:04 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *vector, char stack)
{
	int	tmp;

	tmp = vector[0];
	vector[0] = vector[1];
	vector[1] = tmp;
	if (stack == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

// 212 32 5 42 9
void	rotate(int *vector, int size, char stack)
{
	int	tmp;

	size -= 1;
	tmp = vector[0];
	ft_memmove(&vector[0], &vector[1], sizeof(int) * (size));
	vector[size] = tmp;
	if (stack == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	reverse_rotate(int *vector, int size, char stack)
{
	int	tmp;

	tmp = vector[size - 1];
	ft_memmove(&vector[1], &vector[0], sizeof(int) * (size - 1));
	vector[0] = tmp;
	if (stack == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	push(int *src, int *dst, t_stack *stack)
{
	int	tmp;

	tmp = src[0];
	if (stack->size_a > 0)
	{
		ft_memmove(&src[0], &src[1], (stack->size_a - 1) * sizeof(int));
		ft_memmove(&dst[1], &dst[0], (stack->size_b) * sizeof(int));
		dst[0] = tmp;
	}
	stack->size_a -= 1;
	stack->size_b += 1;
}

