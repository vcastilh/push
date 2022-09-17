/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:01:37 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/17 01:01:40 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	size;
	int	i;
	int	min;
	int	pos;

	size = stack->size_a;
	i = 0;
	min = 0;
	while (size--)
	{
		if (stack->a[i] < 0)
		{
			if (min > stack->a[i])
			{
				min = stack->a[i];
				pos = i;
			}
		}
		i++;
	}
	return (pos);
}

int	is_positives(t_stack *stack)
{
	int	size;
	int	i;
	int	pos;

	size = stack->size_a;
	i = 0;
	while (size--)
	{
		if (stack->a[i] < 0)
		{
			pos = find_min(stack);
			re_order(stack, turn_positive(stack, pos));
			return (0);
		}
		i++;
	}
	return (1);
}

long long	turn_positive(t_stack *stack, int pos)
{
	long long	tmp;

	tmp = stack->a[pos] * -1;
	return (tmp);
}

void	re_order(t_stack *stack, long long nb_sum)
{
	int	size;
	int	i;

	size = stack->size_a;
	i = 0;
	while (size--)
		stack->a[i++] += nb_sum; 
}
