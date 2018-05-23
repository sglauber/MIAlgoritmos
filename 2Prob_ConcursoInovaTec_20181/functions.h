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

// Inicializando contadores;
void zerarStruct(conteudo_t *conteudo) {
  for (int i = 0; i < 2; i++) {
    conteudo->contador_gestao[i] = 0;
    conteudo->contador_educacao[i] = 0;
    conteudo->contador_psocial[i] = 0;
  }
}

celula_t *criarCelula() {
  celula_t  *Novo;
  Novo = (celula_t*) malloc(sizeof(celula_t));
  Novo->conteudo = NULL;
  Novo->proximo  = NULL;
  return (Novo);
} //Fim de *criarCelula();

void criarLista(projeto_t *projeto, celula_t *inovacao) {
  celula_t *novo = criarCelula();
  if (inovacao == NULL) {
    inovacao = novo;
  } else {
    novo->proximo = inovacao;
    novo = inovacao;
  }
}

void selecionarOpcaoCadastro(conteudo_t *apresentacao, celula_t **inovacao) {
  int seleciona_cadastro;
  int var_controle = 0;
  CLEAR;
  printf("O que voce deseja cadastrar?\n[1] Projeto\n[2] Equipe\nOpcao: ");
  //printf("Equipes podem ser cadastradas em mais de um projeto :)");
  verificarSituacao(&var_controle);
  scanf("%d",&seleciona_cadastro);
  setbuf(stdin,NULL);
  switch (seleciona_cadastro) {
    case 1:
      cadastrarProjetos(apresentacao, inovacao);
      break;
    case 2:
      cadastrarEquipes(apresentacao, inovacao);
      break;
  }
}

void cadastrarEquipes(conteudo_t *conteudo, celula_t **inovacao) {
  printf("\nDê um nome a sua equipe: ");
  fgets(conteudo->projeto.equipe.nome_equipe,MAX,stdin);
  setbuf(stdin,NULL);
  printf("\nInforme o nome de um participantes: ");
  fgets(conteudo->projeto.equipe.nome_participante,MAX,stdin);
  setbuf(stdin,NULL);
  CLEAR;
  escolherCadastramento(conteudo, inovacao);
}

void escolherCadastramento(conteudo_t *conteudo, celula_t **inovacao) {
  int choice;
  printf("Olá! O que você deseja fazer? Você e sua equipe podem:\n");
  printf("[1] Cadastrar um novo projeto\n[2] Ingressar em um projeto já existente\nOpcao: ");
  scanf("%d",&choice);
   //recebe char como args verificando se a opção está correta
   switch(choice){
    case 1:
      exibirCategorias(conteudo, inovacao);
      break;
    case 2:
      ingressarProjeto(conteudo, inovacao);
      break;
  }
}

void verificarSituacao(int *controle) {
  //Esta função recebe como parâmetro uma variável de controle e modifica o seu valor se esta for 0;
}

void exibirCategorias(conteudo_t *conteudo, celula_t **inovacao) {
  char nome_categoria[][15] = {
    "Gestao",
    "Educacao",
    "Projeto Social"
  };
  printf("Escolha uma categoria para o seu projeto: ");
  int categoria_escolhida = escolherCategoria(nome_categoria, 3);
  copiarParaVetor(nome_categoria, categoria_escolhida, conteudo->projeto.pnome_categoria);
  CLEAR;
  cadastrarProjetos(conteudo, &inovacao);
} //Fim de cadastrarProjeto();

void cadastrarProjetos(conteudo_t *conteudo, celula_t *inovacao){
  printf("Hey! você pode me informar um código para o seu projeto? :): ");
  scanf("%d",&conteudo->projeto.codigo_projeto);
  setbuf(stdin,NULL);
  //validaCodigo(projeto.codigo_projeto);
  printf("\nVocê também pode dar um nome bacana pra ele, que tal?: ");
  fgets(conteudo->projeto.titulo_projeto,BUFSIZ,stdin);
  setbuf(stdin,NULL);
}

/*  Função que copia o nome de uma categoria selecionada para a estrutura.
    Recebe a matriz e a posição do conteúdo e o da estrutura onde deve ser gravado.*/
void copiarParaVetor(char nome_categoria[][15], int posicao, char *categoria_projeto) {
      strcpy(categoria_projeto,nome_categoria[posicao]);
}

// Função que realiza a seleção de uma categoria de projeto.
int escolherCategoria(char nome_categoria[][15], int tam) {
  int escolha_categoria;
  CLEAR;
  for (int i = 0; i < tam; i++) {
    printf("\n[%d]-%s",i+1,nome_categoria[i]);
  }
  printf("\nOpção: ");
  while ((scanf("%d",&escolha_categoria) != 1) || (escolha_categoria < 1) || (escolha_categoria > 3)) {
    setbuf(stdin,NULL);
    CLEAR;
    printf("Seleção inválida. Digite novamente por favor.\n\n");
    printf("Qual sua escolha?: ");
  }
  return escolha_categoria;
}

int validarCodigo(celula_t *inovacao, int numero_procurado) {
  celula_t *percorrer = inovacao;
  if (percorrer != NULL) {
    while(percorrer != NULL) {
      return percorrer->conteudo->projeto.codigo_projeto == numero_procurado ? 1 : 0;
    }
    percorrer = percorrer->proximo;
  }
  return 1;
}

/*  Essa função será utilizada para alocar dinamicamente um vetor para uma string
caso o tamanho da string ultrapasse o tamanho do vetor então essa função deverá ser chamada.
void alocaVetor {} */

void ingressarProjeto(conteudo_t *conteudo, celula_t **inovacao) {
  int choice;
  exibirProjetos(inovacao);
  while ((scanf("%d", &choice) != 1 || choice < 1 || choice > 2)) {
    printf("Selecao invalida. Digite novamente por favor.\n\n");
    printf("Podemos tentar de novo? Qual projeto deseja selecionar?: ");
  }
  //jogarEquipeNoProjetoDesejado(equipe, codigo_projeto, inovacao);
}

void exibirProjetos(celula_t **lista) {
  celula_t *percorrer = *lista;
  if (percorrer == NULL) {
    printf("\nNenhum projeto foi adicionado a lista ainda. Deseja cadastrar um novo ? :)\n");
  } else {
    printf("Acho que temos alguns projetos legais, para selecionar um de seu interesse, digite o número correspondente ao código dele :)\n");
  }
  while(percorrer != NULL){
    printf("\nCodigo do projeto: %d", percorrer->conteudo->projeto.codigo_projeto);
    printf("\nNome do projeto: %s", percorrer->conteudo->projeto.titulo_projeto);
    printf("Equipes Participantes");
    percorrer = percorrer->proximo;
  }
} //Fim de exibirProjetos();

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

celula_t* percorrerLista(celula_t* percorrer, int count) {
    while(count > 0 && percorrer != NULL) {
      // printf ("count:%d value:%d", count, percorrer->data.iValue);
      percorrer = percorrer->proximo;
      count--;
    }
    // printf ("Returning percorrer: %p", percorrer);
    return percorrer;
} //Fim de PercorrerLista();
