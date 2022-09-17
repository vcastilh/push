/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:23:44 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/15 15:32:18 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->a[0] < stack->a[1] 
			&& stack->a[1] > stack->a[2]
			&& stack->a[0] < stack->a[2])
	{
		swap(stack->a, 'a');
		rotate(stack->a, stack->size_a, 'a');
	}
	else if (stack->a[0] > stack->a[1] 
			&& stack->a[1] < stack->a[2]
			&& stack->a[0] < stack->a[2])
		swap(stack->a, 'a');
	else if (stack->a[0] < stack->a[1] 
			&& stack->a[1] > stack->a[2]
			&& stack->a[0] > stack->a[2])
		reverse_rotate(stack->a, stack->size_a, 'a');
	else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		swap(stack->a, 'a');
		reverse_rotate(stack->a, stack->size_a, 'a');
	}
	else if(stack->a[0] > stack->a[1] 
			&& stack->a[1] < stack->a[2]
			&& stack->a[0] > stack->a[2])
		rotate(stack->a, stack->size_a, 'a');
}

int	check_sort(t_stack *stack)
{
	int	size;
	int	i;

	size = stack->size_a - 1;
	i = 0;
	while (i < size)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	int	size;
	int	i;

	size = stack->size_a - 1;
	i = 0;
	while (i < size)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	small_sort(t_stack *stack)
{
	while (!check_sort(stack) || stack->size_b != 0)
	{
		if (stack->a[0] > stack->a[1])
			swap(stack->a, 'a');
		if (check_sort(stack))
		{
			stack->src_len = stack->size_b;
			stack->dst_len = stack->size_a;
			push(stack->a, stack->b, stack, 'a');

		}
		else
		{
			stack->src_len = stack->size_a;
			stack->dst_len = stack->size_b;
			push(stack->b, stack->a, stack, 'b');
		}
	}
}

void	radix(t_stack *stack)
{
	int	bit;
	int	j;

	bit = 0;
	while (!is_sorted(stack))
	{
		j = 0;
		while (j < stack->size_a + stack->size_b)
		{
			if ((stack->a[0] >> bit) & 1)
				rotate(stack->a, stack->size_a, 'a');
			else
			{
				stack->dst_len = stack->size_b;
				stack->src_len = stack->size_a;
				push(stack->b, stack->a, stack, 'b');
			}				
			j++;
		}
		bit++;
		while (stack->size_b > 0)
		{
			stack->dst_len = stack->size_a;
			stack->src_len = stack->size_b;
			push(stack->a, stack->b, stack, 'a');
		}
	}
}
