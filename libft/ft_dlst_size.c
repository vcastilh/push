/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:31:15 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/09 11:33:21 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlst_size(t_dlst *dlst)
{
	int	size;

	if (dlst == NULL)
		return (0);
	size = 1;
	while (dlst->next != NULL)
	{
		size++;
		dlst = dlst->next;
	}
	return (size);
}
