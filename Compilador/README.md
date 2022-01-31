# Guia de orientação sobre o compilador

## 1 - Conceitos

### 1.1 - Fases de um compilador

### 1.2 - Analisador Léxico
Também é chamado de scanner. Ele recebe a saída do pré-processador (que realiza a inclusão de arquivos e a expansão de macros) como entrada que está em uma linguagem de alto nível pura. Ele lê os caracteres do programa fonte e os agrupa em lexemas (sequência de caracteres que “andam juntos”). Cada lexema corresponde a um token. Os tokens são definidos por expressões regulares que são compreendidas pelo analisador léxico. Ele também remove erros lexicais (por exemplo, caracteres errados), comentários e espaços em branco.


## 2 - Instruções de instalação
```bash
> sudo apt update
> sudo apt install build-essential
> sudo apt-get install flex
> sudo apt-get install bison
```