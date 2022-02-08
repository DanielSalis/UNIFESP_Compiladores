%{
    #define YYPARSER    
    #include "globals.h"
    #include "util.h"
    #include "scan.h"
    #include "parse.h"

    #define YYSTYPE TreeNode *
    static TreeNode * savedTree;   
    static int yylex(void);
%}

%token IF ELSE WHILE INT VOID RETURN
%token NUM ID
%token ASSIGN EQ NOT_EQUAL LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL SUM SUBTRACT MULTIPLY DIVIDE OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_BRACKET CLOSE_BRACKET OPEN_KEYS CLOSE_KEYS COMMA SEMICOLON
%token ERROR ENDFILE

%% 

program            :   list_declaration
                       {
                          savedTree = $1;
                       }
                    ;
list_declaration    :   list_declaration declaration
                        {
                            YYSTYPE t = $1;
                            if(t != NULL)
		   	  			    {
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = $2;
                                $$ = $1;
                            }
                            else
                                $$ = $2;
                        }
                    |   declaration
                        {
                           $$ = $1;
                        }
                    ;
declaration         :   var_declaration
                        {
                           $$ = $1;
                        }
                    |   fun_declaration
                        {
                           $$ = $1;
                        }
                    ;
var_declaration     :   INT ident SEMICOLON
                        {	
                        	$$ = newExpNode(typeK);
                            $$->type = integerK;
                            $$->attr.name = "integer";
                            $$->child[0] = $2;
                            $2->nodekind = statementK;
                            $2->kind.stmt = variableK;
							$2->type = integerK;
                        }
                    |   INT ident OPEN_BRACKET num CLOSE_BRACKET SEMICOLON
                        {
                        	$$ = newExpNode(typeK);
                            $$->type = integerK;
                            $$->attr.name = "integer";
                            $$->child[0] = $2;
                            $2->nodekind = statementK;
                            $2->kind.stmt = variableK;
							$2->type = integerK; 
                            $2->attr.len = $4->attr.val;
                        }
                    ;
fun_declaration     :   INT ident OPEN_PARENTHESES params CLOSE_PARENTHESES compound_decl
                        {
                        	$$ = newExpNode(typeK);
                            $$->type = integerK;
                            $$->attr.name = "integer";
                            $$->child[0] = $2;
                            $2->child[0] = $4;
                            $2->child[1] = $6;
                            $2->nodekind = statementK;
                            $2->kind.stmt = functionK;
							$2->type = integerK;
							$4->type = integerK;
							aggScope($2->child[0], $2->attr.name);
							aggScope($2->child[1], $2->attr.name);
                        }
                    |   VOID ident OPEN_PARENTHESES params CLOSE_PARENTHESES compound_decl
                        {
                        	$$ = newExpNode(typeK);
                            $$->type = voidK;
                            $$->attr.name = "void";
                            $$->child[0] = $2;
                            $2->child[0] = $4;
                            $2->child[1] = $6;
                            $2->nodekind = statementK;
                            $2->kind.stmt = functionK;
							aggScope($2->child[0], $2->attr.name);
							aggScope($2->child[1], $2->attr.name);
                        }
                    ;
params              :   param_list
                        {
                           $$ = $1;
                        }
                    |   VOID
                        {
						  $$ = newExpNode(typeK);
           				  $$->attr.name = "void";
						}
                    ;
param_list          :   param_list COMMA param
                        {
                           YYSTYPE t = $1;
                           if(t != NULL)
						   {
                              while(t->sibling != NULL)
                                  t = t->sibling;
                              t->sibling = $3;
                              $$ = $1;
                            }
                            else
                              $$ = $3;
                        }
                    |   param
                        {
                            $$ = $1;
                        }
                    ;
