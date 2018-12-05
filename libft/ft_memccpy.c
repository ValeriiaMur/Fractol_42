/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:31:26 by vmuradia          #+#    #+#             */
/*   Updated: 2018/10/26 10:37:48 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	k;
	size_t			i;

	a = (unsigned char *)d;
	b = (unsigned char *)src;
	k = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		if (b[i] == k)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
