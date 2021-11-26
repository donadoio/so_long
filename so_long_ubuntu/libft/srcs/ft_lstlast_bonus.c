/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 22:52:43 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/05 16:22:27 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"
#include <stddef.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list *tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
