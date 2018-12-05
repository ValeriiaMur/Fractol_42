/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:13:03 by vmuradia          #+#    #+#             */
/*   Updated: 2018/10/23 14:17:05 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *p;

	p = s;
	while (*p)
		p++;
	if (c == '\0')
		return ((char *)p);
	while (p-- != s)
	{
		if (*p == c)
			return ((char *)p);
	}
	return (NULL);
}
