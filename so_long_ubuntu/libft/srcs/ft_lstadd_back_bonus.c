/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 23:49:06 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/05 16:22:05 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	if (!alst || !new)
		return ;
	if (*(alst) == NULL)
	{
		*alst = new;
	}
	else
	{
		last = ft_lstlast(*alst);
		last->next = new;
	}
}
