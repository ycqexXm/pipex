/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:00:25 by yorlians          #+#    #+#             */
/*   Updated: 2022/11/12 01:36:05 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_w(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static size_t	ft_w(char const *str, char c)
{
	size_t	i;
	size_t	j;

	if (!str[0])
		return (0);
	i = 0;
	j = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c)
		{
			j++;
			while (str[i] && str[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (str[i - 1] != c)
		j++;
	return (j);
}

static void	ft_wd(char **str, size_t *w, char c)
{
	size_t	i;

	*str += *w;
	*w = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*w)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_w;
	char	*str;
	size_t	w;
	size_t	i;

	if (!s)
		return (NULL);
	ptr_w = (char **)malloc(sizeof(char *) * (ft_w(s, c) + 1));
	if (!ptr_w)
		return (NULL);
	i = 0;
	str = (char *)s;
	w = 0;
	while (i < ft_w(s, c))
	{
		ft_wd(&str, &w, c);
		ptr_w[i] = (char *)malloc(sizeof(char) * (w + 1));
		if (!ptr_w[i])
			return (ft_free_w(ptr_w));
		ft_strlcpy(ptr_w[i], str, w + 1);
		i++;
	}
	ptr_w[i] = NULL;
	return (ptr_w);
}
