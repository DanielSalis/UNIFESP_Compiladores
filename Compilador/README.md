# Guia de orientação sobre o compilador

## 1 - Conceitos

### 1.1 - Fases de um compilador

### 1.2 - Analisador Léxico
* Também é chamado de scanner. Ele recebe a saída do pré-processador (que realiza a inclusão de arquivos e a expansão de macros) como entrada que está em uma linguagem de alto nível pura. Ele lê os caracteres do programa fonte e os agrupa em lexemas (sequência de caracteres que “andam juntos”). Cada lexema corresponde a um token. Os tokens são definidos por expressões regulares que são compreendidas pelo analisador léxico. Ele também remove erros lexicais (por exemplo, caracteres errados), comentários e espaços em branco.
* FLEX (gerador analisador léxico rápido) é uma ferramenta/programa de computador para gerar analisadores léxicos (scanners ou lexers) escrito por Vern Paxson em C por volta de 1987.
* Nota: A função yylex() é a principal função flex que executa a Seção de Regras e a extensão (.l) é a extensão usada para salvar os programas.


### 1.3 - Análisador sintático
* A análise sintática(parsing) utiliza os tokens produzifos pelo analisador léxico
* Produz uma árvore de análise sintática (onde representa a estrutura gramatical do fluxo de tokens)
* Existem duas formas de se reconhecer uma linguagem através de uma gramática
    * Inferência recursiva
        * Dada uma cadeia (conjunto de símbolos terminais)
        * Tem o fluxo do corpo para cabeça
    * Derivação
        * Dada uma cadeia (conjunto de símbolos terminais)
        * Tem o fluxo da cabeça para o corpo

* De acordo com a teoria um analisador sintático é igual a um autômato de pilha
    * Análise sintática descendente
        * método que produz uma derivação mais à esquerda para uma cadeia de entrada
        * o problema principal em cada passo é determinar qual produção aplicar
        * tokens são lidos da direita para a esquerda
    * Análise sintática ascendente
        * yacc
        * analisador LR(K)
        * Lê a sentencça da esquerda para a direita 
        * produz uma derivação mais à direita
        * K são simbolos na cadeia de entrada


### 1.4 - Análisador Semantico

### 1.5 - Análisador Semantico
* Tabela de símbolos
    * Nada mais é do que uma tabela hash, foi preciso de uma função hash responsavel por calcular e consultar os endereços e posicições de inserção de novos elementos.
    * Em serguida foi necessário as struct LineListRec. É uma lista encadeada para armazenar as linhas das ocorrencias dos símbolos da linguagem
    * temos também a lista de blocos representada pela struct BucketListRec com informações de nome escopo tipo e ponteiro pro proximo elemento
    temos também a função stInsert para inserir novos elementos na tabela caso não tenham sido propriamente inseridos (é feita uma verificação (while), caso o elemento é adicionado com todas as informações necessárias, caso tenha sido salvo na tabela, somente o número da linha é salvo
    * statementFinder, consulta a tabela de símbolos e retorna o número de localização da memória ou -1 caso elemento não encontrado
    * statementFinderType, consulta a tabela para encontrar o typeData
    * printSymTab imprimir a tabela na tela de acordo com as especificações (nome... escopo... id... linhas)

## 2 - Instruções de instalação
```bash
> sudo apt update
> sudo apt install build-essential
> sudo apt-get install flex-old
> sudo apt-get install bison
```

## 3 - Executando
```bash
flex scanner.l
bison -d parser.y
gcc -c *.c
gcc -o cminus *.o -lfl
./cminus <arquivo.cminus> > result.txt
```