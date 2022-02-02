%{
#include <stdlib.h>
#include <stdio.h>
#include "globals.h"
#include "util.h"
#include "scan.h"

char tokenString[MAXTOKENLEN+1];
static int yylex(void);

int yywrap ();

%}

NUMBER 		[0-9]
WHITESPACE  [ \t]+
LETTER 		[a-zA-Z]
ELSE 		else
IF 			if
INT 		int
RETURN 		return
VOID 		void 
WHILE 		while

%%

"/*" { 
	char c;
	do{ 
		c = input();
		if (c == EOF) 
			break;
		if (c == '\n') 
		lineno++;
		if (c == '*') {
			if(input() == '/')
				break;
		}		
	} 
	while (1);
	}

{ELSE}										return ELSE;
{IF}										return IF;
{INT}										return INT;
{RETURN}									return RETURN;
{VOID}										return VOID;
{WHILE}										return WHILE;
{NUMBER}+									return NUM;
{LETTER}({LETTER}|{NUMBER})*				return ID;
"+"											return PLUS;
"-"											return MINUS;
"*"											return TIMES;
"/"											return OVER;	
"<"											return LESS_THAN;
"<="										return LESS_THAN_EQUAL;
">"											return GREATER_THAN;
">="										return GREATER_THAN_EQUAL;
"=="										return EQUAL;
"!="										return NOT_EQUAL;
,											return COMMA;
"{"											return OPEN_KEYS;
"}"											return CLOSE_KEYS;	
"["											return OPEN_BRACKET;				
"]"											return CLOSE_BRACKET;
=											return ASSIGN;
;											return SEMICOLON;
"("											return OPEN_PARENTHESES;
")"											return CLOSE_PARENTHESES;
<<EOF>> 									return END_OF_FILE;
\n              							lineno++;
{WHITESPACE}   								{         }
.|({NUMBER}+{LETTER}+)						return ERR;

%%

void abrirArq(){
	yyin = fopen("entrada.txt", "r");
}

int yywrap () {  };

TokenType getToken(void){ 
	static int firstTime = TRUE;
 	TokenType currentToken;
 	if (firstTime){ 
		firstTime = FALSE;
   	lineno = lineno + 1;
  	yyin = source;
 	yyout = listing;
 	}
 	currentToken = yylex();
 	strncpy(tokenString,yytext,MAXTOKENLEN);
  	if (TraceScan) {
		  if(currentToken != FIM){ 
    		fprintf(tokenList,"\t%d: ",lineno);
    		printToken(tokenList, currentToken,tokenString);
		  }
	 }
	 
	if(currentToken == ERR){
		printf("\nERRO LÉXICO. Linha: %d, ", lineno);
		printToken(listing, currentToken,tokenString);
		Error = TRUE;
	}
	return currentToken;
}
