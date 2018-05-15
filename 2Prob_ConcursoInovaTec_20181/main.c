#include "functions.h"
#include <stdio.h>

int main () {
  // Declaração e inicialização dos ponteiros para o inicio e fim da lista.
  celula_t *Cabeca = NULL;
  celula_t *Cauda = NULL;
  //Declaração da struct
  conteudo_t contadores;
  projeto_t projeto;

  zerarStruct(&contadores);
  selecionaMenu(&projeto, &Cabeca, &Cauda);
  return EXIT_SUCCESS;
} //End main();
