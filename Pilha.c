#include <stdlib.h>
#include "Pilha.h"

typedef struct node_s{
    dadosItem info;
    struct node_s * next;
} node_t;


pilha_t * criarPilha(void){
    pilha_t * pilha = (pilha_t *)malloc(sizeof(pilha_t));
    pilha->top = NULL;
    pilha->size = 0;
    return pilha;
}

void push(pilha_t * pilha, dadosItem info){
    node_t * newNode = (node_t *) malloc(sizeof(node_t));
    newNode->info = info;
    newNode->next = pilha->top;
    pilha->top = newNode;
    pilha->size++;
}

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

bool_t empty(pilha_t * pilha){
    return (pilha->size == 0);
}

uint32_t size(pilha_t * pilha){
    return pilha->size;
}

void liberarPilha(pilha_t * pilha){
    while(!empty(pilha)){
        node_t * temp = (node_t *)pilha->top;
        pilha->top = ((node_t *)pilha->top)->next;
        pilha->size--;
        free(temp);
    }
}