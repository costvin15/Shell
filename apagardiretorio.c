#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char **argv){
	int retorno = 0;

	if (argv[1] != NULL)
		retorno = rmdir(argv[1]);
	
	if (retorno == -1)
		printf("Something went wrong! %s\n", strerror(errno));	
	
	return 0;
}
