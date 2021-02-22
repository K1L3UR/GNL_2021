#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#define BUFFER_SIZE 7

int		get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memcpy(void	*dst, const void *src, size_t n);
void		ft_bzero(void *s, size_t n);
char		*ft_strchr(const char *s, int c);

#endif
