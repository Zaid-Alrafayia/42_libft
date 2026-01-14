/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:21:16 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/12 03:53:17 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_lstmax(t_list *a)
{
	int	max;
	int	cur;

	if (!a)
		return (0);
	max = *(int *)a->content;
	while (a)
	{
		cur = *(int *)a->content;
		if (cur > max)
			max = cur;
		a = a->next;
	}
	return (max);
}