param               :   INT ident
                        {
						   	
                           $$ = newExpNode(typeK);
					       $2->nodekind = statementK;
                           $2->kind.stmt = variableK;
                           $$->type = integerK;
						   $2->type = integerK; 	
                           $$->attr.name = "integer";
                           $$->child[0] = $2;
                        }
                    |   INT ident OPEN_BRACKET CLOSE_BRACKET
                        {
							
                            $$ = newExpNode(typeK);
							$2->nodekind = statementK;
                            $2->kind.stmt = variableK;
                            $$->type = integerK;
                            $$->attr.name = "integer";
                            $$->child[0] = $2;
						    $2->type = integerK;
                        }
                    ;
compound_decl       :   OPEN_KEYS local_declarations statement_list CLOSE_KEYS
                        {
                            YYSTYPE t = $2;
                            if(t != NULL)
						    {
                               while(t->sibling != NULL)
                                  t = t->sibling;
                                t->sibling = $3;
                                $$ = $2;
                            }
                            else
                               $$ = $3;
                        }
                    |   OPEN_KEYS local_declarations CLOSE_KEYS
                        {
                            $$ = $2;
                        }
                    |   OPEN_KEYS statement_list CLOSE_KEYS
                        {
                            $$ = $2;
                        }
                    |   OPEN_KEYS CLOSE_KEYS
                        {
			   			}
                    ;
local_declarations  :   local_declarations var_declaration
                        {
                            YYSTYPE t = $1;
                            if(t != NULL)
							{
                            	while(t->sibling != NULL)
                                	 t = t->sibling;
                             	t->sibling = $2;
                             	$$ = $1;
                            }
                            else
                               $$ = $2;
                        }
                   |    var_declaration
                        {
                            $$ = $1;
                        }
                    ;
statement_list      :   statement_list statement
                        {
                           YYSTYPE t = $1;
                           if(t != NULL)
						   {
                              while(t->sibling != NULL)
                                   t = t->sibling;
                              t->sibling = $2;
                              $$ = $1;
                           }
                           else
                             $$ = $2;
                        }
                    |   statement
                        {
                           $$ = $1;
                        }
                    ;
statement           :   expression_decl
                        {
                           $$ = $1;
                        }
                    |   compound_decl
                        {
                           $$ = $1;
                        }
                    |   selection_decl
                        {
                           $$ = $1;
                        }
                    |   iterator_decl
                        {
                           $$ = $1;
                        }
                    |   return_decl
                        {
                           $$ = $1;
                        }
                    ;
expression_decl     :   expression SEMICOLON 
                        {
                           $$ = $1;
                        }
                    |   SEMICOLON
                        {
						}
                    ;
selection_decl      :   IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement 
                        {
                             $$ = newStmtNode(ifK);
                             $$->child[0] = $3;
                             $$->child[1] = $5;
                        }
                    |   IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement ELSE statement
                        {
							 
                             $$ = newStmtNode(ifK);
                             $$->child[0] = $3;
                             $$->child[1] = $5;
                             $$->child[2] = $7;
                        }
                    ;
iterator_decl       :   WHILE OPEN_PARENTHESES expression CLOSE_PARENTHESES statement
                        {
                             $$ = newStmtNode(whileK);
                             $$->child[0] = $3;
                             $$->child[1] = $5;
                        }
                   ;
return_decl        :   RETURN SEMICOLON
                       {
                            $$ = newStmtNode(returnK);
							$$->type = voidK;
                       }
                   |   RETURN expression SEMICOLON
                       {
                            $$ = newStmtNode(returnK);
                            $$->child[0] = $2;
                       }
                   ;
