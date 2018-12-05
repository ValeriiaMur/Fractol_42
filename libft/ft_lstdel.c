/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:03:37 by vmuradia          #+#    #+#             */
/*   Updated: 2018/10/26 15:27:26 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *curr;

	while (*alst)
	{
		curr = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = curr;
	}
	*alst = NULL;
}
