/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 03:00:14 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/05 16:22:21 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	while (lst != NULL)
	{
		if (lst->content != NULL)
			f(lst->content);
		lst = lst->next;
	}
}
