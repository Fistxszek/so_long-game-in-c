
#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd = open("/nfs/homes/korzecho/ProjectsMainFolder/03_GetNextLine/Get_next_line/text", O_RDONLY);
	char * aaa = (char *)malloc((BUFFER_SIZE) * sizeof(char));
	int i = 1;
	while (i == 1)
	{
		aaa = get_next_line(fd);
		if (!aaa)
			i = 0;
		else
			printf("%s", aaa);
	}
	

	return 0;
}