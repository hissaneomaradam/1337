/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:58:42 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/31 18:12:01 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
// void	del(void *content)
// {
// 	free(content);
// }
// int	main()
// {
// 	t_list	*tmp;
// 	t_list	*node;
//
// 	node = ft_lstnew(ft_strdup("hello"));
// 	ft_lstadd_back(&node, ft_lstnew(ft_strdup("world")));
// 	ft_lstadd_back(&node, ft_lstnew(ft_strdup("im")));
// 	ft_lstadd_back(&node, ft_lstnew(ft_strdup("omar")));
// 	tmp = node;
// 	while (tmp)
// 	{
// 		printf("%s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	ft_lstclear(&node, del);
// }
