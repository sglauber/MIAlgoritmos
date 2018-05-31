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

#include "functions_headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> //Para operações incluindo strings
#include <ctype.h> //Quem sabe...

int exibirMenu() {
  printf("\nFavor selecionar uma opção");
  printf("\n[1] Cadastrar Equipe\n[2] Cadastrar Projeto\n[3] Exibir\n[4] Recolher Notas\n[5] Cadastrar Na Lista\n[6]...Sair \nOpção: ");
  return retornaEscolha(1,6);
}
//Cadastramento, podendo ser as equipes ou notas... sei lá. mas precisa adicionar as categorias.
void selecionaMenu(int escolha_menu, equipe_t *equipe, projeto_t *projeto, celula_t **lista_encadeada) {
  /* Verifica se o valor digitado foi um inteiro através do retorno do scanf();
  e se a opção digita está dentro do padrão de escolhas estabelecido. */
  setbuf(stdin,NULL);
  switch(escolha_menu) {
    case 1:
      if(cadastrosDisponiveis(equipe)) {
        cadastrarEquipes(equipe);
      } else {
        printf("Não é possível cadastrar novas equipes.");
      }
    break;
    case 2:
     cadastrarProjetos(projeto, lista_encadeada);
    break;
    case 3:
      exibirCoisas(equipe, projeto, lista_encadeada);
      //Exibir(); Chama funções que exibem as equipes, funções que exibem as notas.
    break;
    case 4:
      recolherNotas();
    break;
    case 5:
      criarLista(projeto, equipe, lista_encadeada);
    break;
    default:
      printf("Saindo...\n");
  }
} //Fim selecionaMenu();


// Inicializando contadores;
void zerarStruct(projeto_t *projeto, equipe_t *equipe) {
  for(int i = 0; i < 3; i++) {
    projeto->contador_categorias[i] = 0;
  }
  equipe->equipe_id = 0;
  projeto->codigo_projeto = 0;
}

void inicializarLista(celula_t **inovacao) {
    *inovacao = NULL;
}

// celula_t *criarCelula() {
//   celula_t  *Novo;
//   Novo = (celula_t*) malloc(sizeof(celula_t));
//   Novo = NULL;
//   return (Novo);
// } //Fim de *criarCelula();

// void criarLista(projeto_t *projeto, equipe_t *equipe, celula_t **inovacao) {
//   printf("ENTROU AQUI!..");
//   celula_t *novo = criarCelula();
//   celula_t  *cabeca = (celula_t*) malloc(sizeof(celula_t));
//   if (cabeca == NULL) {
//     printf("Erro de alocação...\n");
//   }
//     cabeca->equipeCadastrada = *equipe;
//     cabeca->projetoCadastrado = *projeto;
//     cabeca->proximo = NULL;
//   if (novo == NULL) {
//       novo = cabeca;
//   } else {
//       cabeca->proximo = novo;
//       novo = cabeca;
//     }
// }

// void criarLista(projeto_t *projeto, equipe_t *equipe, celula_t **inovacao) {
//   celula_t *novo;
//   novo = (celula_t*) malloc(sizeof(celula_t));
//   if(novo == NULL) {
//     printf("Erro ao alocar memória...\n");
//     //return -1;
//   }
//   novo->projetoCadastrado = *projeto;
//   novo->equipeCadastrada = *equipe;
//   novo->proximo = *inovacao;
//   *inovacao = novo;
// }

void criarLista(projeto_t *projeto, equipe_t *equipe, celula_t **inovacao) {
  celula_t *cabeca;
  celula_t *p_atual;
  cabeca = (celula_t*) malloc(sizeof(celula_t));
  if (cabeca == NULL) {
    puts("Aloc error.");
  }
  cabeca->projetoCadastrado = *projeto;
  cabeca->equipeCadastrada = *equipe;
  cabeca->proximo = NULL;
  if (*inovacao == NULL) {
    *inovacao = cabeca;
  } else {
    p_atual = *inovacao;   /*@ Primeiro elemento*/
    while(p_atual->proximo != NULL) {
      p_atual = p_atual->proximo;
    }
    p_atual->proximo = cabeca;
  }
}

