#ifndef FUNCTIONS_HEADERS_H
#define FUNCTIONS_HEADER_H

#ifdef _WIN32 //Se for Windows ambas arquiteturas x86 e x64
  #define CLEAR system("cls");
#else //In any other OS
  #define CLEAR system("clear");
#endif
#define MAX 256
#include <stdio.h>

/*  As notas compreendem valores de 0 a 10. Cada coluna do vetor irá corresponder a uma nota (critério do jurado) e cada linha corresponde a um jurado.
    Nível de Organização da Equipe na posição [0]
    Estratégia de Venda [1]
    Grau de usabilidade do produto [2]
    Nível de maturidade da área que pretendem atuar [3];
    Grau de inovação do produto [4] */

typedef struct Equipes {
  char nome_equipe[MAX];
  char nome_participante[MAX];
}equipe_t;

typedef struct Projeto {
  equipe_t equipe;
  char titulo[MAX];
  int codigo_projeto;
  int tipo_projeto; //Categorias
  char pnome_categoria[15];
}projeto_t;

typedef struct ConteudoApresentacao {
  projeto_t projeto;
  int contador_gestao[2], contador_educacao[2], contador_psocial[2];
}conteudo_t;

/* Célula da lista
Os ponteiros são utilizados para "andar"
em ambas as direções através da lista,
informando 'de onde' e 'para onde' estamos nos movendo. */
typedef struct Celula {
  conteudo_t    *conteudo;
  struct Celula *Proximo;
  struct Celula *Anterior;
}celula_t;

void selecionaMenu();
void zerarStruct();
celula_t* criarCelula();
void criarLista();
void selecionarOpcaoCadastro();
void cadastrarEquipes();
void escolherCadastramento();
void exibirCategorias();
void cadastrarProjetos();
void copiarParaVetor();
int escolherCategoria();
int validarCodigo();
void ingressarProjeto();
void exibirProjetos();
FILE *abreArquivo();
void lerArquivo();
celula_t* percorrerLista();
#endif
