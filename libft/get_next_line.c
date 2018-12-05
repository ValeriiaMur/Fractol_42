/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:14:57 by vmuradia          #+#    #+#             */
/*   Updated: 2018/11/04 21:11:43 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			reading(char **line, char **text, int fd)
{
	char	*endl;
	char	*tmp;

	endl = ft_strchr(text[fd], '\n');
	if (endl)
		*line = ft_strndup(text[fd], endl - text[fd]);
	else
		*line = ft_strdup(text[fd]);
	tmp = text[fd];
	text[fd] = ft_strsub(text[fd], (unsigned int)(ft_strlen(*line) +
				(endl ? 1 : 0)), (size_t)ft_strlen(text[fd]) - (ft_strlen(*line)
				+ (endl ? 1 : 0)));
	ft_strdel(&tmp);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	int				len;
	char			*tmp;
	static char		*text[MAX_FD];

	if (fd < 0 || fd > MAX_FD || BUFF_SIZE < 1 || !line)
		return (-1);
	if (text[fd] == NULL)
		text[fd] = ft_strnew(1);
	while ((len = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[len] = '\0';
		tmp = ft_strjoin(text[fd], buffer);
		free(text[fd]);
		text[fd] = tmp;
		if (ft_strchr(text[fd], '\n'))
			break ;
	}
	if (len < 0)
		return (-1);
	else if (len == 0 && (text[fd] == NULL || text[fd][0] == '\0'))
		return (0);
	return (reading(line, text, fd));
}
