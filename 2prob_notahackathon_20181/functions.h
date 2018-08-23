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
#include <stdbool.h> //Para operações com valores booleanos, esta biblioteca define MACROS para false e true.
#include <string.h> //Para operações incluindo strings
#include <ctype.h>

//Função que exibe um menu e retorna a escolha do usuário.
int exibirMenu() {
  setbuf(stdin,NULL);
  printf("\nBem-Vindo!\nDiga-me o que deseja fazer?:");
  printf("\n[1] Cadastrar Projeto\n[2] Recolher Notas\n[3] Escrever no arquivo\n[4]Sair...\nOpção: "); //só calcular a media quando a pessoa escolher (sair)/finalizar;
  return retornarEscolha(1,4);
}
//Função de roteamento, de acordo com o retorno de exibirMenu(), esta função selecionará uma opção através de um switch ();
void selecionaMenu(int escolha_menu, equipe_t equipe[], int *cadastros_disponiveis) {
  setbuf(stdin, NULL);
  int pos = *cadastros_disponiveis;
  switch(escolha_menu) {
    case 1:
        // Verificando se há cadastros diponíveis a serem feitos.
        if(*cadastros_disponiveis < 10) {
          cadastrarEquipes(equipe, pos);
          *cadastros_disponiveis += 1;
        } else {
          printf("Não é possível realizar novos cadastros.");
        }
    break;
    case 2:
      //Aplicando tratamento de erro para tentativa de exibição de cadastros disponíveis no caso de nenhum cadastro ter sido realizado.
      if(*cadastros_disponiveis != 0) {
        selecionaProjeto(equipe, cadastros_disponiveis);
      } else {
        printf("\nAinda não há projetos cadastrados.");
      }
    break;
    case 3:
      if(equipe[0].controle == 0) {
        printf("Sem ranking até agora");
      } else {
        exibirRanking(equipe, cadastros_disponiveis);
      }
    break;
    default:
      printf("Aqui vou eu! :) Saindo...\n");
  }
} //Fim selecionaMenu();

// Função para inicializar os valores de uma estrutura, impedindo assim os problemas devido ao lixo de memória.
void zerarStruct(equipe_t equipe[]) {
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 5; j++) {
      equipe[i].projeto.jurados[j].nivel_organizacao = 0;
      equipe[i].projeto.jurados[j].estrategia_vendas = 0;
      equipe[i].projeto.jurados[j].grau_usabilidade = 0;
      equipe[i].projeto.jurados[j].nivel_maturidade = 0;
      equipe[i].projeto.jurados[j].grau_inovacao = 0;
    }
    equipe[i].equipe_id = 0;
    equipe[i].projeto.codigo_projeto = 0;
    equipe[i].projeto.tipo_projeto = 0;
    equipe[i].controle = 0;
  }
}

/* Esta função recebe um número máximo e mínimo de opções em um menu e então
verifica se o valor digitado foi um inteiro através do retorno obtido da
função scanf(); se a opção digita for um inteiro a condição passa a testar
as escolha do usuário que devem estar dentro do padrão estabelecido. */
//Ela então retornará a opção escolhida pelo usuário.
int retornarEscolha(int opcao_min, int opcao_max) {
  int opcao_escolhida;
  while((scanf("%d", &opcao_escolhida) != 1) || (opcao_escolhida < opcao_min) || (opcao_escolhida > opcao_max)) {
    printf("Hey! Parece que você digitou um valor inválido.");
    printf("\nPerceba que sua escolha é delimitada, ela deve estar entre [%d] e [%d]", opcao_min, opcao_max);
    printf("\nDigite sua escolha novamente: ");
    setbuf(stdin, NULL);
  }
  return opcao_escolhida;
}

//Esta função deve cadastrar uma equipe, ela recebe um vetor da estrutura, e sua posição.
//Roteia as devidas atividades para suas respectivas funções, fazendo com que, apenas exibições e algumas verificações sejam feitas em seu escopo.
void cadastrarEquipes(equipe_t equipe[], int pos) {
  printf("\nDê um nome a sua equipe: ");
  while((validarNome(fgets(equipe[pos].nome_equipe, MAX, stdin))) == false) {
    setbuf(stdin, NULL);
    printf("O nome não pode conter números e deve ter mais que 3 caracteres.\n");
  }
  tudoMaiusculo(equipe[pos].nome_equipe);
  setbuf(stdin, NULL);
  printf("Entre com o nome do líder da equipe: ");
  while((validarNome(fgets(equipe[pos].nome_participante, MAX, stdin))) == false) {
    setbuf(stdin, NULL);
    printf("O nome não pode conter números e deve ter mais que 3 caracteres.\n");
  }
  tudoMaiusculo(equipe[pos].nome_participante);
  cadastrarProjetos(equipe, pos);
}

