#ifndef FUNCTIONS_HEADERS_H
#define FUNCTIONS_HEADERS_H

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

typedef struct equipes {
  char nome_equipe[MAX];
  char nome_participante[MAX];
}equipe_t;

typedef struct projeto {
  equipe_t equipe;
  char titulo_projeto[MAX];
  int codigo_projeto;
  int tipo_projeto; //Categorias
  char pnome_categoria[15];
}projeto_t;

typedef struct conteudoApresentacao {
  projeto_t projeto;
  int contador_gestao[2], contador_educacao[2], contador_psocial[2], verificador;
}conteudo_t;

/* Célula da lista
Os ponteiros são utilizados para "andar"
em ambas as direções através da lista,
informando 'de onde' e 'para onde' estamos nos movendo. */
typedef struct celula {
  conteudo_t    *conteudo;
  struct celula *proximo;
//  struct Celula *Anterior;
}celula_t;

void selecionaMenu();
void zerarStruct();
celula_t* criarCelula();
void criarLista();
int retornaEscolha();
void selecionarOpcaoCadastro();
void cadastrarEquipes();
void verificarSituacao(int *controle);
void escolherCadastramento();
void exibirCategorias();
void cadastrarProjetos();
void colocarNaLista();
void copiarParaVetor(char nome_categoria[][15], int posicao, char *categoria_projeto);
int escolherCategoria(char nome_categoria[][15], int tam);
int validarCodigo();
void ingressarProjeto();
void exibirProjetos();
FILE *abreArquivo();
void lerArquivo();
celula_t* percorrerLista();

#endif
