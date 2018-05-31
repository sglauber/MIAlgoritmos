/*******************************************************************************
Autor: Glauber da S. Santana
Componente Curricular: Algoritmos I
Concluido em: 31/05/2018
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************************************************************************/

#include "functions.h"
#include <stdio.h>

int main () {
  int escolha_menu;
  conteudo_t apresentacao;
  equipe_t equipe;
  projeto_t projeto;
  celula_t  *inovacao = NULL;
//  inicializarLista(&inovacao);
  zerarStruct(&projeto, &equipe);
    do{
      escolha_menu = exibirMenu();
      selecionaMenu(escolha_menu, &equipe, &projeto,  &inovacao);
    }while(escolha_menu < 6);
  return EXIT_SUCCESS;
} //End main();
