# MIAlgoritmos # ![Status](https://img.shields.io/badge/status-em%20constru%C3%A7%C3%A3o-orange.svg)

Desenvolvimento do **Problema 2 - 2018.1 (Concurso sobre Inovação Tecnologia)** no branch **in_development**

Um grupo de professores e empresas
resolveram organizar um concurso onde equipes
constituídas por estudantes universitários devem
apresentar projetos. Estes projetos devem ser
relacionados à criação de produtos inovadores na área
de gestão, educação ou projeto social. Os vencedores
receberão consultoria de professores e empresas da
área, interessadas em aportar recursos financeiros para
a concretização e a comercialização do produto. Para que este evento aconteça é necessário um software capaz de gerenciar a competição.

O sistema deve cadastrar um número `máximo de dez equipes` assim como os projetos que serão apresentados, permitindo a leitura e/ou a escrita de um arquivo de texto.

## Requisitos do sistema

1. Cadastramento de Projetos.
2. Recolhimento de notas.
3. Cálculo de média.
4. Impressão em arquivo de texto.
5. Leitura de arquivo de texto.

## Cadastramento de Projetos
1. Código  `(o qual não deve se repetir).`
3. Categorias `os projetos devem ser ordenadas respeitando a sequência de cadastro, e na seguinte ordem de categorias:`
  * Gestão
  * Educação
  * Projeto social
3. Nome da Equipe.

O algoritmos contará ainda com um júri:

Que será composto por 5 especialistas, que, ao final de cada apresentação, emitirá 5 notas individuais, de 0 a 10 com pesos variados para cada critério, conforme indicado a seguir:

1. Nível de Organização da Equipe [PESO 1];
2. Estratégia de Venda [PESO 1];
3. Grau de usabilidade do produto [PESO 2];
4. Nível de maturidade da área que pretendem atuar [PESO 3];
5. Grau de inovação do produto [PESO 3].

`O sistema deverá realizar o cálculo da média.`

Ao finalizar o cadastramento de todos os projetos o programa deverá apresentar num arquivo de saída algumas das informações cadastradas:

* Ranking:
  1. Nomes das equipes.
  2. Médias das notas conquistadas em cada critério.
  3. Média geral ponderada `(em ordem decrescente).`
  4. Equipe vencedora por categoria.¹
  5. Projetos desclassificados.²

Info¹: o critério de desempate é a nota relacionada ao nível de maturidade
Info²: O projeto que obtiver média geral menor que 7 deve ser listado entre os projetos
desclassificados.