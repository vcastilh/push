/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:06:19 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/12 21:52:39 by vcastilh         ###   ########.fr       */
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
		return (1);
	stack->size_a = --argc;
	stack->size_b = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		stack->a[i-1] = (int)ft_atol(argv[i]);
		i++;
	}
	return (0);
}

void	print_stack(int *stack, int size)
{
	int	i;

	i = 0;
	while (size--) 
	{
		printf("[%d] = %d\n", i, stack[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc < 2 || !is_valid_numbers(argv))
		return (1);
	if (init_stack(argc, argv, &stack) || is_duplicated(&stack))
		return (1);
	// tetsing swap
	//swap(stack.a, 'a');
	// testing rotate
	//rotate(stack.a, &stack);
	//reverse_rotate(stack.a, stack.size_a);
	push(stack.a, stack.b, &stack); 
	push(stack.a, stack.b, &stack); 
	push(stack.a, stack.b, &stack); 
	printf("STACK A:\n");
	print_stack(stack.a, stack.size_a);
	printf("STACK B:\n");
	print_stack(stack.b, stack.size_b);
	free_stack(&stack);
	return (0);
}
