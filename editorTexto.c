/* Inclusões*/
#include "editorTexto.h"
#include <stdlib.h>
#include <stdio.h>

/* Constantes */
#define CANCELA_CARACTERE '#'
#define CANCELA_LINHA '\\'
#define CANCELA_PALAVRA '$'
#define SALTA_LINHA '@'
#define MARCA_EOF '~'
#define ESPACO ' '

static bool_t ehCaractereEspecial(dadosItem caractere){
    //Não confiro MARCA_EOF porque ela é conferida anteriormente
    return (caractere == CANCELA_CARACTERE ||
            caractere == CANCELA_LINHA ||
            caractere == CANCELA_PALAVRA ||
            caractere == SALTA_LINHA);
}

static bool_t atingiuLimiteLinha(editorTexto_t * editor){
    if(editor->pilhaLinha->size >= editor->maximoPorLinha ){
        return TRUE;
    }
    return FALSE;
}

editorTexto_t * criaEditor(uint32_t maximoPorLinha){
    editorTexto_t * editor = (editorTexto_t *)malloc(sizeof(editorTexto_t));
    editor->maximoPorLinha = maximoPorLinha;
    editor->pilhaLinha = criarPilha();
    return editor;
}

void imprimirLinha(editorTexto_t * editor){
    dadosItem impressao;
    uint32_t tamanhoTexto = (editor->pilhaLinha->size);
    uint32_t i = tamanhoTexto - 1;
    //Não preciso de deixar espaço para mais 1 pois
    char * textoInvertido = (char *)malloc(sizeof(char) * tamanhoTexto);
    while(popAndReturn(editor->pilhaLinha, &impressao) == TRUE){
        textoInvertido[i--] = impressao;
    }
    for(i = 0; i < tamanhoTexto; i++){
        printf("%c", textoInvertido[i]);
    }
    printf("\n");
    free(textoInvertido);
}

void lerTexto(editorTexto_t * editor){
    dadosItem caractere;
    while((caractere = getchar()) != MARCA_EOF){
        if(caractere == '\n') continue;

        if(ehCaractereEspecial(caractere) == TRUE){
            if(caractere == CANCELA_LINHA){
                liberarPilha(editor->pilhaLinha);
            }
            if(caractere == CANCELA_CARACTERE){
                pop(editor->pilhaLinha);
            }
            if(caractere == SALTA_LINHA){
                imprimirLinha(editor);
            }
            if(caractere == CANCELA_PALAVRA){
                dadosItem caractereRemovido;
                bool_t foiRemovido;
                do{
                    foiRemovido = popAndReturn(editor->pilhaLinha, &caractereRemovido);
                }while(foiRemovido == TRUE && caractereRemovido != ESPACO);
            }
        }else{
            if(atingiuLimiteLinha(editor) == TRUE){
                imprimirLinha(editor);
            }
            push(editor->pilhaLinha, caractere);
        }
    }
    imprimirLinha(editor);
}