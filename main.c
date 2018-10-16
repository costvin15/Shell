#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "palavralib.h"
#include <readline/history.h>
#include <readline/readline.h>

int main(int argc, char **argv){
	char *inserido, **matrizDeComandos;
    	int i, pid, statusExecv, statusPid;
    	while (1){
		inserido = readline("macashell>> ");
        	matrizDeComandos = fraseParaPalavras(inserido);

		const char **argumentos = (const char **) malloc((contaPalavras(inserido) + 2) * sizeof(char *));
		if (contaPalavras(inserido) > 1)
			for (i = 0; i < contaPalavras(inserido); i++)
				argumentos[i] = matrizDeComandos[i];

        	if (strcmp(matrizDeComandos[0], "sair") == 0)
            		exit(1);
    
       		pid = fork();

		if (pid == 0){
            		// Se o PID é zero, então esse processo é um processo-filho
            		if (contaPalavras(inserido) > 1)
				statusExecv = execv(matrizDeComandos[0], (char **) argumentos);
			else
				statusExecv = execv(matrizDeComandos[0], NULL);
            		if (statusExecv == -1)
                		printf("Comando desconhecido\n");
            		return 0;
        	} else 
            		// Se o PID não é zero, então esse processo é um processo-pai
            		waitpid(-1, &statusPid, 0);

        	for (i = 0; i < contaPalavras(inserido); i++)
            		free(matrizDeComandos[i]);
        	free(matrizDeComandos);        
        	free(inserido);
    	}

   	return 0;
}