/* Esta função recebe um número máximo e mínimo de opções em um menu e então
verifica se o valor digitado foi um inteiro através do retorno obtido da
função scanf(); se a opção digita for um inteiro a condição passa a testar
as escolha do usuário que devem estar dentro do padrão estabelecido. */
int retornaEscolha(int opcaoMin, int opcaoMax) {
  int opcao_selecionada;
  setbuf(stdin, NULL);
  while((scanf("%d",&opcao_selecionada) != 1) || (opcao_selecionada < opcaoMin) || (opcao_selecionada > opcaoMax)) {
    printf("Seleção inválida. Pode me informar sua escolha novamente?: \n");
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
    case 3:
      exit(EXIT_SUCCESS);//A pessoa poderá cadastrar uma equipe em um projeto, ou uma equipe separadamente.
  }
}

void cadastrarEquipes(equipe_t *equipe) {
  printf("\nDê um nome a sua equipe: ");
  fgets(equipe->nome_equipe,MAX,stdin);
  setbuf(stdin,NULL);
  printf("\nInforme o nome de um participantes: ");
  fgets(equipe->nome_participante,MAX,stdin);
  setbuf(stdin,NULL);
  //escolherCadastramento(equipe);
}

bool cadastrosDisponiveis(equipe_t *equipe) {
  ++equipe->equipe_id;
  //Retorna verdadeiro se houverem "vagas" e falso se não houverem.
  return equipe->equipe_id <= 10 ? true : false;
}

void escolherCadastramento(conteudo_t *equipe) {
  printf("\nOlá! Você acabou de cadastrar uma equipe! Você pode:\n");
  printf("[1] Cadastrar um novo projeto\n[2] Ingressar em um projeto já existente\nOpção: ");
  int choice = retornaEscolha(1,2);
   //recebe char como args verificando se a opção está correta
   switch(choice) {
    case 1:
      exibirCategorias(equipe);
    break;
    case 2:
      ingressarProjeto(equipe);
    break;
  }
}

