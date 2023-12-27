#ifndef EDITOR_TEXTO_H
#define EDITOR_TEXTO_H
#include "tipos.h"
#include "Pilha.h"

typedef struct editorTexto_s{
    uint32_t maximoPorLinha;
    pilha_t * pilhaLinha;
} editorTexto_t;

editorTexto_t * criaEditor(uint32_t maximoPorLinha);
bool_t atingiuLimiteLinha(editorTexto_t * editor);
void lerTexto(editorTexto_t * editor);
#endif