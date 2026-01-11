/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:42:50 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/11 11:23:49 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstmin(t_list *a)
{
	int	i;

	i = *(int *)a->content;
	while (a)
	{
		if (*(int *)a->next->content < i)
			i = *(int *)a->next->content;
		a = a->next;
	}
	return (i);
}
