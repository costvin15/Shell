#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "palavralib.h"
#include <readline/history.h>
#include <readline/readline.h>

int main(int argc, char **argv){
    char *inserido, **matrizDeArgumentos;
    int i, pid, statusExecv, statusPid;
    while (1){
        inserido = readline("macashell>> ");
        matrizDeArgumentos = fraseParaPalavras(inserido);

        if (strcmp(matrizDeArgumentos[0], "sair") == 0)
            exit(1);
    
        pid = fork();

        if (pid == 0){
            // Se o PID é zero, então esse processo é um processo-filho
            statusExecv = execv(matrizDeArgumentos[0], matrizDeArgumentos[0]);

            for (int j = 0; matrizDeArgumentos[0][j] != '\0'; j++)
                printf("-> %c\n", matrizDeArgumentos[0][j]);
            
            if (statusExecv == -1)
                printf("Comando desconhecido\n");

            return 0;
        } else {
            // Se o PID não é zero, então esse processo é um processo-pai
            waitpid(-1, &statusPid, 0);
        }

        for (i = 0; i < contaPalavras(inserido); i++)
            free(matrizDeArgumentos[i]);
        free(matrizDeArgumentos);        
        free(inserido);
    }

    return 0;
}