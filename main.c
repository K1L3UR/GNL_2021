#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "get_next_line.h"

int    main(int argc, char **argv)
{
    int        fd;
    int        fd_w;
    char    *line;
    int        ret;

    if (argc < 2)
        return (0);
    fd = open(argv[1], O_RDONLY);
    fd_w = open("gnl_out.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR + S_IWUSR);
    if (fd < 0)
    {
        printf("fd = %i\n", fd);
        return (1);
    }
    ret = 1;
    line = NULL;
    while (ret > 0)
    {
        ret = get_next_line(fd, &line);
        printf("%i-%s\n", ret, line);
        //write(fd_w, line, strlen(line));
        if (ret != 0)
            write(fd_w, "\n", 1);
    }
    return (0);
}