expression         :   var ASSIGN expression
                       {
                            $$ = newStmtNode(assignK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                       }
                   |   simple_expression
                       {
                            $$ = $1;
                       }
                   ;
var                :   ident
                       {
                            $$ = $1;
                       }
                   |   ident OPEN_BRACKET expression CLOSE_BRACKET
                       {
                            $$ = $1;
                            $$->child[0] = $3;
                            $$->kind.exp = vectorK;
							$$->type = integerK;
                       }
                    ;
simple_expression   : sum_expression relational sum_expression
                       {
                            $$ = $2;
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                       }
                    |  sum_expression
                       {
                            $$ = $1;
                       }
                    ;
relational          :  EQ
                       {
                            $$ = newExpNode(operationK);
                            $$->attr.op = EQ;  
							$$->type = booleanK;                          
                       }
                    |  NOT_EQUAL
                       {
                            $$ = newExpNode(operationK);
                            $$->attr.op = NOT_EQUAL;
							$$->type = booleanK;                            
                       }
                    |  LESS_THAN
                       {
                            $$ = newExpNode(operationK);
                            $$->attr.op = LESS_THAN;                            
							$$->type = booleanK;
                       }
                    |  LESS_THAN_EQUAL
                       {
                            $$ = newExpNode(operationK);
                            $$->attr.op = LESS_THAN_EQUAL;                            
							$$->type = booleanK;
                       }
                    |  GREATER_THAN
                       {
                            $$ = newExpNode(operationK);
                            $$->attr.op = GREATER_THAN;                            
							$$->type = booleanK;
                       }
                    |  GREATER_THAN_EQUAL
                       {
                            $$ = newExpNode(operationK);
                            $$->attr.op = GREATER_THAN_EQUAL;                            
							$$->type = booleanK;
                       }
                    ;
sum_expression      :  sum_expression sum term
                       {
                            $$ = $2;
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                       }
                    |  term
                       {
                            $$ = $1;
                       }
                    ;
sum                 :  SUM
                       {
                            $$ = newExpNode(operationK);
                            $$->attr.op = SUM;                            
                       }
                    |  SUBTRACT
                       {
                            $$ = newExpNode(operationK);
                            $$->attr.op = SUBTRACT;                            
                       }
                    ;
term                :  term mult factor
                       {
                            $$ = $2;
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                       }
                   |   factor
                       {
                            $$ = $1;
                       }
                    ;
mult                :  MULTIPLY
                       {
                            $$ = newExpNode(operationK);
                            $$->attr.op = MULTIPLY;                            
                       }
                   |   DIVIDE
                       {
                            $$ = newExpNode(operationK);
                            $$->attr.op = DIVIDE;                            
                       }
                    ;
factor              :  OPEN_PARENTHESES expression CLOSE_PARENTHESES
                       {
                            $$ = $2;
                       }
                   |   var
                       {
                            $$ = $1;
                       }
                   |   activation
                       {
                            $$ = $1;
                       }
                   |   num
                       {
                            $$ = $1;
                       }
                    ;
activation          :  ident OPEN_PARENTHESES arg_list CLOSE_PARENTHESES
                       {
                            $$ = $1;
                            $$->child[0] = $3;
                            $$->nodekind = statementK;
                            $$->kind.stmt = callK;
                       }
                    |  ident OPEN_PARENTHESES CLOSE_PARENTHESES 
					   {
                            $$ = $1;
                            $$->nodekind = statementK;
                            $$->kind.stmt = callK;
                       }
                       
                    ;
arg_list            :  arg_list COMMA expression
                       {
                            YYSTYPE t = $1;
                             if(t != NULL)
							 {
                                while(t->sibling != NULL)
                                   t = t->sibling;
                                 t->sibling = $3;
                                 $$ = $1;
                             }
                             else
                                 $$ = $3;
                        }
                    |   expression
                        {
                             $$ = $1;
                        }
                    ;
ident               :   ID
                        {
                             $$ = newExpNode(idK);
                             $$->attr.name = copyString(tokenString);
                        }
                    ;
num                 :   NUM
                        {
                             $$ = newExpNode(constantK);
                             $$->attr.val = atoi(tokenString);
							 $$->type = integerK;
						}
                    ;

%%

int yyerror(char* message){
    fprintf(listing,"ERRO SINTÁTICO: ");
    printTokenForError(yychar,tokenString);
    fprintf(listing," LINHA: %d\n",lineno);
    Error = TRUE;
    return 0;
}


static int yylex(void){
    return getToken();
}

TreeNode * parse(void){
    yyparse();
    return savedTree;
}
