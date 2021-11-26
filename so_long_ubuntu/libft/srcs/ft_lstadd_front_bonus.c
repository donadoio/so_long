/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 22:16:42 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/05 16:22:09 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst == NULL || new == NULL)
		return ;
	new->next = *alst;
	*alst = new;
}
