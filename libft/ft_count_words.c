/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:49:52 by vmuradia          #+#    #+#             */
/*   Updated: 2018/11/21 18:50:39 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_words(const char *s, char c)
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
