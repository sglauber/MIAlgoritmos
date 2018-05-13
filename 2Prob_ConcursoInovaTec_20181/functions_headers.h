#ifndef FUNCTIONS_HEADERS_H
#define FUNCTIONS_HEADER_H

typedef struct {
  union {
    char nome_projeto[30];
    char nome_equipe[30];
  }nomes;
  int  codigo_projeto;
  char* cp;
  char  cbuff[20];
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

//void criaCelula();
int menuSelecao();
tipoCelula *criaCelula(tipoConteudo Conteudo);//deve receber uma struct como parametro
void cadastraProposta();
tipoCelula* PercorrerLista(tipoCelula* Percorrer, int count);
tipoConteudo lerCadastro();
void mostrarLista();
int buscaPorCodigo(tipoCelula **Celula, int *codigo);
void criaArquivo();
void lerArquivo();
 #endif
