/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:09:17 by vmuradia          #+#    #+#             */
/*   Updated: 2018/10/27 13:40:34 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *m;

	m = (char *)malloc(size * sizeof(char));
	if (m == NULL)
	{
		return (NULL);
	}
	ft_bzero(m, size);
	return (m);
}
