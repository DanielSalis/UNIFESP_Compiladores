%{

#define YYPARSER
#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode*
TreeNode* savedTree;
int yylex(void);

void yyerror(char *);

%}

%start program
%token IF ELSE RETURN INT VOID WHILE
%token ID NUM
%token ASSIGN LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL EQUAL NOT_EQUAL
%token SEMICOLON COMMA
%token OPEN_PAREN CLOSE_PAREN
%token OPEN_BRACKET CLOSE_BRACKET
%token OPEN_KEYS CLOSE_KEYS
%token PLUS MINUS MULTIPLYER DIVIDER
%token ERROR END
%expect 1

%%

program : declaracao_lista { savedTree = $1; };

declaracao_lista : declaracao_lista declaracao
                    {
                        YYSTYPE t = $1;
                        if(t != NULL){
                            while(t -> sibling != NULL){
                                t = t->sibling;
                            }
                            t->sibling = $2;
                            $$ = $1;
                        } else {
                            $$ = $2;
                        }
                    }

				 | 	declaracao { $$ = $1; }
                 ;

declaracao : var_declaracao { $$ = $1; }
		   | fun_declaracao { $$ = $1; }
           ;

id : ID {
            $$ = newExpNode(IdK);
            $$->attr.name = copyString(tokenString);
		};

var_declaracao : INT id SEMICOLON
                    {
						$$ = newExpNode(TypeK);
						$$->type = Integer;
						$$->attr.name = "integer";
						$$->child[0] = $2;
						$2->nodekind = StmtK;
						$2->kind.stmt = VarK;
						$2->type = Integer;
						$2->attr.len = 1;
					} 

				| 	INT id OPEN_BRACKET num CLOSE_BRACKET SEMICOLON
                    {
						$$ = newExpNode(TypeK);
						$$->type = Integer;
						$$->attr.name = "integer";
						$$->child[0] = $2;
						$2->nodekind = StmtK;
						$2->kind.stmt = VarK;
						$2->type = Integer;
						$2->attr.len = $4->attr.val; 	
					} 

				|	VOID id SEMICOLON
                    {
						$$ = newExpNode(TypeK);
						$$->type = Void;
						$$->attr.name = "void";
						$$->child[0] = $2;
						$2->nodekind = StmtK;
						$2->kind.stmt = VarK;
						$2->type = Void;
						$2->attr.len = 1;
					} 

				| VOID id OPEN_BRACKET num CLOSE_BRACKET SEMICOLON
                    {
						$$ = newExpNode(TypeK);
						$$->type = Void;
						$$->attr.name = "void";
						$$->child[0] = $2;
						$2->nodekind = StmtK;
						$2->kind.stmt = VarK;
						$2->type = Void;
						$2->attr.len = $4->attr.val;
					}
                ;

num : NUM {
			$$ = newExpNode(ConstK);
            $$->attr.val = atoi(tokenString);
			$$->type = Integer;
		  };

fun_declaracao : INT id OPEN_PAREN params CLOSE_PAREN composto_decl
                    {
						$$ = newExpNode(TypeK);
                    	$$->type = Integer;
                    	$$->attr.name = "integer";
                    	$$->child[0] = $2;
                    	$2->child[0] = $4;
                    	$2->child[1] = $6;
                    	$2->nodekind = StmtK;
                    	$2->kind.stmt = FuncK;
						$2->type = Integer;
						$4->type = Integer;
						aggScope($2->child[0], $2->attr.name);
						aggScope($2->child[1], $2->attr.name);
					}

				| VOID id OPEN_PAREN params CLOSE_PAREN composto_decl
                    {
						$$ = newExpNode(TypeK);
                    	$$->type = Void;
                    	$$->attr.name = "void";
                    	$$->child[0] = $2;
                    	$2->child[0] = $4;
                   	 	$2->child[1] = $6;
                    	$2->nodekind = StmtK;
                    	$2->kind.stmt = FuncK;
						aggScope($2->child[0], $2->attr.name);
						aggScope($2->child[1], $2->attr.name);
					}
                ;

params : param_lista { $$ = $1; }
	   | VOID
            {
			    $$ = newExpNode(TypeK);
           	    $$->attr.name = "void";
			}
       ;

