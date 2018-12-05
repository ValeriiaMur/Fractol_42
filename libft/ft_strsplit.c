/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:01:33 by vmuradia          #+#    #+#             */
/*   Updated: 2018/10/28 10:10:09 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(const char *s, char c)
{
	int	cnt;
	int	inside;

	inside = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (inside == 1 && *s == c)
			inside = 0;
		if (inside == 0 && *s != c)
		{
			inside = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int	ft_dellen(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		nb_word;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nb_word = ft_counter((const char *)s, c);
	res = (char **)malloc(sizeof(*res) * (ft_counter((const char *)s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		res[i] = ft_strsub((const char *)s, 0, ft_dellen((const char *)s, c));
		if (res[i] == NULL)
			return (NULL);
		s = s + ft_dellen(s, c);
		i++;
	}
	res[i] = NULL;
	return (res);
}
