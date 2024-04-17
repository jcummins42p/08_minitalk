/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:16:44 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/26 19:08:01 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*root;

	root = malloc(sizeof(t_list));
	if (!root)
		return (NULL);
	root->content = content;
	root->next = NULL;
	return (root);
}

/*int	main(void)*/
/*{*/
	/*int		send = 4;*/
	/*t_list	*newlist = ft_lstnew(&send);*/
	/*int		*valueptr = (int *)(newlist->content);*/

	/*printf("The value stored in the list is %d\n", *valueptr);*/
	/*return (0);*/
/*}*/
