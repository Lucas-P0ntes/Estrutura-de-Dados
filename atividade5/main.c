#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bubble_sort.h"

void imprimir_arr(char *arr[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso ordena arquivo: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

   // char *outputFile = "arq_palavras_ordenado.txt";

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

   /* FILE *outputFile = fopen(outputFile, "w");
    if (outputFile == NULL) {
        perror("Erro ao criar o arquivo de saída");
        fclose(inputFile);
        return 1;
    }*/

    char palavras[50];
    int tam = 0;
    char buffer[100];

    while (fgets(buffer, sizeof(buffer)/sizeof(char), inputFile) != NULL) {
        //le uma linha do arquivo e armazena em bufferrrr
        int length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
        }

        char *word = strdup(buffer);//duplica a string
        if (word == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }

        palavras[tam] = *word;//armazena a palavra no vetor
        tam++;//incrementa o tamanho do vetor
    }

    fclose(inputFile);

    bubble_sort(palavras, tam);

    imprimir_arr(palavras, tam);

    for (int i = 0; i < i; i++) {
        free(palavras[tam]);
    }

    return 0;

}