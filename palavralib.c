#include "palavralib.h"

/*
 * Essa função conta a quantidade de palavras em uma frase
 */
int contaPalavras(char *frase){
    // i = variavel contadora que percorre toda a frase
    // conta = variavel contadora de palavras
    int i, cont;
    for (i = 0, cont = 0; frase[i] != '\0'; i++)
        // cont é incrementado se e apenas se, o caractere atual é alfanumérica, e o próximo é um espaço.
        if (isalpha(frase[i]) && (isspace(frase[i + 1]) || frase[i + 1] == '\0'))
            cont++;
    return cont;
}

char **fraseParaPalavras(char *frase){
    char **matriz;
    int i, j, k, qntPalavras = contaPalavras(frase);
    matriz = (char **) malloc(qntPalavras * sizeof(char *));

    for (i = 0; i < qntPalavras; i++)
        matriz[i] = NULL;

    for (i = 0, j = 0, k = 0; frase[i] != '\0' && k < qntPalavras; i++){
        if (!isspace(frase[i])){
            matriz[k] = (char *) realloc(matriz[k], (j + 1) * sizeof(char));
            matriz[k][j++] = frase[i];
        }

        if (!isspace(frase[i]) && (isspace(frase[i + 1]) || frase[i + 1] == '\0')){
            matriz[k][j] = '\0';
            j = 0;
            k++;
        }
    }

    return matriz;
}