#include <stdio.h>
#include "Pilha.h"
#include "editorTexto.h"

int main() {
    // pilha_t minhaPilha;
    // iniciarPilha(&minhaPilha);

    // int opcao;

    // do {
    //     printf("\n--- Menu ---\n");
    //     printf("1 - Empilhar\n");
    //     printf("2 - Desempilhar\n");
    //     printf("3 - Mostrar tamanho\n");
    //     printf("4 - Sair\n");
    //     printf("Escolha uma opção: ");
    //     scanf("%d", &opcao);

    //     switch (opcao) {
    //         case 1: {
    //             int valor;
    //             printf("Digite o valor a ser empilhado: ");
    //             scanf("%d", &valor);
    //             push(&minhaPilha, valor);
    //             printf("Valor %d empilhado com sucesso.\n", valor);
    //             break;
    //         }
    //         case 2: {
    //             if (!empty(&minhaPilha)) {
    //                 printf("Valor desempilhado: %d\n", pop(&minhaPilha));
    //             } else {
    //                 printf("A pilha está vazia.\n");
    //             }
    //             break;
    //         }
    //         case 3: {
    //             printf("Tamanho da pilha: %u\n", size(&minhaPilha));
    //             break;
    //         }
    //         case 4:
    //             printf("Encerrando o programa.\n");
    //             break;
    //         default:
    //             printf("Opção inválida. Tente novamente.\n");
    //     }
    // } while (opcao != 4);
    // liberarPilha(&minhaPilha);

    editorTexto_t * meuEditor = criaEditor(70);
    lerTexto(meuEditor);

    return 0;
}
