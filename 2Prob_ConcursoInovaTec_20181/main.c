#include "functions.h"
#include <stdio.h>

int main () {
  tipoCelula *Cabeca = NULL;
  tipoCelula *Cauda = NULL;
  int escolha_menu;
  

  printf("Favor selecionar uma opcao");
  printf("\n[1] Cadastramento\n[2] Ler Arquivo\n[3] Mostrar\n[4] Sair\nOpcao: ");
  /* Verifica se o valor digitado foi um inteiro através do retorno do scanf();
  e se a opção digita está dentro do padrão de escolhas estabelecido. */
  while((scanf("%d",&escolha_menu) != 1) || (escolha_menu < 1 ) || (escolha_menu > 4)) {
    setbuf(stdin,NULL);
    CLEAR;
    printf("Selecao invalida. Digite novamente por favor.\n\n");
    printf("Qual sua escolha?: ");
  }
  switch(escolha_menu) {
    case 1:
      selecionaOpcaoCadastro(); //Cadastramento, podendo ser as equipes ou notas... sei lá. mas precisa adicionar as categorias.
      break;
    case 2:
      lerArquivo();
      break;
    case 3:
      exibirLista(); //Exibir(); Chama funções que exibem as equipes, funções que exibem as notas.
      break;
    default:
      exit(EXIT_SUCCESS);
  }
  return EXIT_SUCCESS;
} //End main();



























} //Fim da main();
