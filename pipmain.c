#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
    
int main()
{
    char     *line;
    int        out;
    int        p[2];
    int        fd;
    int        gnl_ret;

    out = dup(1);
    pipe(p);

    fd = 1;
    dup2(p[1], fd);
    write(fd, "abc\n\n", 5);
    close(p[1]);
    dup2(out, fd);

    /* Read abc and new line */
    gnl_ret = get_next_line(p[0], &line);
    printf("[1] out %d\n" ,gnl_ret);
    printf("comp %d\n" ,strcmp(line, "abc"));

    /* Read new line */
    gnl_ret = get_next_line(p[0], &line);
    printf("[1] out %d\n" ,gnl_ret);
    // mt_assert(line == NULL || *line == '\0');

    /* Read again, but meet EOF */
    gnl_ret = get_next_line(p[0], &line);
    printf("[0] out %d\n" ,gnl_ret);
    // mt_assert(line == NULL || *line == '\0');

    /* Let's do it once again */
    gnl_ret = get_next_line(p[0], &line);
    printf("[0] out %d\n" ,gnl_ret);
    // mt_assert(line == NULL || *line == '\0');
}
