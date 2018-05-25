#include "functions.h"
#include <stdio.h>

int main () {
  int escolha_menu;
  conteudo_t *apresentacao;
  celula_t   *inovacao = NULL;
  zerarStruct(apresentacao);
    do{
      escolha_menu = exibirMenu();
      selecionaMenu(escolha_menu, apresentacao, &inovacao);
    }while(escolha_menu < 5);
  return EXIT_SUCCESS;
} //End main();
