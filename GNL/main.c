#include "get_next_line.h"
#include <stdio.h>

#include <time.h>
     

int	main()
{

	 clock_t start, end;
     
    start = clock();
    start = NULL;
	int i;
	int fd = open("large_file.txt", O_RDONLY);
	char	**line;
	line = malloc(100000);
	*line = malloc(100000);
	i = 1;
	int count = 0;
	while (count != 783)
	{	
		count++;
		i = get_next_line(fd, line);
		printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
	}
	 end = clock();
	printf("%lu\n",end );
}
     // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
/*
}
int	main()
{
	
	int i = 0;

	int	fd2 = open("one_big_fat_line.txt", O_RDONLY);
	char	**line2;
	line2 = malloc(100000);
	*line2 = malloc(100000);

	while (i > -1)
	{
		i = get_next_line(fd2, line2);
	}
//	i = get_next_line(fd2, line2);
//	printf("%s\n", *line2);
//	i = get_next_line(fd2, line2);
//	i = get_next_line(fd2, line2);
//	i = get_next_line(fd2, line2);
*/
