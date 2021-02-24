/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:22:40 by arnduran          #+#    #+#             */
/*   Updated: 2021/02/24 00:58:07 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (!(s = (void *)malloc(count * size)))
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((!(dst)) && (!(src)))
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
