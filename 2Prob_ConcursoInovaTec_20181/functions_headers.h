#ifndef FUNCTIONS_HEADERS_H
#define FUNCTIONS_HEADER_H

#ifdef _WIN32 //Se for Windows ambas arquiteturas x86 e x64
  #define CLEAR system("cls");
#else //In any other OS
  #define CLEAR system("clear");
#endif
#define MAX 20
#include <stdio.h>

typedef struct Projeto {
  char nome_projeto[MAX];
  int  codigo_projeto;
  int notas_jurados[5][5];
  char categoria_projeto[MAX];
}tipoProjeto;

/*  As notas compreendem valores de 0 a 10. Cada coluna do vetor irá corresponder a uma nota (critério do jurado) e cada linha corresponde a um jurado.
    Nível de Organização da Equipe na posição [0]
    Estratégia de Venda [1]
    Grau de usabilidade do produto [2]
    Nível de maturidade da área que pretendem atuar [3];
    Grau de inovação do produto [4] */

typedef struct Equipes {
  tipoProjeto equipeProjeto;
  char nome_equipe[MAX];
  char nome_participante[MAX];
}tipoEquipe;

typedef struct Conteudo {
  tipoEquipe Equipe;
  tipoProjeto Projeto;
}tipoConteudo;

/* Célula da lista
Os ponteiros são utilizados para "andar"
em ambas as direções através da lista,
informando 'de onde' e 'para onde' estamos nos movendo. */
typedef struct Lista {
  tipoConteudo Conteudo;
  struct Lista *Proximo;
  struct Lista *Anterior;
}tipoCelula;

int selecionaMenu();
tipoCelula *criaCelula(tipoProjeto Projeto);
void selecionaOpcaoCadastro();
void cadastraEquipe();
tipoEquipe lerEquipe();
void cadastraProjeto();
tipoProjeto lerProjeto();
tipoCelula* PercorrerLista(tipoCelula* Percorrer, int count);
tipoProjeto lerCadastro();
void validaCategoria();
int escolheCategoria();
int validaCodigo();
void exibirLista();
int buscaPorCodigo(tipoProjeto CodeFind);
FILE *abreArquivo(char *nome_arquivo);
void lerArquivo();
 #endif
