/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:28:22 by arnduran          #+#    #+#             */
/*   Updated: 2021/02/24 01:46:45 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	gnl_read(int fd, char **stock)
{
	ssize_t		ret;
	char		buf[BUFFER_SIZE];
	char		*string;
	size_t		stock_len;

	stock_len = 0;
	ret = 1;
	while (*stock == NULL || ft_strchr(*stock, '\n') == NULL)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) <= 0)
			return (ret);
		if (*stock != NULL)
			stock_len = ft_strlen(*stock);
		if (!(string = ft_calloc(ret + stock_len + 1, 1)))
			return (-1);
		ft_memcpy(string, *stock, stock_len);
		ft_memcpy(string + stock_len, buf, ret);
		if (*stock)
			free(*stock);
		*stock = string;
	}
	return (ret);
}

static	int		gnl_fill_line(char **stock, char **line)
{
	char	*position_eol;
	char	*tmp;

	if (*stock == NULL)
	{
		*line = ft_calloc(1, 1);
		return (0);
	}
	if ((position_eol = ft_strchr(*stock, '\n')) != NULL)
	{
		if ((*line = ft_calloc(position_eol - *stock + 1, 1)) == NULL)
			return (-1);
		ft_memcpy(*line, *stock, position_eol - *stock);
		if ((tmp = ft_calloc(ft_strlen(position_eol) + 1, 1)) == NULL)
			return (-1);
		ft_memcpy(tmp, position_eol + 1, ft_strlen(position_eol));
		free(*stock);
		*stock = tmp;
	}
	else
	{
		*line = *stock;
		*stock = NULL;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*stock = NULL;
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if ((ret = gnl_read(fd, &stock)) == -1)
		return (-1);
	if (gnl_fill_line(&stock, line) == -1)
		return (-1);
	if (ret == 0)
		return (ret);
	return (1);
}
