# Guia de orientação sobre o compilador

## 1 - Conceitos

### 1.1 - Fases de um compilador

### 1.2 - Analisador Léxico
* Também é chamado de scanner. Ele recebe a saída do pré-processador (que realiza a inclusão de arquivos e a expansão de macros) como entrada que está em uma linguagem de alto nível pura. Ele lê os caracteres do programa fonte e os agrupa em lexemas (sequência de caracteres que “andam juntos”). Cada lexema corresponde a um token. Os tokens são definidos por expressões regulares que são compreendidas pelo analisador léxico. Ele também remove erros lexicais (por exemplo, caracteres errados), comentários e espaços em branco.
* FLEX (gerador analisador léxico rápido) é uma ferramenta/programa de computador para gerar analisadores léxicos (scanners ou lexers) escrito por Vern Paxson em C por volta de 1987.
* Nota: A função yylex() é a principal função flex que executa a Seção de Regras e a extensão (.l) é a extensão usada para salvar os programas.


## 2 - Instruções de instalação
```bash
> sudo apt update
> sudo apt install build-essential
> sudo apt-get install flex
> sudo apt-get install bison
```