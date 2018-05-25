#include "functions_headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> //Para operações incluindo strings
#include <ctype.h> //Quem sabe...

int exibirMenu() {
  printf("\nFavor selecionar uma opção");
  printf("\n[1] Cadastrar Equipe\n[2] Cadastrar Projeto\n[3] Colocar na Lista\n[4] Mostrar Projetos\n[5] Recolher Notas\n[6] Sair\nOpção: ");
  return retornaEscolha(1,6);
}
//Cadastramento, podendo ser as equipes ou notas... sei lá. mas precisa adicionar as categorias.
void selecionaMenu(int escolha_menu, conteudo_t *apresentacao, celula_t **inovacao) {
  /* Verifica se o valor digitado foi um inteiro através do retorno do scanf();
  e se a opção digita está dentro do padrão de escolhas estabelecido. */
  setbuf(stdin,NULL);
  switch(escolha_menu) {
    case 1:
      if(cadastrosDisponiveis(apresentacao)){
        cadastrarEquipes(apresentacao);
      } else {
        printf("Não é possível cadastrar novas equipes.");
      }
      break;
    case 2:
     cadastrarProjetos(apresentacao);
     break;
    case 3:
      colocarNaLista(apresentacao->projeto, inovacao);
      break;
    case 4:
      exibirProjetos(apresentacao, inovacao);
      //Exibir(); Chama funções que exibem as equipes, funções que exibem as notas.
      break;
    case 5:
      recolherNotas();
    default:
      printf("Saindo...\n");
  }
} //Fim selecionaMenu();


