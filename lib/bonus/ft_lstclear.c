/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:58:31 by jcummins          #+#    #+#             */
/*   Updated: 2023/11/21 15:29:16 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*swap;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		swap = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = swap;
	}
}