param_lista : param_lista COMMA param
                {
					YYSTYPE t = $1;
                    	if(t != NULL){
                        	while(t->sibling != NULL)
                            	t = t->sibling;
                        	t->sibling = $3;
                        	$$ = $1;
                        }
                        else
                          $$ = $3;
				}

			| param { $$ = $1; }
            ;

param : INT id
        {
			$$ = newExpNode(TypeK);
			$2->nodekind = StmtK;
            $2->kind.stmt = ParamK;
            $$->type = Integer;
			$2->type = Integer;
            $$->attr.name = "integer";
            $$->child[0] = $2;
		}

	  | INT id OPEN_BRACKET CLOSE_BRACKET
        {
			$$ = newExpNode(TypeK);
			$2->nodekind = StmtK;
            $2->kind.stmt = ParamK;
            $$->type = Integer;
            $$->attr.name = "integer";
            $$->child[0] = $2;
			$2->type = Integer;
		}

	  |	VOID id
        {
			$$ = newExpNode(TypeK);
			$2->nodekind = StmtK;
            $2->kind.stmt = ParamK;
            $$->type = Void;
			$2->type = Void;
            $$->attr.name = "integer";
            $$->child[0] = $2;
		}

      | VOID id OPEN_BRACKET CLOSE_BRACKET
        {
			$$ = newExpNode(TypeK);
			$2->nodekind = StmtK;
            $2->kind.stmt = ParamK;
            $$->type = Void;
            $$->attr.name = "void";
            $$->child[0] = $2;
			$2->type = Void;
		}
      ;

composto_decl : OPEN_KEYS local_declaracoes statement_lista CLOSE_KEYS
                {
					YYSTYPE t = $2;
                    if(t != NULL){
						while(t->sibling != NULL)
                        t = t->sibling;
                        t->sibling = $3;
                        $$ = $2;
                    }
					else
                    	$$ = $3;
				}

			  | OPEN_KEYS local_declaracoes CLOSE_KEYS { $$ = $2; }
              | OPEN_KEYS statement_lista CLOSE_KEYS { $$ = $2;	}
              | OPEN_KEYS CLOSE_KEYS { }
              ;

local_declaracoes : local_declaracoes var_declaracao
                    {
						YYSTYPE t = $1;
                        if(t != NULL){
                        	while(t->sibling != NULL)
                            	t = t->sibling;
                            t->sibling = $2;
                            $$ = $1;
                        }
                        else
                        	$$ = $2;
					} 

				  | var_declaracao { $$ = $1; }
                  ;

statement_lista : statement_lista statement
                    {
                    	YYSTYPE t = $1;
                        if(t != NULL){
                        	while(t->sibling != NULL)
                            	t = t->sibling;
                            t->sibling = $2;
                            $$ = $1;
                        }
                    	else
                        	$$ = $2;
					} 

				| statement { $$ = $1; }
                ;

statement : expressao_decl  { $$ = $1; }
		  | composto_decl   { $$ = $1; }
		  | selecao_decl    { $$ = $1; }
		  | iteracao_decl   { $$ = $1; }
		  | retorno_decl    { $$ = $1; }
          ;

expressao_decl : expressao SEMICOLON { $$ = $1; }
			   | SEMICOLON { }
               ;

selecao_decl : 	IF OPEN_PAREN expressao CLOSE_PAREN statement
                {
					$$ = newStmtNode(IfK);
                	$$->child[0] = $3;
                	$$->child[1] = $5;
				}
			  | IF OPEN_PAREN expressao CLOSE_PAREN statement ELSE statement
                {
					$$ = newStmtNode(IfK);
                    $$->child[0] = $3;
                    $$->child[1] = $5;
                    $$->child[2] = $7;
				}
              ;

iteracao_decl : WHILE OPEN_PAREN expressao CLOSE_PAREN statement
                {
					$$ = newStmtNode(RepeatK);
                    $$->child[0] = $3;
                    $$->child[1] = $5;
				};

retorno_decl : RETURN SEMICOLON
                {
					$$ = newStmtNode(ReturnK);
					$$->type = Void;
				}
			 | RETURN expressao SEMICOLON
                {
					$$ = newStmtNode(ReturnK);
                    $$->child[0] = $2;
				};

