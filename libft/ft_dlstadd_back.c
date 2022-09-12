/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:47:23 by vcastilh          #+#    #+#             */
/*   Updated: 2022/08/15 00:39:19 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlstadd_back(t_dlst *old_node, int content)
{
	t_dlst	*dlst;

	dlst = malloc(sizeof(t_dlst));
	if (dlst == NULL)
		return (NULL);
	old_node->next = dlst;
	dlst->prev = old_node;
	dlst->content = content;
	dlst->next = NULL;
	return (dlst);
}
