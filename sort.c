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

	size = stack->size_a - 2;
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

	size = stack->size_a;
	i = 0;
	if (size < 3)
	{
		while (i < size)
		{
			if (stack->a[i] > stack->a[i + 1])
				return (0);
			i++;
			size--;
		}
	}
	else
	{
		while (i <= size)
		{
			if (stack->a[i] > stack->a[i + 1])
				return (0);
			i++;
			size--;
		}
	}
	return (1);
}
//"2", "1", "3", "6", "5", "8"
void	small_sort(t_stack *stack)
{
	while (!check_sort(stack) || stack->size_b != 0)
	{
		if (stack->a[0] > stack->a[1])
			swap(stack->a, 'a');
		if (is_sorted(stack))
		{
			stack->src_len = stack->size_b;
			stack->dst_len = stack->size_a;
			push(stack->a, stack->b, stack, 'a');//pa

		}
		else
		{
			stack->src_len = stack->size_a;
			stack->dst_len = stack->size_b;
			push(stack->b, stack->a, stack, 'b'); //pb
		}
	}
}
//"2", "1", "3", "6", "5", "8"