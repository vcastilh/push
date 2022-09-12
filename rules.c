/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:09:37 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:29:27 by vcastilh         ###   ########.fr       */
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
void	rotate(int *vector, int size)
{
	int	tmp;

	size -= 1;
	tmp = vector[0];
	ft_memmove(&vector[0], &vector[1], sizeof(int) * (size));
	vector[size] = tmp;
}

void	reverse_rotate(int *vector, int size)
{
	int	tmp;

	tmp = vector[size - 1];
	ft_memmove(&vector[1], &vector[0], sizeof(int) * (size - 1));
	vector[0] = tmp;
}

