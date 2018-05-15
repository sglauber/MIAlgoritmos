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

void selecionaMenu(projeto_t *projeto, celula_t **Cabeca, celula_t **Cauda) {
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
      selecionarOpcaoCadastro(projeto); //Cadastramento, podendo ser as equipes ou notas... sei lá. mas precisa adicionar as categorias.
      break;
    case 2:
      lerArquivo();
      break;
    case 3:
      exibirProjetos(Cabeca); //Exibir(); Chama funções que exibem as equipes, funções que exibem as notas.
      break;
    default:
      exit(EXIT_SUCCESS);
  }
}

// Inicializando contadores;
void zerarStruct(conteudo_t *conteudo) {
  for (int i = 0; i < 2; i++) {
    conteudo->contador_gestao[i] = 0;
    conteudo->contador_educacao[i] = 0;
    conteudo->contador_psocial[i] = 0;
  }
}

celula_t* criarCelula(projeto_t *projeto) {
  celula_t *Novo = malloc(sizeof(celula_t));
  Novo->conteudo->projeto = *projeto;
  Novo->Anterior = NULL;
  Novo->Proximo  = NULL;
  return (Novo);
} //Fim de *criaCelula();

void criarLista(projeto_t *projeto) {
  celula_t *Cabeca = NULL;
  celula_t *Cauda = NULL;
  celula_t *Novo = criarCelula(projeto);
  if (Cabeca == NULL) {
    Cabeca = Novo;
    Cauda = Cabeca;
  }
  else {
    Novo->Anterior = Cabeca;
    Cauda->Proximo = Novo;
    Cauda = Novo;
  }
}

void selecionarOpcaoCadastro(projeto_t *projeto) {
  int seleciona_cadastro;
  CLEAR;
  printf("O que voce deseja cadastrar?\n[1] Equipe\n[2] Projeto\nOpcao: ");
  //printf("Equipes podem ser cadastradas em mais de um projeto :)");
  scanf("%d",&seleciona_cadastro);
  setbuf(stdin,NULL);
  switch (seleciona_cadastro) {
    case 1:
      cadastrarEquipes(projeto);
      break;
    case 2:
      cadastrarProjetos(projeto);
      break;
  }
}

void cadastrarEquipes(projeto_t *equipe) {
  printf("\nDe um nome a sua equipe: ");
  fgets(equipe->equipe.nome_equipe,MAX,stdin);
  setbuf(stdin,NULL);
  printf("\nInforme o nome de um participantes: ");
  fgets(equipe->equipe.nome_participante,MAX,stdin);
  setbuf(stdin,NULL);
  CLEAR;
  escolherCadastramento(equipe);
}

void escolherCadastramento(projeto_t *equipe) {
  int choice;
  printf("Olá! O que você deseja fazer? Você e sua equipe podem:\n");
  printf("[1] Cadastrar um novo projeto\n[2] Ingressar em um já projeto existente\nOpcao: ");
  scanf("%d",&choice);
   //recebe char como args verificando se a opção está correta
   switch(choice){
    case 1:
      exibirCategorias(equipe);
      break;
    case 2:
      ingressarProjeto();
      break;
  }
}

void exibirCategorias(projeto_t *projeto) {
  char nome_categoria[][15] = {
    "Gestao",
    "Educacao",
    "Projeto Social"
  };
  printf("Escolha uma categoria para o seu projeto: ");
  int categoria_escolhida = escolherCategoria(nome_categoria, 3);
  copiarParaVetor(nome_categoria, categoria_escolhida, projeto->pnome_categoria);
  CLEAR;
  cadastrarProjetos(projeto);
} //Fim de cadastrarProjeto();

void cadastrarProjetos(projeto_t *projeto){
  printf("Hey! você pode me informar um código para o seu projeto? :): ");
  scanf("%d",&projeto->codigo_projeto);
  setbuf(stdin,NULL);
  //validaCodigo(projeto.codigo_projeto);
  printf("\nVocê também pode dar um nome bacana pra ele, que tal?: ");
  fgets(projeto->titulo,BUFSIZ,stdin);
  setbuf(stdin,NULL);
  criarLista(projeto);
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
  for (int i = 0; i < tam; i++){
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

int validarCodigo(celula_t *Lista, int numero_procurado) {
  celula_t *Percorrer = Lista;
  if (Percorrer != NULL) {
    while(Percorrer != NULL){
      return Percorrer->conteudo->projeto.codigo_projeto == numero_procurado ? 1 : 0;
    }
    Percorrer = Percorrer->Proximo;
  }
}

/*  Essa função será utilizada para alocar dinamicamente um vetor para uma string
caso o tamanho da string ultrapasse o tamanho do vetor então essa função deverá ser chamada.
void alocaVetor {} */

void ingressarProjeto() {
  int choice;
  printf("Acho que temos alguns projetos legais, para selecionar um de seu interesse, digite o número correspondente ao código dele :)");
  //exibirProjetos(Celula);
  while((scanf("%d", &choice) != 1 || choice < 1 || choice > 2)) {
    printf("Selecao invalida. Digite novamente por favor.\n\n");
    printf("Podemos tentar de novo? Qual projeto deseja selecionar?: ");
  }
}


void exibirProjetos(celula_t **Celula) {
  celula_t  *Percorrer = *Celula;
  // printf ("Inside display...%p\n", Percorrer);
  if (Percorrer == NULL) {
    printf("\nA lista esta vazia.\n");
  } else {
    while(Percorrer != NULL){
      printf("\nCodigo do projeto: %d",Percorrer->conteudo->projeto.codigo_projeto);
      printf("\nNome do projeto: %s", Percorrer->conteudo->projeto.titulo);
      printf("Equipes Participantes");
      Percorrer = Percorrer->Proximo;
    }
  }
} //Fim de mostrarLista();

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

celula_t* percorrerLista(celula_t* Percorrer, int count) {
    while(count > 0 && Percorrer != NULL) {
      // printf ("count:%d value:%d", count, Percorrer->data.iValue);
      Percorrer = Percorrer->Proximo;
      count--;
    }
    // printf ("Returning Percorrer: %p", Percorrer);
    return Percorrer;
} //Fim de PercorrerLista();
