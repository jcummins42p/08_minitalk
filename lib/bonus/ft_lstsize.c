/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:20:25 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/26 16:45:30 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		i;

	curr = lst;
	i = 0;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

/*int	main(void)*/
/*{*/
	/*int	content = 4;*/

	/*t_list	*testl = ft_lstnew(&content);*/
	/*printf("The length of the list is %d\n", ft_lstsize(testl));*/
	/*return (0);*/
/*}*/
