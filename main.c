#include <stdio.h>
#include "Pilha.h"
#include "editorTexto.h"

int main() {
    editorTexto_t * meuEditor = criaEditor(70);
    lerTexto(meuEditor);

    return 0;
}
