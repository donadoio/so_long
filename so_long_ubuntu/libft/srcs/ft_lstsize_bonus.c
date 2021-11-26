/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 22:35:40 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/05 16:22:38 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (!lst)
	{
		return (0);
	}
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
