#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

int main(void){
	DIR *diretorioAtual;
	diretorioAtual = opendir(".");

	struct dirent *dir;

	if (diretorioAtual != NULL){
		while ((dir = readdir(diretorioAtual)) != NULL){
			printf("%s ", dir->d_name);
			if (dir->d_type == DT_DIR)
				printf(" (pasta)");
			else if(dir->d_type == DT_REG)
				printf(" (arquivo)");
			putchar('\n');
		}
		putchar('\n');
		closedir(diretorioAtual);
	} else
		printf("Something went wrong! %s\n", strerror(errno));

	return 0;
}
