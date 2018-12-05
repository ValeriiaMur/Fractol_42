/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:43:23 by vmuradia          #+#    #+#             */
/*   Updated: 2018/10/26 15:21:46 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	var;

	if (!(*needle))
		return ((char *)haystack);
	var = ft_strlen(needle);
	while (*haystack && var <= len--)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, var) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return ((void *)0);
}
