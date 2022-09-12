/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:46:16 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/09 08:56:41 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlstlast(t_dlst *dlst)
{
	if (dlst == NULL || dlst->next == NULL)
		return (dlst);
	return (ft_dlstlast(dlst->next));
}
