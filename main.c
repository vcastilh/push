/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:06:19 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/14 20:15:45 by vcastilh         ###   ########.fr       */
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

//void	print_stack(int *stack, int size)
//{
//	int	i;
//
//	i = 0;
//	while (size--) 
//	{
//		printf("[%d] = %d\n", i, stack[i]);
//		i++;
//	}
//}

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

int	turn_positive(t_stack *stack, int pos)
{
	int	tmp;

	tmp = stack->a[pos] * -1;
	return (tmp);
}

void	re_order(t_stack *stack, int nb_sum)
{
	int	size;
	int	i;

	size = stack->size_a;
	i = 0;
	while (size--)
	{
		while (stack->a[i])
			stack->a[i++] += nb_sum; 
	}
}

int	is_sorted(t_stack *stack)
{
	int	size;
	int	i;

	size = stack->size_a;
	i = 0;
	while (i < size--)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// top to middle, middle to bottom, and bottom to top

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc < 2 || !is_valid_numbers(argv)) 
		return (1);
	if (init_stack(argc, argv, &stack) || is_duplicated(&stack) || is_sorted(&stack))
	{
		free_stack(&stack);
		return (1);
	}
	is_positives(&stack);
	if (stack.size_a == 2)
		swap(stack.a, 'a');
	else if (stack.size_a == 3)
		sort_three(&stack);

		//small_sort(&stack);
	//radix();
		

	//radix recebe positivos 1.pegar menor numero e multiplica por -1 e soma, 1 - 9 -7 8 -4 => 10 0 2 17 5

	//função boleana se estiver ordenado o vetor

	//algo pra 3 e 5 números
	//radix acima de 50 números
	//
	//
	//swap(stack.a, 'a');
	//rotate(stack.a, stack.size_a);
	//reverse_rotate(stack.a, stack.size_a);
	//push(stack.a, stack.b, &stack); 
//	printf("STACK A:\n");
//	print_stack(stack.a, stack.size_a);
//	printf("STACK B:\n");
//	print_stack(stack.b, stack.size_b);
	free_stack(&stack);
	return (0);
}
