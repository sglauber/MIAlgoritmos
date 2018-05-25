#include "functions.h"
#include <stdio.h>

int main () {
  int escolha_menu;
  conteudo_t apresentacao;
  equipe_t equipe;
  projeto_t projeto;
  celula_t   *inovacao = NULL;
  zerarStruct(&apresentacao);
    do{
      escolha_menu = exibirMenu();
      selecionaMenu(escolha_menu, &apresentacao, &inovacao);
    }while(escolha_menu < 6);
  return EXIT_SUCCESS;
} //End main();
