/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:06:19 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/12 11:54:44 by vcastilh         ###   ########.fr       */
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

	stack->a = malloc(sizeof(int) * argc);
	stack->b = malloc(sizeof(int) * argc);
	if (stack->a == NULL || stack->b == NULL)
		return (0);
	stack->size_a = --argc;
	stack->size_b = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		stack->a[i-1] = (int)ft_atol(argv[i]);
		i++;
	}
	return (1);
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->size_a--) 
	{
		printf("a[%d] = %d\n", i, stack->a[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc < 2 || !is_valid_numbers(argv))
		return (1);
	init_stack(argc, argv, &stack);
	print_stack(&stack);
	free_stack(&stack);
	return (0);
}
