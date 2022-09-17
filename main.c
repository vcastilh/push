/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:06:19 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/17 06:42:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
}

int	init_stack(int argc, char *argv[], t_stack *stack)
{
	int	i;

	stack->a = malloc(sizeof(long long) * (argc + 1));
	stack->b = malloc(sizeof(long long) * (argc + 1));
	if (stack->a == NULL || stack->b == NULL)
		return (1);
	stack->size_a = --argc;
	stack->size_b = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		stack->a[i - 1] = (long long)ft_atol(argv[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc < 2)
		return (1);
	if (init_stack(argc, argv, &stack) || is_duplicated(&stack)
		|| !is_valid_numbers(argv))
	{
		free_stack(&stack);
		write(1, "Error\n", 6);
		return (1);
	}
	if (is_sorted(&stack))
		return (0);
	is_positives(&stack);
	if (stack.size_a == 2)
		swap(stack.a, 'a');
	else if (stack.size_a == 3)
		sort_three(&stack);
	else if (stack.size_a <= 9)
		small_sort(&stack);
	else
		radix(&stack);
	free_stack(&stack);
	return (0);
}
