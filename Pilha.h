/**
 * @file Pilha.h
 * @brief Arquivo com a definição dos tipos e funções relacionadas a pilha
 * @author Bernardo Venancio
 * @date 2023-12-27
*/

#ifndef PILHA_H
#define PILHA_H

/* Inclusões */
#include <stdint.h>
#include "tipos.h"

/* Tipos */
/// Tipo armazenado na pilha
typedef char dadosItem;

/// Estrutura com as informações de uma pilha
typedef struct pilha_s{
    void * top;
    uint32_t size;
} pilha_t;

/* Funções exportadas*/
pilha_t * criarPilha(void);
void push(pilha_t * pilha, dadosItem info);
bool_t popAndReturn(pilha_t * pilha, dadosItem *info);
bool_t pop(pilha_t * pilha);
uint32_t size(pilha_t * pilha);
bool_t empty(pilha_t * pilha);
void liberarPilha(pilha_t * pilha);

#endif