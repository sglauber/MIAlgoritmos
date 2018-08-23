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
#define MAX 64
#include <stdio.h> //a bibliotece é incluída para que assim, o tipo FILE possa ser utilizado.
#include <stdbool.h> //a biblioteca é incluída para qeu assim, o tipo bool possa ser utilizado.

/*  As notas compreendem valores de 0 a 10. Cada coluna do vetor irá
    corresponder a uma nota (critério do jurado) e cada linha corresponde a um jurado.
    Nível de Organização da Equipe na posição [0]
    Estratégia de Venda [1]
    Grau de usabilidade do produto [2]
    Nível de maturidade da área que pretendem atuar [3];
    Grau de inovação do produto [4] */

//COmo eu já tinha 3 structs prontas, provindas da implementação com lista encadeada eu só reaproveitei e modifiquei algumas pequenas coisas.
//Colocar imagem ?

typedef struct notas {
  float nivel_organizacao;
  float estrategia_vendas;
  float grau_usabilidade;
  float nivel_maturidade;
  float grau_inovacao;
}jurados_t;

typedef struct projeto {
  char titulo_projeto[MAX];
  int codigo_projeto;
  //Categorias, será que eu vou usar isso ?
  int tipo_projeto;
  //Este vetor recebe o nome da categoria do projeto.
  char pnome_categoria[15];
  //Contador_categorias[0] será Gestão, contador_categorias[1] Educação, contador_categorias[2] Projetos Sociais.
  jurados_t jurados[5];
  float media[5];
  float geral;
}projeto_t;

typedef struct equipes {
  int equipe_id;
  int controle;
  char nome_equipe[MAX];
  char nome_participante[MAX];
  projeto_t projeto;
}equipe_t;

int  exibirMenu();
void selecionaMenu(int n, equipe_t *stream, int *);
void zerarStruct(equipe_t *vetor);
int  retornarEscolha(int min, int max);
void cadastrarEquipes(equipe_t *stream, int n);
bool validarNome(char *str);
void tudoMaiusculo(char *str);
void cadastrarProjetos(equipe_t *stream, int n);
bool codigoValido(equipe_t *stream, int n);
void selecionarCategoria(equipe_t *stream, int n);
void incrementarQuantidadeCategorias();
bool existeProjeto(equipe_t *stream);
void exibirTestes(equipe_t *stream, int*);
void exibirProjetos(equipe_t *stream, int*);
void exibirRanking();
void selecionaProjeto(equipe_t *stream, int*);
void recolherNotas(equipe_t *stream, int n);
float retornaNota();
void calcularMedia(equipe_t *stream, int n);
void organizarRanking(equipe_t *stream, int *);
FILE *abreArquivo();
void lerArquivo();
void saidaArquivo();



#endif
