/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:23:44 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/14 18:26:27 by vcastilh         ###   ########.fr       */
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
