#ifndef PILHA_H
#define PILHA_H
#include <stdint.h>
#include "tipos.h"

typedef char dadosItem;

typedef struct pilha_s{
    void * top;
    uint32_t size;
} pilha_t;

pilha_t * criarPilha(void);
void esvaziarPilha(pilha_t * pilha);
void push(pilha_t * pilha, dadosItem info);
bool_t popAndReturn(pilha_t * pilha, dadosItem *info);
bool_t pop(pilha_t * pilha);
uint32_t size(pilha_t * pilha);
bool_t empty(pilha_t * pilha);
void liberarPilha(pilha_t * pilha);

#endif