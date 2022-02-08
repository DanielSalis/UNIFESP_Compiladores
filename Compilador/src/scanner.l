%{
#include "globals.h"
#include "util.h"
#include "scan.h"

char tokenString[MAXTOKENLEN+1];
static int yylex(void);
%}

digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}+
newline     \n
whitespace  [ \t]+

%%
"/*"            { char c;
                  do
                  { c = input();
                    if (c == EOF) break;
                    if (c == '\n') lineno++;
  		            if (c == '*') 
                    { 
		                if(input() == '/')
		                break;
		            }		
                  } while (1);
                }
"int"		        {return INT;}
"if"            {return IF;}
"else"          {return ELSE;}
"return"	      {return RETURN;}
"void"		      {return VOID;}
"while"		      {return WHILE;}
"="             {return ASSIGN;}
"=="            {return EQ;}
"<"             {return LESS_THAN;}
">"		          {return GREATER_THAN;}
"<="		        {return LESS_THAN_EQUAL;}
">="		        {return GREATER_THAN_EQUAL;}
"!="	       	  {return NOT_EQUAL;}
"["		          {return OPEN_BRACKET;}
"]"		          {return CLOSE_BRACKET;}
"{"		          {return OPEN_KEYS;}
"}"		          {return CLOSE_KEYS;}
"+"             {return SUM;}
"-"             {return SUBTRACT;}
"*"             {return MULTIPLY;}
"/"             {return DIVIDE;}
"("             {return OPEN_PARENTHESES;}
")"             {return CLOSE_PARENTHESES;}
","		          {return COMMA;}
";"             {return SEMICOLON;}
{number}        {return NUM;}
{identifier}    {return ID;}
{newline}       {lineno++;}
{whitespace}    {         }
.               {return ERROR;}

%%

TokenType getToken(void)
{ 
      static int firstTime = TRUE;
      TokenType currentToken;
      if (firstTime)
      { 
        firstTime = FALSE;
        lineno++;
        yyin = source;
        yyout = listing;
      }
      currentToken = yylex();
      strncpy(tokenString,yytext,MAXTOKENLEN);
      if (TraceScan) 
      {
        fprintf(listing,"\t%d: ",lineno);
        printToken(currentToken,tokenString);
      }
      if(currentToken == ERROR){
        printf("\nERRO LÉXICO: ");
        printTokenForError(currentToken,tokenString);
        printf(" LINHA: %d\n", lineno);
        Error = TRUE;
	    }
      return currentToken;
}

