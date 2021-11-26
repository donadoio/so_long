/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 03:07:33 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/05 16:22:30 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *node_new;
	t_list *node_1;

	if (lst == NULL)
		return (NULL);
	node_1 = ft_lstnew((*f)(lst->content));
	if (node_1 == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		node_new = ft_lstnew((*f)(lst->content));
		if (node_new == NULL)
		{
			ft_lstclear(&node_1, del);
			return (NULL);
		}
		ft_lstadd_back(&node_1, node_new);
		lst = lst->next;
	}
	return (node_1);
}
