#define MAX 30
#include "functions_headers.h"
#include <stdio.h>
#include <stdlib.h>

//Testando a implementação de structs com unions {}
/*O tamanho de uma union é dado pelo tipo que contém o maior
número de bytes. Os membros dessa union são acessados um por vez.
Sendo assim os membros "restantes" recebem lixo de memória ao seus valores. */

//Elementos onde serão armazenados os conteúdos que compõem a lista encadeada.

tipoCelula *Cabeca = NULL;
tipoCelula *Cauda = NULL;

//Função que executa a exibição e seleção do menu.
int menuSelecao() {
  int escolha_menu;
    printf("Favor selecionar uma opcao");
    printf("\n[1] Cadastramento\n[2] Ler Arquivo\n[3] Mostrar\n[4] Sair\nOpcao: ");
    /* Verifica se o valor digitado foi um inteiro através do retorno do scanf();
     e se a opção digita está dentro do padrão estabelecido. */
    while((scanf("%d",&escolha_menu) != 1) || (escolha_menu < 1 ) || (escolha_menu > 4)) {
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
    case 3:
      mostrarLista();
      break;
    default:
      exit(1);
  }
} //Fim de menuSelecao();

tipoCelula *criaCelula(tipoConteudo Conteudo) {
  tipoCelula *Novo = malloc(sizeof(tipoCelula));
  Novo->Conteudo = Conteudo;
  Novo->Anterior = NULL;
  Novo->Proximo = NULL;
  return (Novo);
} //Fim de *criaCelula();

void cadastraProposta() {
  tipoConteudo codigo = lerCadastro();
  tipoCelula *Novo = criaCelula(codigo);
  if (Cabeca == NULL) {
    Cabeca = Novo;
    Cauda = Cabeca;
  } else {
    Novo->Anterior = Cauda;
    Cauda->Proximo = Novo;
    Cauda = Novo;
  }
}

tipoCelula* PercorrerLista(tipoCelula* Percorrer, int count) {
    while(count > 0 && Percorrer != NULL) {
      // printf ("count:%d value:%d", count, Percorrer->data.iValue);
      Percorrer = Percorrer->Proximo;
      count--;
    }
    // printf ("Returning Percorrer: %p", Percorrer);
    return Percorrer;
} //Fim de cadastraProposta();

tipoConteudo lerCadastro() {
  tipoConteudo Projeto;
  system("clear");
  printf("Digite um codigo para o seu projeto: ");
  fscanf(stdin,"%d",&Projeto.codigo_projeto);
  setbuf(stdin,NULL);
  printf("\nDe um nome ao seu projeto: ");
  fgets(Projeto.nomes.nome_projeto,BUFSIZ,stdin);
  return Projeto;
} //Fim de lerCadastro();

/*  Essa função será utilizada para alocar dinamicamente um vetor para uma string
caso o tamanho da string ultrapasse o tamanho do vetor então essa função deverá ser chamada.
void alocaVetor {} */

void mostrarLista(){
  tipoCelula  *Percorrer = Cabeca;
  // printf ("Inside display...%p\n", Percorrer);
  if (Percorrer == NULL) {
    printf("\nA lista esta vazia.\n");
  } else {
    while(Percorrer != NULL){
      printf("\nCodigo do projeto:  %d",Percorrer->Conteudo.codigo_projeto);
      printf("\nNome do projeto: %s", Percorrer->Conteudo.nomes.nome_projeto);
      Percorrer = Percorrer->Proximo;
    }
  }
}

int buscaPorCodigo(tipoCelula **Celula, int *codigo) {
  tipoCelula *Percorrer;
  Percorrer = *Celula;
  while (Percorrer != NULL) {
    return Percorrer->Conteudo.codigo_projeto == *codigo ? 1 : 0;
  }
  Percorrer = Percorrer->Proximo;
} //End buscaPorCodigo();

void criaArquivo(){
  FILE *file = fopen("arquivo","w");
  if (file == NULL){
    perror("open()");
  } else {
    fclose(file);
  }
} //Fim de criaArquivo();

void lerArquivo() {

}
