#include "get_next_line.h"

static ssize_t	gnl_read(int fd, char *stock)
{
	ssize_t	ret;
	char	buf[BUFFER_SIZE];
	char	*string;
	size_t	stock_len;

	stock_len = 0;
	ret = 0;
	while (stock == NULL || strchr(stock, '\n') == NULL)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			return (ret);
		if (stock != NULL)
			stock_len = strlen(stock);
		string = malloc(BUFFER_SIZE + stock_len + 1);
		memcpy(string, stock, stock_len);
		memcpy(string + stock_len, buf, BUFFER_SIZE);
		string[stock_len + BUFFER_SIZE] = '\0';
		free(stock);
		stock = string;
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static	char	*stock = NULL;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	gnl_read(fd, stock);
	return (0);
}
