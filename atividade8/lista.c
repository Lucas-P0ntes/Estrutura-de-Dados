#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No* L, No* no){
    if(L != NULL){
        if(L->proximo_no == NULL){
            L->proximo_no = no;
        }
        else{
            lista_inserir_no(L->proximo_no, no);
        }
    }
}

void lista_imprimir(No* L){
    if(L != NULL){
        printf("%c ", L->valor);
        lista_imprimir(L->proximo_no);
    }
}

int lista_quantidade_nos(No* L){
    if(L != NULL){
        return 1 + lista_quantidade_nos(L->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* L){
    if(L != NULL){
        return no(L->valor, lista_copiar(L->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* L, No* Lc){
    lista_inserir_no(L, Lc);
}

void lista_liberar(No* L){
    if(L != NULL){
        lista_liberar(L->proximo_no);
        free(L);
    }

    int lista_verificar_existencia(No* L, char valor_busca) {
    while (L != NULL) {
        if (L->valor == valor_busca) {
            return 1; // Valor encontrado
        }
        L = L->proximo_no;
    }
    return 0; // Valor não encontrado
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int ocorrencias = 0;
    while (L != NULL) {
        if (L->valor == valor_busca) {
            ocorrencias++;
        }
        L = L->proximo_no;
    }
    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L != NULL) {
        lista_imprimir_inversa(L->proximo_no);
        printf("%c ", L->valor);
    }
}

void lista_inserir_no_i(No* L, int i) {
    if (i == 0) {
        // Inserir no início da lista
        No* novo_no = no('N', L);
        L = novo_no;
    } else if (i > 0 && L != NULL) {
        lista_inserir_no_i(L->proximo_no, i - 1);
    } else {
        printf("Índice inválido para inserção.\n");
    }
}

void lista_remover_no_i(No* L, int i) {
    if (i == 0 && L != NULL) {
        No* no_a_remover = L->proximo_no;
        if (no_a_remover != NULL) {
            L->proximo_no = no_a_remover->proximo_no;
            free(no_a_remover);
        } else {
            printf("Índice inválido para remoção.\n");
        }
    } else if (i > 0 && L != NULL) {
        lista_remover_no_i(L->proximo_no, i - 1);
    } else {
        printf("Índice inválido para remoção.\n");
    }
}

void lista_remover_no(No* L, char valor_busca) {
    while (L != NULL && L->proximo_no != NULL) {
        if (L->proximo_no->valor == valor_busca) {
            No* no_a_remover = L->proximo_no;
            L->proximo_no = no_a_remover->proximo_no;
            free(no_a_remover);
        } else {
            L = L->proximo_no;
        }
    }
}
}