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

tipoCelula* criaCelula(tipoProjeto Projeto) {
  tipoCelula *Novo = malloc(sizeof(tipoCelula));
  Novo->Conteudo.Projeto = Projeto;
  Novo->Anterior = NULL;
  Novo->Proximo = NULL;
  return (Novo);
} //Fim de *criaCelula();

void selecionaOpcaoCadastro() {
  int seleciona_cadastro;
  CLEAR;
  printf("O que voce deseja cadastrar?\n[1] Equipe\n[2] Projeto\nOpcao: ");
  scanf("%d",&seleciona_cadastro);
  setbuf(stdin,NULL);
  switch (seleciona_cadastro) {
    case 1:
      cadastraEquipe();
      break;
    case 2:
      cadastraProjeto();
      break;
  }
}

void cadastraEquipe(){
  lerEquipe();
}

tipoEquipe lerEquipe() {
  tipoEquipe Equipe;
  printf("\nDe um nome a sua equipe: ");
  fgets(Equipe.nome_equipe,BUFSIZ,stdin);
  setbuf(stdin,NULL);
  printf("\nAdicione um participantes: ");
  fgets(Equipe.nome_participante,BUFSIZ,stdin);
  setbuf(stdin,NULL);
  return Equipe;
}

void cadastraProjeto() {
  tipoProjeto Conteudo = lerProjeto();
  tipoCelula *Novo = criaCelula(Conteudo);
  int verifica = buscaPorCodigo(Conteudo);
    if (Cabeca == NULL) {
      Cabeca = Novo;
      Cauda = Cabeca;
    } else {
      Novo->Anterior = Cauda;
      Cauda->Proximo = Novo;
      Cauda = Novo;
    }
  }
} //Fim cadastrarProposta();

tipoProjeto lerProjeto() {
  tipoProjeto Projeto;
  CLEAR;
  validaCategoria(Projeto.categoria_projeto);
  printf("Digite um codigo para o seu projeto: ");
  fscanf(stdin,"%d",&Projeto.codigo_projeto);
  setbuf(stdin,NULL);
  validaCodigo(Projeto.codigo_projeto);
  printf("\nDe um nome ao seu projeto: ");
  fgets(Projeto.nome_projeto,BUFSIZ,stdin);
  setbuf(stdin,NULL);
  return Projeto;
} //Fim de lerCadastro();

void validaCategoria(char *nome_categoria) {
  int categoria = escolheCategoria();
  switch (categoria) {
    case 1:
      strcpy(nome_categoria,"Gestao");
      break;
    case 2:
      strcpy(nome_categoria,"Educacao");
      break;
    case 3:
      strcpy(nome_categoria,"Projeto Social");
      break;
  }
}

int escolheCategoria() {
  int escolha_categoria;
  printf("Escolha uma categoria para seu projeto.\n");
  printf("[1] Gestao\n[2] Educacao\n[3] Projeto Social\nOpcao: ");
  while ((scanf("%d",&escolha_categoria) != 1) || (escolha_categoria < 1) || (escolha_categoria > 3)) {
    setbuf(stdin,NULL);
    CLEAR;
    printf("Selecao invalida. Digite novamente por favor.\n\n");
    printf("Qual sua escolha?: ");
  }
  return escolha_categoria;
}

int validaCodigo() {

}

/*  Essa função será utilizada para alocar dinamicamente um vetor para uma string
caso o tamanho da string ultrapasse o tamanho do vetor então essa função deverá ser chamada.
void alocaVetor {} */

void exibirLista() {
  tipoCelula  *Percorrer = Cabeca;
  // printf ("Inside display...%p\n", Percorrer);
  if (Percorrer == NULL) {
    printf("\nA lista esta vazia.\n");
  } else {
    while(Percorrer != NULL){
      printf("\nCodigo do projeto: %d",Percorrer->Conteudo.Projeto.codigo_projeto);
      printf("\nNome do projeto: %s", Percorrer->Conteudo.Projeto.nome_projeto);
      printf("\nCategoria do projeto: %s",Percorrer->Conteudo.Projeto.categoria_projeto);
      printf("\nNome da equipe: %s",Percorrer->Conteudo.Equipe.nome_equipe);
      printf("\nParticipante: %s\n",Percorrer->Conteudo.Equipe.nome_participante);
      Percorrer = Percorrer->Proximo;
    }
  }
} //Fim de mostrarLista();

int buscaPorCodigo(tipoProjeto CodeFind) {
    tipoCelula *Percorrer;
    Percorrer = Cabeca;
    while (Percorrer != NULL) {
      if (Percorrer->Conteudo.Projeto.codigo_projeto == CodeFind.codigo_projeto) {
        return 1;
    } else {
        return 0;
    }
    Percorrer = Percorrer->Proximo;
  }
} //Fim de buscaPorCodigo();

void find() {
  int pos = getPosition();
  Node* iter = traverse(lhead, pos);
  if (iter == NULL) {
    printf("\n No such position");
  }
  else {
    Node* prevNode = iter->linkTo.prev;
    Node* nextNode = iter->linkTo.next;
    int iterValue = iter->data.iValue;
    int prevValue = (prevNode != NULL)? prevNode->data.iValue : -1;
    int nextValue = (nextNode != NULL)? nextNode->data.iValue : -1;
    printf("\nThe data around the position are %d %d %d\n", prevValue, iterValue, nextValue);
  }
}

FILE *abreArquivo(char *nome_arquivo) {
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
  setbuf(stdin,NULL);
  strcat(nome_arquivo,".txt"); //Concatenando a extensão ao nome do arquivo de texto.
  //abreArquivo(nome_arquivo);
} //Fim de lerArquivo();

tipoCelula* percorrerLista(tipoCelula* Percorrer, int count) {
    while(count > 0 && Percorrer != NULL) {
      // printf ("count:%d value:%d", count, Percorrer->data.iValue);
      Percorrer = Percorrer->Proximo;
      count--;
    }
    // printf ("Returning Percorrer: %p", Percorrer);
    return Percorrer;
} //Fim de PercorrerLista();
