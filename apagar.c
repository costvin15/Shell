#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv){
	int retorno = 0;
	if (argv[1] != NULL)
		retorno = remove(argv[1]);
	if (retorno != 0)
		printf("Something went wrong! %s\n", strerror(errno));
	return 0;
}
