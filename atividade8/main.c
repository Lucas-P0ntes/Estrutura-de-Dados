#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]){
    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));
    No* n3 = no('U', NULL);
    
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);

    lista_imprimir(n0);
    printf("\nQuantidade de nós: %d", lista_quantidade_nos(n0));

    char valor_busca = 'D';
    printf("\nVerificar existência de '%c': %d", valor_busca, lista_verificar_existencia(n0, valor_busca));

    valor_busca = 'C';
    printf("\nOcorrências de '%c': %d", valor_busca, lista_verificar_ocorrencias(n0, valor_busca));

    printf("\nLista em ordem inversa: ");
    lista_imprimir_inversa(n0);

    int i = 2;
    lista_inserir_no_i(n0, i);

    i = 5;
    lista_remover_no_i(n0, i);

    valor_busca = 'C';
    lista_remover_no(n0, valor_busca);

    printf("\nLista após operações:\n");
    lista_imprimir(n0);
    printf("\n");

    lista_liberar(n0);
    n0 = NULL;

    return 0;
}
