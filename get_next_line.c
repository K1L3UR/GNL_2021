#include "get_next_line.h"

/*
	verifier ft_memcpy(string, stock(value = 0), stock_len(value = 0) puis je le faire sans erreur sur mon ft_memcpy;


*/

static ssize_t	gnl_read(int fd, char **stock)
{
	ssize_t	ret;
	char	buf[BUFFER_SIZE];
	char	*string;
	size_t	stock_len;

	stock_len = 0;
	ret = 1;
	while (*stock == NULL || strchr(*stock, '\n') == NULL)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) <= 0)
			return (ret);
		if (*stock != NULL)
			stock_len = strlen(*stock);
		if (!(string = calloc(ret + stock_len + 1, 1)))
			return (-1);
		memcpy(string, *stock, stock_len); // verif implementation ft_memcpy -> src = NULL stock_len = 0 | 
		memcpy(string + stock_len, buf, ret);
		if (*stock)
			free(*stock);
		*stock = string;
	}
	return (ret);
}

static	int gnl_fill_line(char **stock, char **line)
{
	char	*position_eol;
	char	*tmp;

	if (stock == NULL)
		return (0);
	position_eol = strchr(*stock, '\n');
	if (position_eol != NULL)
	{
		if ((*line = calloc(position_eol - *stock + 1, 1)) == NULL)
			return (-1);
		memcpy(*line, *stock, position_eol - *stock);
		if ((tmp = calloc(strlen(position_eol) + 1, 1)) == NULL)
			return (-1);
		memcpy(tmp, position_eol + 1, strlen(position_eol));
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

int		get_next_line(int fd, char **line)
{
	static	char	*stock = NULL;
	int		ret;

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
