/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:14:01 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/22 19:07:16 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	hexcond(char p, int *result)
{
	if (p >= '0' && p <= '9')
		*result = *result * 16 + (p - '0');
	else if (p >= 'a' && p <= 'f')
		*result = *result * 16 + (p - 'a' + 10);
	else if (p >= 'A' && p <= 'F')
		*result = *result * 16 + (p - 'A' + 10);
	else
		return (0);
	return (1);
}

int	ft_hexatoi(const char *str)
{
	int			sign;
	int			result;
	const char	*p;

	sign = 1;
	result = 0;
	p = str;
	if (!p)
		return (0);
	if (*p == '+' || *p == '-')
	{
		if (*p == '-')
			sign = -1;
		p++;
	}
	if (*p == '0' && (*(p + 1) == 'x' || *(p + 1) == 'X'))
		p += 2;
	while (*p)
	{
		if (!hexcond(*p, &result))
			break ;
		p++;
	}
	return (result * sign);
}
