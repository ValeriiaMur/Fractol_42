/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 10:15:57 by vmuradia          #+#    #+#             */
/*   Updated: 2018/10/28 10:25:59 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		count;
	int		size;
	char	c;

	size = ft_strlen(str);
	count = size;
	while (count > size / 2)
	{
		c = str[size - count];
		str[size - count] = str[count - 1];
		str[count - 1] = c;
		count--;
	}
	return (str);
}
