/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:16:08 by yorlians          #+#    #+#             */
/*   Updated: 2022/10/20 00:08:12 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*s1c;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	s1c = malloc((len + 1) * sizeof(char));
	i = 0;
	if (s1c == 0)
		return (0);
	while (i < len)
	{
		s1c[i] = s1[i];
		i++;
	}
	s1c[i] = '\0';
	return (s1c);
}
