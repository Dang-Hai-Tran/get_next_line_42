#include "get_next_line.h"

int main(void)
{
	int return_value;
	int fd;
	int idx;
	char *line = 0;

	fd = open("./file.txt", O_RDONLY);
	idx = 1;
	while ((return_value = get_next_line(fd, &line)) > 0)
	{
		printf("line %d : %s\n", idx, line);
		idx++;
		free(line);
	}
	printf("line %d : %s\n", idx, line);
	free(line);
	printf("\nreturn value = %d", return_value);
	return (0);
}