// A função recebe uma string, e verifica se nela há um número, caso esta string possua um numeral a função retorna false invalidando a entrada do usuário.
// Ela também verifica se essa string tem no mínimo 3 caracteres válidos.
bool validarNome(char string[]) {
  int tamanho = strlen(string) - 1;
  int eh_valido = 1;
  char num[] = {'0','1','2','3','4','5','6','7','8','9'};
  if(tamanho < 4) {
    return false;
  }
  for(int i = 0; i < tamanho; i++) {
    for(int j = 0; j < 10; j++){
      if (string[i] == num[j]) {
        eh_valido = 0;
      }
    }
  }
  return eh_valido == 0 ? false : true;
}

// Função que recebe uma string e converte todos os seu caracteres em caixa baixa para CAIXA ALTA.
void tudoMaiusculo(char string[]) {
  int t = strlen(string) - 1;
  char lower[] = "abcdefghijklmnopqrstuvwxyz";
  char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i = 0; i < t; i++) {
    for(int j = 0; j < 25; j++) {
      if(string[i] == lower[j]) {
        string[i] = upper[j];
      }
    }
  }
}

//Esta função deve cadastrar um projeto, ela recebe um vetor da estrutura, e sua posição.
//Ela roteia as devidas atividades para suas respectivas funções, fazendo com que, apenas exibições e algumas verificações sejam feitas em seu escopo.
void cadastrarProjetos(equipe_t equipe[], int pos) {
  int codigo = 0;
  selecionarCategoria(equipe, pos);
  setbuf(stdin, NULL);
  printf("\nVocê deve informar um código, com ele poderemos identificar o seu projeto :)");
  printf("\nAh... Lembre-se seu código deve conter no máximo 2 dígitos.");
  printf("\nCódigo: ");
  codigo = retornarEscolha(1, 99);
  setbuf(stdin, NULL);
  while((codigoValido(equipe, codigo)) == false) {
    printf("Este código já foi utilizado, o que o torna inválido.\nVocê precisará informar um outro código.");
    printf("\nCodigo: ");
    codigo = retornarEscolha(1, 99);
    setbuf(stdin, NULL);
  }
  equipe[pos].projeto.codigo_projeto = codigo;
  printf("Você também pode dar um nome bacana pra ele :) :  ");
  while((validarNome(fgets(equipe[pos].projeto.titulo_projeto, MAX, stdin))) == false) {
    setbuf(stdin, NULL);
    printf("O nome não pode conter números e deve ter mais que 3 caracteres.\n");
  }
//Escolhi utilizar fgets() pois o gets(),porque é impossível de dizer quantos caracteres gets() vai ler, fazendo com que,
//gets(), continue a armazenar caracteres, podendo escrever em uma região da memória já utilizada por outro programa.
  tudoMaiusculo(equipe[pos].projeto.titulo_projeto);
  equipe[pos].equipe_id = pos + 1;
} // Fim cadastrarProjetos();

//Esta função realiza a verificação do código digitado pelo usuário, procurando por este valor em um projeto já cadastrado.
//Se o valor digitado corresponder a algum código já utilizado a função retorna false, fazendo com que o usuário precise digitar um outro código para seu projeto.
bool codigoValido(equipe_t equipe[], int codigo) {
  int i = 0;
  while(i < 10 && equipe[i].projeto.codigo_projeto != codigo) {
    i++;
  }
  return (equipe[i].projeto.codigo_projeto == codigo ? false : true);
} //Fim de validarCodigo();

// Esta função realiza a seleção de uma categoria de projeto,
// copiando o nome de uma categoria selecionada para a estrutura.
// Ela exibe a matriz de opções, e deve receber um vetor da estrutura e a posição onde deve os dados serão gravados.
void selecionarCategoria(equipe_t equipe[], int pos) {
  char nome_categoria[][15] = {
    "GESTÃO",
    "EDUCAÇÃO",
    "PROJETO SOCIAL"
  };
  printf("Selecione uma categoria para o seu projeto");
  for(int i = 0; i < 3; i++) {
    printf("\n[%d] - %s",i+1,nome_categoria[i]);
  }
  printf("\nOpção: ");
  int categoria = retornarEscolha(1,3);
  equipe[pos].projeto.tipo_projeto = categoria;
  strcpy(equipe[pos].projeto.pnome_categoria, nome_categoria[categoria - 1]);
} // Fim selecionarCategoria();

