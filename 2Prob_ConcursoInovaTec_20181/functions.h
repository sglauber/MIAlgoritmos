#include "functions_headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para operações incluindo strings
#include <ctype.h> //Quem sabe...

//Testando a implementação de structs com unions {}
/*O tamanho de uma union é dado pelo tipo que contém o maior
número de bytes. Os membros dessa union são acessados um por vez.
Sendo assim os membros "restantes" recebem lixo de memória ao seus valores. */

//Elementos onde serão armazenados os conteúdos que compõem a lista encadeada.

tipoCelula *inicializa(tipoCelula *Cabeca, tipoCelula *Cauda){
  tipoCelula Cabeca = NULL;
  tipoCelula Cauda = NULL;
}

tipoCelula *Cabeca = NULL;
tipoCelula *Cauda = NULL;

int selecionaMenu() {
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
      exibirLista(); //Exibir (); Chama funções que exibem as equipes, funções que exibem as notas.
      break;
    default:
      exit(EXIT_SUCCESS);
  }
} //Fim selecionaMenu();

tipoCelula* criaCelula(tipoConteudo Conteudo) {
  tipoCelula *Novo = malloc(sizeof(tipoCelula));
  Novo->Conteudo = Conteudo;
  Novo->Anterior = NULL;
  Novo->Proximo = NULL;
  return (Novo);
} //Fim de *criaCelula();

void selecionaOpcaoCadastro() {
  int seleciona_cadastro;
  printf("O que voce deseja cadastrar?\n[1] Equipe\n[2] Projeto\nOpcao: ");
  scanf("%d",&seleciona_cadastro);
  switch (seleciona_cadastro) {
    case 1:
      cadastraEquipe();
      break;
    case 2:
      cadastraProjeto();
      break;
  }
}

void cadastraEquipe() {

}

void cadastraProjeto() {
  tipoConteudo Conteudo = lerCadastro();
  tipoCelula *Novo = criaCelula(Conteudo);

  if (Cabeca == NULL) {
    Cabeca = Novo;
    Cauda = Cabeca;
  } else {
    Novo->Anterior = Cauda;
    Cauda->Proximo = Novo;
    Cauda = Novo;
  }
} //Fim cadastrarProposta();

tipoCelula* percorrerLista(tipoCelula* Percorrer, int count) {
    while(count > 0 && Percorrer != NULL) {
      // printf ("count:%d value:%d", count, Percorrer->data.iValue);
      Percorrer = Percorrer->Proximo;
      count--;
    }
    // printf ("Returning Percorrer: %p", Percorrer);
    return Percorrer;
} //Fim de PercorrerLista();

tipoConteudo lerCadastro()  {
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

void exibirLista()  {
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
} //Fim de mostrarLista();

int buscaPorCodigo(tipoCelula **Celula, int *codigo) {
  tipoCelula *Percorrer;
  Percorrer = *Celula;
  while (Percorrer != NULL) {
    return Percorrer->Conteudo.codigo_projeto == *codigo ? 1 : 0;
  }
  Percorrer = Percorrer->Proximo;
} //Fim de buscaPorCodigo();

FILE *abreArquivo(char *nome_arquivo){
  FILE *file  = fopen(nome_arquivo,"a+b");
  if (file == NULL){
    printf("Errro!");
  }
  return file;
} //Fim de abreArquivo();

void lerArquivo() {
  char nome_arquivo[MAX];
  puts("\nDigite o nome do arquivo de texto.\n");
  fgets(nome_arquivo,BUFSIZ,stdin);
  strcat(nome_arquivo,".txt") //Concatenando a extensão ao nome do arquivo de texto.
  //abreArquivo(nome_arquivo);
} //Fim de lerArquivo();
