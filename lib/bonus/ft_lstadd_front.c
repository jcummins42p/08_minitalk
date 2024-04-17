/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:57 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/26 19:28:17 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int	main(void)*/
/*{*/
	/*int 	content1 = 4;*/
	/*int		content2 = 2;*/
	/*t_list *root;*/
	/*int		*valueptr1;*/
	/*int		*valueptr2;*/

	/*root = ft_lstnew(&content1);*/
	/*valueptr1 = (int *)(root->content);*/
	/*printf("%d, %d, %d\n", *valueptr1, *valueptr1, *valueptr1);*/
	/*ft_lstadd_front(&root, ft_lstnew(&content2));*/
	/*valueptr1 = (int *)(root->content);*/
	/*valueptr2 = (int *)(root->next->content);*/
	/*printf("%d, %d, %d\n", *valueptr1, *valueptr2, *valueptr1);*/
	/*return (0);*/
/*}*/