void exibirCategorias(projeto_t *conteudo) {
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
void copiarAspectosDoProjeto(char nome_categoria[][15], int categoria_escolhida, projeto_t *conteudo) {
      conteudo->tipo_projeto = categoria_escolhida;
      incrementarQuantidadeCategorias(categoria_escolhida, conteudo);
      strcpy(conteudo->pnome_categoria,nome_categoria[categoria_escolhida]);
}

void incrementarQuantidadeCategorias(int categoria_escolhida, projeto_t *conteudo) {
  if(categoria_escolhida == 0) {
    conteudo->contador_categorias[0]++;
  } else if (categoria_escolhida == 1) {
    conteudo->contador_categorias[1]++;
  } else {
    conteudo->contador_categorias[2]++;
  }
}

void cadastrarProjetos(projeto_t *projeto, celula_t **lista_encadeada) {
  int codigo_utilizado;
  exibirCategorias(projeto);
  setbuf(stdin,NULL);
  printf("Hey! você pode me informar um código para o seu projeto? :): ");
  do {
  scanf("%d",&projeto->codigo_projeto);
  setbuf(stdin,NULL);
  codigo_utilizado = validarCodigo(projeto, lista_encadeada);
    if (codigo_utilizado == true) {
      printf("Código inválido\n");
    }
  }while((projeto->codigo_projeto == 0) || codigo_utilizado == true);
  printf("\nVocê também pode dar um nome bacana pra ele, que tal?: ");
  fgets(projeto->titulo_projeto,BUFSIZ,stdin);
  setbuf(stdin,NULL);
}

// Função que realiza a seleção de uma categoria de projeto.
int escolherCategoria(char nome_categoria[][15], int tam) {
  int escolha_categoria;
  CLEAR;
  for (int i = 0; i < tam; i++) {
    printf("\n[%d] - %s",i,nome_categoria[i]);
  }
  printf("\nOpção: ");
  escolha_categoria = retornaEscolha(0,2);
  return escolha_categoria;
}

bool validarCodigo(projeto_t *projeto, celula_t **lista) {
  celula_t *procurando_codigo = *lista;
  printf("ENTREI NA FUNÇÃO\n");
  while (procurando_codigo != NULL) {
    printf("ENTREI NO WHILE\n");
    return procurando_codigo->projetoCadastrado.codigo_projeto == projeto->codigo_projeto ? true : false;
    procurando_codigo = procurando_codigo->proximo;
    }
  }

void ingressarProjeto(celula_t **inovacao) {
  // celula_t *exibe_projetos = *inovacao;
  // while(exibe_projetos != NULL) {
  //   if(exibe_projetos->conteudo->projeto.codigo_projeto == apresentacao->projeto.codigo_projeto) {
  //     exibe_projetos->conteudo->projeto.equipe = apresentacao->projeto.equipe;
  //     break;
  //   }
  //   exibe_projetos = exibe_projetos->proximo;
  // }
}//jogarEquipeNoProjetoDesejado(equipe, codigo_projeto, inovacao);

void exibirCoisas(equipe_t *equipe, projeto_t *projeto, celula_t **lista_encadeada) {
  printf("\n\nOlá! O que você deseja?");
  printf("\n[1] Visualizar as Equipes?\n[2] Visualizar os Projetos\nOpção: ");
  int opcao_selecionada = retornaEscolha(1,3);
  switch (opcao_selecionada) {
    case 1:
      if(existeEquipe(equipe)) {
        exibirEquipes(equipe, lista_encadeada);
      }
    break;
    case 2:
      if(existeProjeto(projeto)) {
        exibirProjetos(projeto, lista_encadeada);
      }
    break;
  }
}

bool existeEquipe(equipe_t *equipe) {
  if (equipe->equipe_id == 0) {
    printf("\nNão existem equipes cadastradas!\n");
  }
  return equipe->equipe_id != 0 ? true : false;
}

bool existeProjeto(projeto_t *projeto) {
  if (projeto->codigo_projeto == 0) {
    printf("\nNão existem projetos cadastrados!\n");
  }
  return projeto->codigo_projeto != 0 ? true : false;
}

void exibirEquipes(equipe_t *equipe, celula_t **lista_encadeada) {
  celula_t *exibe_equipes = *lista_encadeada;
  while(exibe_equipes != NULL) {
    printf("\nID da Equipe: %d", exibe_equipes->equipeCadastrada.equipe_id);
    printf("\nNOME da EQUIPE: %s", exibe_equipes->equipeCadastrada.nome_equipe);
    fprintf(stdout,"NOME PARTICIPANTE: %s", exibe_equipes->equipeCadastrada.nome_participante);
    exibe_equipes = exibe_equipes->proximo;
  }
  if(existeProjeto() == true) {
    printf("Deseja cadastrar sua equipe em algum projeto?\n[1] Ingressar\n[2] Menu Principal");
    retornaEscolha(1,2);
    ingressarProjeto(lista_encadeada);
  }
}

void exibirProjetos(projeto_t *projeto, celula_t **lista_encadeada) {
  celula_t *exibe_projetos = *lista_encadeada;
  if(exibe_projetos == NULL) {
    printf("\nHey! Parece que ainda não há nenhum projeto cadastrado NA LISTAAA..Você será levado de volta ao menu :)");
    exibirMenu();
  } else {
      printf("Acho que temos alguns projetos legais! Você pode adicionar uma equipe a um deles digite o código para selecionar o projeto desejado:)\n");
      while(exibe_projetos != NULL) {
        printf("\nTITULO PROJETO: %s", exibe_projetos->projetoCadastrado.titulo_projeto);
        printf("CODIGO PROJETO: %d\n", exibe_projetos->projetoCadastrado.codigo_projeto);
        printf("TIPO PROJETO NUM: %d\n", exibe_projetos->projetoCadastrado.tipo_projeto);
        printf("NOME CATEGORIA: %s\n", exibe_projetos->projetoCadastrado.pnome_categoria);
        printf("CONTADOR GESTAO: %d\n", exibe_projetos->projetoCadastrado.contador_categorias[0]);
        printf("CONTADOR EDUCACAO: %d\n", exibe_projetos->projetoCadastrado.contador_categorias[1]);
        printf("CONTADOR PSOCIAL: %d\n\n", exibe_projetos->projetoCadastrado.contador_categorias[2]);
        exibe_projetos = exibe_projetos->proximo;
      }
    }
} //Fim de exibirProjetos();

void recolherNotas() {
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
  if (file == NULL) {
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

celula_t *percorrerLista(celula_t *exibe_projetos) {
    int count;
    while(exibe_projetos != NULL) {
      exibe_projetos = exibe_projetos->proximo;
      count++;
    }
    return exibe_projetos;
    // printf ("Returning exibe_projetos: %p", exibe_projetos);
} //Fim de PercorrerLista();
