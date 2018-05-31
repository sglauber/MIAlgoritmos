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

#ifndef FUNCTIONS_HEADERS_H
#define FUNCTIONS_HEADERS_H

#ifdef _WIN32 //Se for Windows ambas arquiteturas x86 e x64
  #define CLEAR system("cls");
#else //In any other OS
  #define CLEAR system("clear");
#endif
#define MAX 256
#include <stdio.h> //a bibliotece é incluída para que assim, o tipo FILE possa ser utilizado.
#include <stdbool.h> //a biblioteca é incluída para qeu assim, o tipo bool possa ser utilizado.

/*  As notas compreendem valores de 0 a 10. Cada coluna do vetor irá
    corresponder a uma nota (critério do jurado) e cada linha corresponde a um jurado.
    Nível de Organização da Equipe na posição [0]
    Estratégia de Venda [1]
    Grau de usabilidade do produto [2]
    Nível de maturidade da área que pretendem atuar [3];
    Grau de inovação do produto [4] */

typedef struct equipes {
  int equipe_id;
  char nome_equipe[MAX];
  char nome_participante[MAX];
}equipe_t;

typedef struct projeto {
  equipe_t equipe;
  int existe_equipe;
  char titulo_projeto[MAX];
  int codigo_projeto;
  //Categorias, será que eu vou usar isso ?
  int tipo_projeto;
  //Este vetor recebe o nome da categoria do projeto.
  char pnome_categoria[15];
  //Contador_categorias[0] será Gestão, contador_categorias[1] Educação, contador_categorias[2] Projetos Sociais.
  int contador_categorias[3];
}projeto_t;

typedef struct conteudoApresentacao {
  equipe_t equipeTeste;
  projeto_t projeto;
}conteudo_t;

/* Célula da lista
Os ponteiros são utilizados para "andar"
em ambas as direções através da lista,
informando 'de onde' e 'para onde' estamos nos movendo. */
typedef struct celula {
  equipe_t  equipeCadastrada;
  projeto_t projetoCadastrado;
  //Em conteudo deverão ser listados os projetos que já possuem equipes.
  conteudo_t    *conteudo;
  struct celula *proximo;
//  struct Celula *Anterior;
}celula_t;

void selecionaMenu();
void zerarStruct();
celula_t* criarCelula();
void inicializarLista();
void criarLista();
int retornaEscolha();
void selecionarOpcaoCadastro();
void cadastrarEquipes();
bool cadastrosDisponiveis();
void escolherCadastramento();
void exibirCategorias();
void cadastrarProjetos();
void exibirCoisas();
bool existeEquipe();
void exibirEquipes();
bool existeProjeto();
void exibirProjetos();
void colocarNaLista();
void copiarAspectosDoProjeto();
void incrementarQuantidadeCategorias();
int escolherCategoria();
bool validarCodigo();
void ingressarProjeto();
void recolherNotas();
FILE *abreArquivo();
void lerArquivo();
celula_t* percorrerLista();

#endif
