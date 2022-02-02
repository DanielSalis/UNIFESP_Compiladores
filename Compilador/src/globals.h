#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#ifndef YYPARSER

#include "scanner_table.h"

#define ENDFILE 0

#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define MAXRESERVED 8

typedef int TokenType;

extern FILE *source; 
extern FILE *listing; 
extern FILE *tokenList; 
extern FILE *symTab;
extern FILE *synTree;
extern FILE *intermediateCode;

extern int  lineno; 

typedef enum {statementK,expressionK
} NodeKind;
	
typedef enum {ifK, whileK, assignK, varK, funcK, callK, returnK, argK, paramK
} StmtKind;
	
typedef enum {opK, constK, idK, vectK, vectIndexK, typeK,
} ExpKind;

typedef enum { voidt, integert,booleant
} ExpType;

#define MAXCHILDREN 3

typedef struct treeNode{
	struct treeNode * child[MAXCHILDREN];
    struct treeNode * sibling;
    int lineno;
    NodeKind nodekind;
    union 	{ 
		 		StmtKind stmt; 
				ExpKind exp;
			} kind;

    struct	{	
		 		TokenType op;
				int  val;
        		int  len;
        		char* name; 
        		char* scope;	
			} attr;
    ExpType type; /* para verificar os tipos*/
	int icTemp; /* Armazena o registro temporário do código intermediário */
	int idxReg; /* Armazena o registro de índice para uma instrução de armazenamento de uma matriz */
	int paramQt; /* Armazene o número de parâmetros de uma função apenas para funcK. Se não for necessário, remova e remova de utils.c*/
   }TreeNode;



/* EchoSource = TRUE, faz com que o programa fonte seja 'ecoado' no arquivo de listagem
                com números de linha durante a análise*/
extern int EchoSource;

/* 
TraceScan = TRUE, faz com que as informações do token sejam impressas no arquivo de listagem à medida 
     que cada token é reconhecido pelo scanner
 */
extern int TraceScan;

/* TraceParse = TRUE ,faz com que a árvore de sintaxe seja impressa 
                no arquivo de listagem de forma linearizada
 */
extern int TraceParse;

/* TraceAnalyze = TRUE faz com que as inserções e pesquisas na tabela de símbolos
                    sejam relatadas ao arquivo de listagem
 */
extern int TraceAnalyze;

/* TraceCode = TRUE, faz com que comentários sejam gravados no arquivo de código conforme o código é gerado*/
extern int TraceCode;

/* Error = TRUE, impede mais passagens se ocorrer um erro */
int Error; 

/* Função responsável por converter um valor inteiro em uma string */
char *convertIntChar(int x);

/* Função que conta o número de parâmetros de uma função*/
int paramCounter(TreeNode *t);

#endif