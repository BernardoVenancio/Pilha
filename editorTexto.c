/**
 * @file editorTexto.c
 * @brief Arquivo com a implementação do TAD editor de texto utilizando pilha 
 *        para sua manipulação
 * @author Bernardo Venancio
 * @date 2023-12-27
*/

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

/* Funções auxiliares */
/**
 * @brief Função que verifica se um caractere é especial ou não
 * @param caractere Caractere que será feita a verificação
 * @return TRUE se o caractere for um dos caracteres especiais,
 *         ou caso contrário, FALSE
*/
static bool_t ehCaractereEspecial(dadosItem caractere){
    //Não confiro MARCA_EOF porque ela é conferida anteriormente
    return (caractere == CANCELA_CARACTERE ||
            caractere == CANCELA_LINHA ||
            caractere == CANCELA_PALAVRA ||
            caractere == SALTA_LINHA);
}

/**
 * @brief Função que verifica se a linha atual do editor atingiu o limite
 * @param editor Apontador para o editor de texto a ser utilizado
 * @return TRUE caso a linha esteja na capacidade máxima, ou caso contrário,
 *         FALSE
*/
static bool_t atingiuLimiteLinha(editorTexto_t * editor){
    if(editor->pilhaLinha->size >= editor->maximoPorLinha ){
        return TRUE;
    }
    return FALSE;
}

/* Funções exportadas */
/**
 * @brief Função que cria e inicializa um editor
 * @param maximoPorLinha Quantidade de caracteres por linha que o editor criado terá
 * @return Apontador para o local que o editor foi criado e armazenado
*/
editorTexto_t * criaEditor(uint32_t maximoPorLinha){
    editorTexto_t * editor = (editorTexto_t *)malloc(sizeof(editorTexto_t));
    editor->maximoPorLinha = maximoPorLinha;
    editor->pilhaLinha = criarPilha();
    return editor;
}

/**
 * @brief Função que imprime a linha atual do editor
 * @param editor Apontador para o editor de texto a ser utilizado
*/
void imprimirLinha(editorTexto_t * editor){
    dadosItem impressao;
    uint32_t tamanhoTexto = (editor->pilhaLinha->size);
    uint32_t i = tamanhoTexto - 1;
    //Salvo o texto num vetor de char na ordem inversa à da retirada da pilha, devido a natureza
    //da retirada dos itens duma pilha
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

/**
 * @brief Função que lê caracteres do usuário e realiza as operações definidas para o editor de texto
 * @param editor Apontador para o editor de texto a ser utilizado
*/
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