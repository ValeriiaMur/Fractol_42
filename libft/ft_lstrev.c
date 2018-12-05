/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 10:32:17 by vmuradia          #+#    #+#             */
/*   Updated: 2018/10/28 10:33:09 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrev(t_list **alst)
{
	t_list	*last;
	t_list	*cur;
	t_list	*next;

	last = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = last;
		last = cur;
		cur = next;
	}
	*alst = last;
}