// Inicializando contadores;
void zerarStruct(conteudo_t *conteudo) {
    conteudo->contador_gestao = 0;
    conteudo->contador_educacao = 0;
    conteudo->contador_psocial = 0;
    conteudo->projeto.equipe.equipe_id = 0;
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

/* Esta função recebe um número máximo e mínimo de opções em um menu e então
verifica se o valor digitado foi um inteiro através do retorno obtido da
função scanf(); se a opção digita for um inteiro a condição passa a testar
as escolha do usuário que devem estar dentro do padrão estabelecido. */
int retornaEscolha(int opcaoMin, int opcaoMax) {
  int opcao_selecionada;
  while((scanf("%d",&opcao_selecionada) != 1) || (opcao_selecionada < opcaoMin) || (opcao_selecionada > opcaoMax)) {
    printf("Selecao invalida. Pode me informar sua escolha novamente?: \n");
    setbuf(stdin, NULL);
  }
  return opcao_selecionada;
}

void selecionarOpcaoCadastro(conteudo_t *apresentacao, celula_t **inovacao) {
  int seleciona_cadastro;
  printf("O que voce deseja cadastrar?\n[1] Projeto\n[2] Equipe\nOpcao: ");
  //printf("Equipes podem ser cadastradas em mais de um projeto :)");
  //verificarSituacao(&var_controle);
  seleciona_cadastro = retornaEscolha(1,2);
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

void cadastrarEquipes(conteudo_t *equipe) {
  printf("\nDê um nome a sua equipe: ");
  fgets(equipe->projeto.equipe.nome_equipe,MAX,stdin);
  setbuf(stdin,NULL);
  printf("\nInforme o nome de um participantes: ");
  fgets(equipe->projeto.equipe.nome_participante,MAX,stdin);
  setbuf(stdin,NULL);
  //escolherCadastramento(equipe);
}

int cadastrosDisponiveis(conteudo_t *equipe) {
  ++equipe->projeto.equipe.equipe_id;
  //Retorna verdadeiro se houverem "vagas" e falso se não houverem.
  return equipe->projeto.equipe.equipe_id <= 10 ? true : false;
}
void escolherCadastramento(conteudo_t *equipe) {
  printf("Olá! Você acabou de cadastrar uma equipe! Você pode:\n");
  printf("[1] Cadastrar um novo projeto\n[2] Ingressar em um projeto já existente\nOpção: ");
  int choice = retornaEscolha(1,2);
   //recebe char como args verificando se a opção está correta
   switch(choice){
    case 1:
      exibirCategorias(equipe);
      break;
    case 2:
      ingressarProjeto(equipe);
      break;
  }
}

void exibirCategorias(conteudo_t *conteudo) {
  char nome_categoria[][15] = {
    "Gestao",
    "Educacao",
    "Projeto Social"
  };
  printf("Escolha uma categoria para o seu projeto: ");
  int categoria_escolhida = escolherCategoria(nome_categoria, 3);
  copiarAspectosDoProjeto(nome_categoria, categoria_escolhida, conteudo);
  CLEAR;
} //Fim de cadastrarProjeto();

/*  Função que copia o nome de uma categoria selecionada para a estrutura.
    Recebe a matriz e a posição do conteúdo e o da estrutura onde deve ser gravado.*/
void copiarAspectosDoProjeto(char nome_categoria[][15], int categoria_escolhida, conteudo_t *conteudo) {
      conteudo->projeto.tipo_projeto = categoria_escolhida;
      incrementarQuantidadeCategorias(categoria_escolhida, conteudo);
      strcpy(conteudo->projeto.pnome_categoria,nome_categoria[categoria_escolhida]);
}

void incrementarQuantidadeCategorias(int categoria_escolhida, conteudo_t *conteudo){
  if(categoria_escolhida == 0) {
    conteudo->contador_gestao++;
  } else if (categoria_escolhida == 1) {
    conteudo->contador_educacao++;
  } else {
    conteudo->contador_psocial++;
  }
}

void cadastrarProjetos(conteudo_t *conteudo){
  exibirCategorias(conteudo);
  printf("Hey! você pode me informar um código para o seu projeto? :): ");
  scanf("%d",&conteudo->projeto.codigo_projeto);
  setbuf(stdin,NULL);
  //validaCodigo(projeto.codigo_projeto);
  printf("\nVocê também pode dar um nome bacana pra ele, que tal?: ");
  fgets(conteudo->projeto.titulo_projeto,BUFSIZ,stdin);
  setbuf(stdin,NULL);
}

void colocarNaLista(projeto_t *projeto, celula_t *inovacao) {
  printf("Entrou na função");
  celula_t *novo;
  novo = (celula_t*) malloc(sizeof(celula_t));
  if (novo == NULL) {
    printf("Erro de alocação.");
  }
  novo->conteudo->projeto = *projeto;
  novo->proximo = NULL;
  if (inovacao == NULL) {
    inovacao = novo;
  } else {
    novo->proximo = inovacao;
    inovacao = novo;
  }
}

// Função que realiza a seleção de uma categoria de projeto.
int escolherCategoria(char nome_categoria[][15], int tam) {
  int escolha_categoria;
  CLEAR;
  for (int i = 0; i < tam; i++) {
    printf("\n[%d]-%s",i,nome_categoria[i]);
  }
  printf("\nOpção: ");
  escolha_categoria = retornaEscolha(0,2);
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
}

/*  Essa função será utilizada para alocar dinamicamente um vetor para uma string
caso o tamanho da string ultrapasse o tamanho do vetor então essa função deverá ser chamada.
void alocaVetor {} */

void ingressarProjeto(conteudo_t *apresentacao, celula_t **inovacao) {
  celula_t *percorrer = *inovacao;
  while(percorrer != NULL) {
    if(percorrer->conteudo->projeto.codigo_projeto == apresentacao->projeto.codigo_projeto){
      percorrer->conteudo->projeto.equipe = apresentacao->projeto.equipe;
      break;
    }
    percorrer = percorrer->proximo;
  }
}//jogarEquipeNoProjetoDesejado(equipe, codigo_projeto, inovacao);

void exibirProjetos(conteudo_t *apresentacao, celula_t **lista) {
  printf("\nTITULO PROJETO: %s\n", apresentacao->projeto.titulo_projeto);
  printf("CODIGO PROJETO: %d\n", apresentacao->projeto.codigo_projeto);
  printf("TIPO PROJETO NUM: %d\n", apresentacao->projeto.tipo_projeto);
  printf("NOME CATEGORIA: %s\n", apresentacao->projeto.pnome_categoria);
  printf("NOME EQUIPE:    %s\n", apresentacao->projeto.equipe.nome_equipe);
  printf("NOME PARTICIPANTE: %s\n", apresentacao->projeto.equipe.nome_participante);
  printf("GESTAO: %d\n", apresentacao->contador_gestao);
  printf("PSOCIAL: %d\n", apresentacao->contador_psocial);
  printf("EDUCACAO: %d\n", apresentacao->contador_educacao);
  celula_t *percorrer = *lista;
  if (percorrer == NULL) {
    printf("\nHey! Parece que ainda não há nenhum projeto cadastrado...");
    printf("Me conta ai, o que você deseja fazer?\n[1] Cadastrar Novo Projeto\n[2] Voltar ao Menu\nOpção: ");
    int cadastro;
    cadastro = retornaEscolha(1,2);
    switch (cadastro) {
      case 1:
        cadastrarProjetos(apresentacao);
        break;
      default:
        exibirMenu();
    }
  } else {
      printf("Acho que temos alguns projetos legais, para selecionar um de seu interesse, digite o número correspondente ao código dele :)\n");
      while(percorrer != NULL) {
        printf("\nCodigo do projeto: %d", percorrer->conteudo->projeto.codigo_projeto);
        printf("\nNome do projeto: %s", percorrer->conteudo->projeto.titulo_projeto);
        printf("\nEquipes participantes do projeto: %s", percorrer->conteudo->projeto.equipe.nome_equipe);
      }
      percorrer = percorrer->proximo;
      ingressarProjeto(apresentacao, lista);
    }
} //Fim de exibirProjetos();

void recolherNotas(){
  float vetor_notas[5];
  printf("Nível de Organização da equipe: ");
  scanf("%f", &vetor_notas[0]);
  printf("Estratégia de vendas: ");
  scanf("%f", &vetor_notas[1]);
  printf("Grau de usabilidade do produto: ");
  scanf("%f", &vetor_notas[2]);
  printf("Nível de maturidade: ");
  scanf("%f", &vetor_notas[3]);
  printf("Grau de inovação do produto: ");
  scanf("%f", &vetor_notas[4]);
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
  //Concatenando a extensão ao nome do arquivo de texto.
  strcat(nome_arquivo,".txt");
  //abreArquivo(nome_arquivo);
} //Fim de lerArquivo();

celula_t *percorrerLista(celula_t *percorrer) {
    int count;
    while(percorrer != NULL) {
      percorrer = percorrer->proximo;
      count++;
    }
    return percorrer;
    // printf ("Returning percorrer: %p", percorrer);
} //Fim de PercorrerLista();
