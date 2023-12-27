/**
 * @file Pilha.c
 * @brief Arquivo com a implementação do TAD Pilha
 * @author Bernardo Venancio
 * @date 2023-12-27
*/

/* Inclusões */
#include <stdlib.h>
#include "Pilha.h"

/* Tipos */
/// Tipo "Item de Pilha", estrutura com os membros de um item de uma pilha
typedef struct node_s{
    dadosItem info;
    struct node_s * next;
} node_t;

/* Funções exportadas */
/**
 * @brief Função que cria e inicializa uma pilha
 * @return Apontador para o local onde a pilha foi criada e armazenada
*/
pilha_t * criarPilha(void){
    pilha_t * pilha = (pilha_t *)malloc(sizeof(pilha_t));
    pilha->top = NULL;
    pilha->size = 0;
    return pilha;
}

/**
 * @brief Função que adiciona um item à pilha
 * @param pilha Apontador para a pilha a ser utilizada
 * @param info  Informação a ser inserida na pilha
*/
void push(pilha_t * pilha, dadosItem info){
    node_t * newNode = (node_t *) malloc(sizeof(node_t));
    newNode->info = info;
    newNode->next = pilha->top;
    pilha->top = newNode;
    pilha->size++;
}

/**
 * @brief Função que remove um item do topo da pilha e o retorna
 * @param pilha Apontador para a pilha a ser utilizada
 * @param item Endereço que receberá o item removido
 * @return TRUE caso o item seja removido, FALSE se não houver item para ser removido
*/
bool_t popAndReturn(pilha_t * pilha, dadosItem *item){
    if(empty(pilha)){
        *item = ' ';
        return FALSE;
    }

    node_t * target = pilha->top;
    pilha->top = target->next;

    *item = target->info;
    free(target);
    pilha->size--;
    return TRUE;
}

/**
 * @brief Função que remove um item do topo da pilha
 * @param pilha Apontador para a pilha a ser utilizada
 * @return TRUE caso o item seja removido, FALSE caso não tenha item para remover
*/
bool_t pop(pilha_t * pilha){
    if(empty(pilha)){
        return FALSE;
    }
    
    node_t * removedItem = pilha->top;
    pilha->top = ((node_t *)pilha->top)->next;

    pilha->size--;
    free(removedItem);
    return TRUE;
}

/**
 * @brief Função que verifica se uma pilha está vazia
 * @param pilha Apontador para a pilha a ser utlizada
 * @return TRUE caso a pilha esteja vazia, ou caso contrário, FALSE
*/
bool_t empty(pilha_t * pilha){
    return (pilha->size == 0);
}

/**
 * @brief Função que retorna o tamanho de uma pilha
 * @param pilha Apontador para a pilha a ser utilizada
 * @return A quantidade de elementos presentes na pilha
*/
uint32_t size(pilha_t * pilha){
    return pilha->size;
}

/**
 * @brief Função que libera a memória dos itens armazenados por uma pilha
 * @param pilha Apontador para a pilha a ser utlizada
*/
void liberarPilha(pilha_t * pilha){
    while(!empty(pilha)){
        node_t * temp = (node_t *)pilha->top;
        pilha->top = ((node_t *)pilha->top)->next;
        pilha->size--;
        free(temp);
    }
}