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
  equipe_t equipe[10];
  zerarStruct(equipe);
  //Utilizo um contador para referenciar a minha struct, a posição onde os dados devem ser armazenados.
  //A cada vez que uma nova equipe é cadastrada o contador é incrementado, já que sua passagem está sendo feita por referência.
  //Quando o valor dele chega a 10, o cadastramento de equipes é interrrompido.
  // o usuário poderia escolher o mesmo indice duas vezes, implementqar tratamento de erro? hm..
  //variavel de controle para as matrizes que já possuem notas.
  int cadastros_disponiveis = 0;
    do{
      escolha_menu = exibirMenu();
      selecionaMenu(escolha_menu, equipe, &cadastros_disponiveis);
    }while(escolha_menu < 4);
  return EXIT_SUCCESS;
} //Fim main();
