/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:14:21 by vcastilh          #+#    #+#             */
/*   Updated: 2022/08/15 00:47:22 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlstnew(int content)
{
	t_dlst	*dlst;

	dlst = malloc(sizeof(t_dlst));
	if (dlst == NULL)
		return (NULL);
	dlst->content = content;
	dlst->prev = NULL;
	dlst->next = NULL;
	return (dlst);
}
