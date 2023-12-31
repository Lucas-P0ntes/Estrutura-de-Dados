#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>

typedef struct Ponto{
    int x;
    float y;
} Ponto;

// void imprimeLista(Ponto* p) {
//     printf("%d, %.1f\n", p->x, p->y);
// }

int main(int argc, char* argv[]) {

    int mediaX = 0;
    int somaX = 0;

    float mediaY = 0;
    float somaY = 0;

    float somatorio1 = 0;
    float somatorio2 = 0;

    float inclinacao = 0;

    float intercepcao = 0;


    FILE *csvFile = fopen(argv[1], "r");

    if(csvFile == NULL) {
        fprintf(stderr, "Arquivo %s nao existe\n", argv[1]);
        return 1;
    }

    Ponto* pontos = NULL;  // Ponteiro para o array de pontos
    int capacidade = 10;   // Tamanho inicial da array
    int tamanho = 0;       // Número de elementos atual

    pontos = malloc(capacidade * sizeof(Ponto)); 

    if (pontos == NULL) {
        fprintf(stderr, "Erro na alocacao de memoria\n");
        return 1;
    }

    Ponto ponto;

    while (fscanf(csvFile, "%d, %f", &ponto.x, &ponto.y) == 2) {
        if (tamanho >= capacidade) {
            capacidade *= 2;  // Dobra a capacidade
            pontos = realloc(pontos, capacidade * sizeof(Ponto));
            if (pontos == NULL) {
                fprintf(stderr, "Erro na realocacao de memoria\n");
                return 1;
            }
        }
        pontos[tamanho++] = ponto;
    }

    fclose(csvFile);

    // for (int i = 0; i < tamanho; i++) {
    //     imprimeLista(&pontos[i]);
    // }

    //imprimeLista(&pontos[0]);

    for(int i = 0; i < tamanho; i++) {
        somaX = somaX + pontos[i].x;
        somaY = somaY + pontos[i].y;
    }

    //printf("%d", tamanho);

    mediaX = somaX / tamanho;
    mediaY = somaY / tamanho;

    //printf("%d\n", mediaX);
    //printf("%.1f", mediaY);

    for(int i = 1; i < tamanho; i++) {
        somatorio1 = (pontos[i].x - mediaX) * (pontos[i].y - mediaY);
    }

    for(int i = 1; i < tamanho; i++) {
        somatorio2 = pow((pontos[i].x - mediaX), 2);
    }

    inclinacao = somatorio1 / somatorio2;
    //printf("%.1f\n", inclinacao);

    intercepcao = mediaY - inclinacao * mediaX;

    printf("y = %.1fx + %1.f", inclinacao, intercepcao);

    free(pontos);  // Libera a memória alocada
    return 0;

}