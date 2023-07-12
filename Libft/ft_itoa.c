/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:01:14 by yorlians          #+#    #+#             */
/*   Updated: 2022/11/07 19:07:16 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_null(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			num;
	int			count;

	num = n;
	count = 0;
	while (num != 0)
	{
		count++;
		num = num / 10;
	}
	count = count + (n <= 0);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (str);
	ft_null(n, str);
	str[count] = '\0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		str[--count] = (n % 10) * (2 * (n > 0) - 1) + '0';
		n = n / 10;
	}
	return (str);
}