expressao : var ASSIGN expressao
            {
				$$ = newStmtNode(AssignK);
                $$->child[0] = $1;
                $$->child[1] = $3;
			}

		  | simples_expressao { $$ = $1; }
          ;

var : id { $$ = $1; }
	| id OPEN_BRACKET expressao CLOSE_BRACKET
        {
			$$ = $1;
            $$->child[0] = $3;
            $$->kind.exp = VectK;
		}
    ;

simples_expressao :	soma_expressao relacional soma_expressao
                    {
						$$ = $2;
                        $$->child[0] = $1;
                        $$->child[1] = $3;
					} 

				  | soma_expressao { $$ = $1; };

relacional : LESS_THAN_EQUAL
                {
					$$ = newExpNode(OpK);
                    $$->attr.op = LESS_THAN_EQUAL;
					$$->type = Boolean;
				}

            | LESS_THAN
                {
					$$ = newExpNode(OpK);
                    $$->attr.op = LESS_THAN;
					$$->type = Boolean;
				}

            | GREATER_THAN
                {
					$$ = newExpNode(OpK);
                    $$->attr.op = GREATER_THAN;
					$$->type = Boolean;
				}

            | GREATER_THAN_EQUAL
                {
					$$ = newExpNode(OpK);
                    $$->attr.op = GREATER_THAN_EQUAL;
					$$->type = Boolean;
				}

			| EQUAL
                {
					$$ = newExpNode(OpK);
                    $$->attr.op = EQUAL;
					$$->type = Boolean;
				}

			| NOT_EQUAL
                {
					$$ = newExpNode(OpK);
                    $$->attr.op = NOT_EQUAL;
					$$->type = Boolean;
				}
            ;

soma_expressao : soma_expressao soma termo
                    {
						$$ = $2;
                    	$$->child[0] = $1;
                    	$$->child[1] = $3;
					} 
			   | termo { $$ = $1; };

soma : PLUS
        {
		    $$ = newExpNode(OpK);
            $$->attr.op = PLUS;
		}

	 | MINUS
        {
			$$ = newExpNode(OpK);
            $$->attr.op = MINUS;
		}
     ;

termo : termo mult fator
        {
			$$ = $2;
            $$->child[0] = $1;
            $$->child[1] = $3;
        }

	  |	fator {	$$ = $1; }
      ;

mult : MULTIPLYER
        {
			$$ = newExpNode(OpK);
            $$->attr.op = MULTIPLYER;
		}
	 | DIVIDER
        {
			$$ = newExpNode(OpK);
        	$$->attr.op = DIVIDER;
		}
     ;

fator : OPEN_PAREN expressao CLOSE_PAREN { $$ = $2; }
	  | var                              { $$ = $1; }
	  | ativacao                         { $$ = $1; }
	  | num                              { $$ = $1; }
      ;

ativacao : id OPEN_PAREN arg_lista CLOSE_PAREN
            {
				$$ = $1;
                $$->child[0] = $3;
                $$->nodekind = StmtK;
                $$->kind.stmt = CallK;
			}
		  |	id OPEN_PAREN CLOSE_PAREN
            {
				$$ = $1;
                $$->nodekind = StmtK;
                $$->kind.stmt = CallK;
			}
          ;

arg_lista : arg_lista COMMA expressao
            {
				YYSTYPE t = $1;
                if(t != NULL){
                   while(t->sibling != NULL)
                    	t = t->sibling;
                    t->sibling = $3;
                    $$ = $1;
                }
                else
                    $$ = $3;
			}
		  | expressao { $$ = $1; }
          ;

%%

void yyerror(char* message){
	
	if(yychar != ERROR){
		if(yychar != END){	
    		fprintf(listing,"Erro sintático na linha %d: %s\n",lineno,message);
    		fprintf(listing,"Token atual: ");

            //TokenType currentToken = yylex();
    		printToken(yychar, tokenString);
    		Error = TRUE;
		}
	}
	else
		Error = TRUE;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */

int yylex(void){
    return getToken();
}

TreeNode * parse(void){
    yyparse();
    return savedTree;
}