/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:27:49 by arnduran          #+#    #+#             */
/*   Updated: 2021/02/24 00:54:33 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void	*dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);

#endif
