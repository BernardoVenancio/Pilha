/**
 * @file editorTexto.h
 * @brief Arquivo com a definição dos tipos e funções relacionadas ao editor de texto utilizando pilha
 * @author Bernardo Venancio
 * @date 2023-12-27
*/

#ifndef EDITOR_TEXTO_H
#define EDITOR_TEXTO_H

/* Inclusões */
#include "tipos.h"
#include "Pilha.h"

/* Tipos */
/// Estrutura com as informações de um editor de texto
typedef struct editorTexto_s{
    uint32_t maximoPorLinha;
    pilha_t * pilhaLinha;
} editorTexto_t;

/* Funções exportadas */
editorTexto_t * criaEditor(uint32_t maximoPorLinha);
bool_t atingiuLimiteLinha(editorTexto_t * editor);
void lerTexto(editorTexto_t * editor);
#endif