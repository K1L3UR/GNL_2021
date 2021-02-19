#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;
	int	ret;

	ret = 1;
	if (argc < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("%i-%s|\n", ret, line);
		sleep(1);
	}
	return (0);
}
