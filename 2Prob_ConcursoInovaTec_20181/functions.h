#include "functions_headers.h"
#include <stdio.h>
#include <stdlib.h>

//Testando a implementação de structs com unions {}
/*O tamanho de uma union é dado pelo tipo que contém o maior
número de bytes. Os membros dessa union são acessados um por vez.
Sendo assim os membros "restantes" recebem lixo de memória ao seus valores. */

//Elementos onde serão armazenados os conteúdos que compõem a lista encadeada.

typedef struct {
  union {
    int nome_projeto[30];
    int nome_equipe[30];
  }nomes;
  char  codigo_projeto;
  char* cp;
  char  cbuff[20];
}tipoConteudo;

/*  Elementos de conexão que compõe a lista.
Estes ponteiros são utilizados para "andar"
em ambas as direções através da lista,
informando 'de onde' e 'para onde' estamos nos movendo. */
typedef struct Link {
  struct Lista *Proximo;
  struct Lista *Anterior;
}tipoConector;

//Célula da lista encadeada.
//Função que executa a exibição e seleção do menu.
typedef struct Lista {
  tipoConteudo Conteudo;
  tipoConector Direcao;
}tipoCelula;

tipoCelula *Cabeca = NULL;
tipoCelula *Cauda = NULL;

int menuSelecao() {
  int escolha_menu;
    printf("Favor selecionar uma opcao");
    printf("\n[1] Cadastramento\n[2] Ler Arquivo\n[3] Sair\nOpcao: ");
    //fscanf(stdin, "%d", &escolha_menu);
    //Verifica se o valor digitado foi um inteiro através do retorno do scanf(); e se a opção digita está dentro do padrão estabelecido.
    while((scanf("%d",&escolha_menu) != 1) || (escolha_menu < 1 ) || (escolha_menu > 3)) {
      setbuf(stdin,NULL);
      printf("Selecao invalida. Digite novamente por favor.\n\n");
      printf("Qual sua escolha?: ");
    }
  switch(escolha_menu) {
    case 1:
      cadastraProposta();
      break;
    case 2:
      lerArquivo();
      break;
    default:
      exit(1);
  }
}

tipoCelula *criaCelula(int codigo) {
  tipoCelula *Novo = malloc(sizeof(tipoCelula));
  Novo->Conteudo.codigo_projeto = codigo;
  Novo->Direcao.Anterior = NULL;
  Novo->Direcao.Proximo = NULL;
  return (Novo);
}

void cadastraProposta() {
  int codigo = recebeValor();
  tipoCelula *Novo = criaCelula(codigo);
  if (Cabeca == NULL) {
    *Cabeca = *Novo;
    *Cauda = *Cabeca;
  } else {
    Novo->Direcao.Anterior = Cauda;
    Cauda->Direcao.Proximo = Novo;
    *Cauda = *Novo;
  }
}

int recebeValor() {
  int codigo;
  system("clear");
  printf("Codigo: ");
  fscanf(stdin,"%d",&codigo);
  return codigo;
}

void lerArquivo() {

}
