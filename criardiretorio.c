#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char **argv){
	int result = 0;
	if (argv[1] != NULL)
		result = mkdir(argv[1], 0754);
	if (result == -1)
		printf("Something went wrong! %s\n", strerror(errno));

	return 0;
}
