#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
    
int main()
{
    char     *line;
    int        out;
    int        p[2];
    int        fd;
    int        ret;

    out = dup(1);
    pipe(p);

    fd = 1;
    dup2(p[1], fd);
    write(fd, "abcdefghijklmnop\n", 17);
    write(fd, "qrstuvwxyzabcdef\n", 17);
    close(p[1]);
    dup2(out, fd);
    ret = get_next_line(p[0], &line);
    printf("line1 compare [0]    %d\n", strcmp(line, "abcdefghijklmnop"));
    printf("return value [1]    %d\n",ret);
    ret = get_next_line(p[0], &line);
    printf("line2 compare [0]    %d\n",strcmp(line, "qrstuvwxyzabcdef"));
    printf("return value [1]    %d\n",ret);
    ret = get_next_line(p[0], &line);
    printf("return value [0]    %d\n",ret);
}
