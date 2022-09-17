/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:22:48 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/17 06:36:21 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(char *argv[])
{
	int		i;
	long	temp;

	i = 1;
	while (argv[i] != NULL)
	{
		temp = ft_atol(argv[i]);
		if (temp < MIN_INT || temp > MAX_INT)
			return (0);
		i++;
	}
	return (1);
}

int	is_number(char *numb)
{
	while (*numb)
	{
		if (*numb == '-' || *numb == '+')
			numb++;
		else if (ft_isdigit(*numb))
			numb++;
		else
			return (0);
	}
	return (1);
}

int	is_valid_numbers(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (is_number(argv[i]) == 0)
			return (0);
		i++;
	}
	if (is_integer(argv) == 0)
		return (0);
	return (1);
}

int	is_duplicated(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp_size;

	i = 0;
	tmp_size = stack->size_a;
	while (i < tmp_size - 1)
	{
		j = i + 1;
		while (j < tmp_size)
		{
			if (stack->a[i] == stack->a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