//Esta função seleciona um projeto no qual o jurado irá lançar suas notas.
//Ela recebe um vetor de estrutura e a quantidade de projetos cadastrados.
void selecionaProjeto(equipe_t equipe[], int *qtd_cadastrada) {
  int id_selecionado = 0;
  int i = 0;
    for (int pos = 0; pos < *qtd_cadastrada; pos++) {
      if(equipe[pos].controle == 1) {
        i++;
      }
      if (i == *qtd_cadastrada) {
        printf("Cadastros finalizados.");
        return;
    }
  }
  exibirProjetos(equipe, qtd_cadastrada);
  printf("Entre com a sua opção: ");
  id_selecionado = retornarEscolha(1, *qtd_cadastrada);
  for(int pos = 0; pos < *qtd_cadastrada; pos++) {
      if(equipe[pos].equipe_id == id_selecionado) {
        if(equipe[pos].controle == 0) {
          printf("\nEquipe selecionada: %s", equipe[pos].nome_equipe);
          printf("%d", id_selecionado);
          recolherNotas(equipe, pos);
        } else if (equipe[pos].controle == 1) {
          printf("Notas já lançadas para esta equipe, você será levado ao menu.");
          exibirMenu();
          return;
        }
    }
  }
}//Fim selecionaProjeto()

//Função que exibe os projetos cadastrados.
void exibirProjetos(equipe_t equipe[], int *qtd_cadastrada) {
  printf("Acho que temos alguns projetos legais para lhe mostrar!\n");
  for(int pos = 0; pos < *qtd_cadastrada; pos++) {
    printf("\nEQUIPE: %sID: %d\nLÍDER: %s", equipe[pos].nome_equipe, equipe[pos].equipe_id, equipe[pos].nome_participante);
    printf("PROJETO: %sCATEGORIA: %s\nCÓDIGO: %d\n", equipe[pos].projeto.titulo_projeto, equipe[pos].projeto.pnome_categoria, equipe[pos].projeto.codigo_projeto);
  }
} //Fim de exibirProjetos();

//Função que exibe as notas dos projetos de acordo com sua média, ranqueadas e organizadas.
void exibirRanking(equipe_t equipe[], int *qtd_cadastrada) {
  printf("Escrevendo no arquivo...");
  printf("Você deve sair do programa para visualizar o arquivo com as informações.Favor fechá-lo");
  FILE *arquivo  = fopen("arquivo.txt","w"); //rt
  for (int pos; pos < *qtd_cadastrada; pos++) {
    if(equipe[pos].controle == 1) {
      organizarRanking(equipe, qtd_cadastrada);
      fprintf(arquivo,"\nEQUIPE: %sLÍDER: %sCATEGORIA: %s\n", equipe[pos].nome_equipe, equipe[pos].nome_participante, equipe[pos].projeto.pnome_categoria);
      for(int i = 0; i < 5; i++){
        fprintf(arquivo, "\nJ%d ORGANIZAÇÃO: %.2f VENDAS: %.2f USABILIDADE:%.2f MATURIDADE: %.2f INOVAÇÃO: %.2f", i, equipe[pos].projeto.jurados[i].nivel_organizacao, equipe[pos].projeto.jurados[i].estrategia_vendas, equipe[pos].projeto.jurados[i].grau_usabilidade, equipe[pos].projeto.jurados[i].nivel_maturidade, equipe[pos].projeto.jurados[i].grau_inovacao);
      }
      fprintf(arquivo, "\nMÉDIA GERAL: %.2f\n", equipe[pos].projeto.geral);
    } else {
      return;
    }
  }
  fclose(arquivo);
} //Fim exibirRanking();

