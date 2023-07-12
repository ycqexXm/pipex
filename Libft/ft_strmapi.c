/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 06:22:41 by yorlians          #+#    #+#             */
/*   Updated: 2022/10/23 00:37:10 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*n_str;
	size_t	i;
	size_t	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		i = 0;
		n_str = malloc(sizeof(char ) *(len + 1));
		if (n_str == NULL)
			return (NULL);
		while (i < len)
		{
			n_str[i] = f((unsigned int)i, s[i]);
			i++;
		}
		n_str[i] = 0;
		return (n_str);
	}
	return (NULL);
}