//Função para recolher as notas para um projeto, ela recebe o projeto selecionado astravés da função selecionaProjeto(); e armazena os valores na estrutura.
void recolherNotas(equipe_t equipe[], int pos) {
  for(int i = 0; i < 5; i++) {
      printf("\nNível de Organização da equipe: ");
      equipe[pos].projeto.jurados[i].nivel_organizacao = retornaNota();
      printf("Estratégia de vendas: ");
      equipe[pos].projeto.jurados[i].estrategia_vendas = retornaNota();
      printf("Grau de usabilidade do produto: ");
      equipe[pos].projeto.jurados[i].grau_usabilidade = retornaNota();
      printf("Nível de maturidade: ");
      equipe[pos].projeto.jurados[i].nivel_maturidade = retornaNota();
      printf("Grau de inovação do produto: ");
      equipe[pos].projeto.jurados[i].grau_inovacao = retornaNota();
    }
    equipe[pos].controle = 1;
    calcularMedia(equipe, pos);
} //Fim recolherNotas();

//Realiza a leitura de uma nota dadd por um jurado, e verifica se ela está de acordo com as "normas", devendo estar entre 0 e 10.
//Ela retorna a nota lida.
float retornaNota() {
  float nota = 0;
  while((scanf("%f", &nota) != 1) || (nota < 0) || (nota > 10)) {
    printf("Hey! Parece que você digitou um valor inválido.");
    printf("\nDigite sua escolha novamente: ");
    setbuf(stdin, NULL);
  }
  return nota;
} //Fim retornaNota();

//Função que recebe o vetor de estrutura e sua posição, e calcula a média das notas informada, somando cada uma das 5 notas, e armazenando numa variável auxiliar.
//E então lançando as médias e a média geral no vetor medias[];
void calcularMedia(equipe_t equipe[], int pos) {
  equipe[pos].projeto.media[5] = 0;
  float soma_organizacao = 0, soma_estrategia = 0, soma_usabilidade = 0, soma_maturidade = 0, soma_inovacao = 0;
  for(int i = 0; i < 5; i++) {
    soma_organizacao += equipe[pos].projeto.jurados[i].nivel_organizacao;
    soma_estrategia  += equipe[pos].projeto.jurados[i].estrategia_vendas;
    soma_usabilidade += equipe[pos].projeto.jurados[i].grau_usabilidade;
    soma_maturidade  += equipe[pos].projeto.jurados[i].nivel_maturidade;
    soma_inovacao    += equipe[pos].projeto.jurados[i].grau_inovacao;
  }
    equipe[pos].projeto.media[0] = (soma_organizacao * 0.1);
    equipe[pos].projeto.media[1] = (soma_estrategia * 0.1);
    equipe[pos].projeto.media[2] = (soma_usabilidade * 0.2);
    equipe[pos].projeto.media[3] = (soma_maturidade * 0.3);
    equipe[pos].projeto.media[4] = (soma_inovacao * 0.3);
    for (int i = 0; i < 5; i++) {
      equipe[pos].projeto.geral += equipe[pos].projeto.media[i];
    }
}

//Função que organizar os projetos cadastrados em ordem decrescente de acordo com suas notas gerais.
//Este é um bubbleSort, modificado apenas para trocar a posição de uma struct.
void organizarRanking(equipe_t equipe[], int *qtd_cadastrada) {
	equipe_t aux;
	int troca = 1; //A variável "troca" será a verificação da troca em cada passada*/
	for(int j =  *qtd_cadastrada - 1; (j >= 1) && (troca == 1); j--) {
		troca = 0; //Se o valor continuar 0 na próxima passada quer dizer que não houve troca e a função é encerrada.*/
		for(int i = 0; i < j; i++) {
			if(equipe[i].projeto.geral < equipe[i + 1].projeto.geral) {
				aux = equipe[i];
				equipe[i] = equipe[i + 1];
				equipe[i + 1] = aux;
				troca = 1; //Se houve troca, "troca" recebe 1 para continuar rodando.*/
			}
		}
	}
}

FILE *abreArquivo(char *nome_arquivo) {
} //Fim de abreArquivo();

void lerArquivo() {
  // for(int i = 0; i < 10; i++){
  //   fscanf(arquivo,"%s", &equipe[i].nome_equipe);
  //   fscanf(arquivo,"%f", &equipe[i].notas.notas[j]);
  // }
}

void saidaArquivo() {
  // if(file == NULL) {
  //   printf("Errro!");
  // }
  // char nome_arquivo[MAX];
  // puts("\nDigite o nome do arquivo de texto: ");
  // fgets(nome_arquivo,BUFSIZ,stdin);
  // setbuf(stdin, NULL);
  // //Concatenando a extensão ao nome do arquivo de texto.
  // strcat(nome_arquivo,".txt");
  // //abreArquivo(nome_arquivo);
} //Fim de lerArquivo();
