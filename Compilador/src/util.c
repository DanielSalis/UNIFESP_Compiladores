#include "globals.h"
#include "util.h"


void printToken(FILE* file, TokenType token, const char* tokenString )
{ switch (token){ 
    case IF:            fprintf(file, "Palavra reservada: IF, Lexema: %s\n",tokenString); break;
    case ELSE:          fprintf(file, "Palavra reservada: ELSE, Lexema: %s\n",tokenString); break;
    case RETURN:        fprintf(file, "Palavra reservada: RETURN, Lexema: %s\n",tokenString); break;
    case INT:		        fprintf(file, "Palavra reservada: INT, Lexema: %s\n",tokenString); break;
    case VOID:	        fprintf(file, "Palavra reservada: VOID, Lexema: %s\n",tokenString); break;
    case WHILE:         fprintf(file, "Palavra reservada: WHILE, Lexema: %s\n",tokenString); break;
    case IGL:           fprintf(file, "=\n"); break;
	  case PEV:           fprintf(file, ";\n"); break;
	  case APR:           fprintf(file, "(\n"); break;
	  case FPR:           fprintf(file, ")\n"); break;
	  case MENOR:         fprintf(file, "<\n"); break;
    case MENORIGUAL:    fprintf(file, "<=\n"); break;
    case MAIOR:         fprintf(file, ">\n"); break;
    case MAIORIGUAL:    fprintf(file, ">=\n"); break;
    case IGUALIGUAL:    fprintf(file, "==\n"); break;
	  case DIFERENTE:     fprintf(file, "!=\n"); break;
	  case VIRGULA:       fprintf(file, ",\n"); break;
	  case COLCHETEABRE:  fprintf(file, "[\n"); break;
	  case COLCHETEFECHA: fprintf(file, "]\n"); break;
	  case CHAVESABRE:    fprintf(file, "{\n"); break;
	  case CHAVESFECHA:   fprintf(file, "}\n"); break;
	  case SOM:           fprintf(file, "+\n"); break;
	  case SUB:           fprintf(file, "-\n"); break;
	  case MUL:           fprintf(file, "*\n"); break;
	  case DIV:           fprintf(file, "/\n"); break;
    case FIM:           fprintf(file, "EOF\n"); break;
    case NUM:           fprintf(file, "NUM, val= %s\n",tokenString); break;
    case ID:            fprintf(file, "ID, name= %s\n",tokenString); break;
    case ERR:           fprintf(file, "Lexema: %s\n",tokenString); break;
    default: 
      fprintf(file,"Unknown token: %d\n",token);
  }
}

void aggScope(TreeNode* t, char* scope)
{
	int i;
	while(t != NULL)
	{
		for(i = 0; i < MAXCHILDREN; ++i)
		{
			t->attr.scope = scope;
			aggScope(t->child[i], scope);
		}
		t = t->sibling; 
	}
}

/* A função newStmtNode cria uma nova instrução
 * nó para construção de árvore de sintaxe
 */
TreeNode * newStmtNode(StmtKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i=0;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) 
        t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = statementK;
        t->kind.stmt = kind;
        t->lineno = lineno;
        t->attr.scope = "global";
        t->icTemp = -1;
        t->paramQt = 0;


  }
  return t;
}

/* A função newExpNode cria uma nova expressão
 * nó para construção de árvore de sintaxe
 */
TreeNode * newExpNode(ExpKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  
  int i=0;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++){ 
      t->child[i] = NULL;
    }
    t->sibling = NULL;
    t->nodekind = expressionK;
    t->kind.exp = kind;
    t->lineno = lineno;
    t->type = VOID;
    t->attr.scope = "global";
    t->icTemp = -1;
    t->paramQt = 0;
  }

  return t;
}

/* A função copyString aloca e cria um novo
 * cópia de uma string existente
 */
char * copyString(char * s)
{ int n;
  char * t;
  if (s==NULL) 
    return NULL;
  
  n = strlen(s)+1;
  t = malloc(n);
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else 
    strcpy(t,s);
  return t;
}

/*Uma função copyString aloca e cria um novo
 * cópia de uma string existente
 */
static int indentno = 0;


#define INDENT indentno+=2
#define UNINDENT indentno-=2


static void printSpaces(void)
{ int i;
  for (i=0;i<indentno;i++)
    fprintf(synTree," ");
}

/* procedimento printTree imprime uma árvore de sintaxe para o
 * arquivo de listagem usando indentação para indicar subárvores
 */
void printTree( TreeNode * tree )
{ 
  int i;
  INDENT;
  while (tree != NULL) {
    printSpaces();
    if (tree->nodekind==statementK)
    { switch (tree->kind.stmt) {
        case ifK:     fprintf(synTree,"If\n"); break;
        case whileK:  fprintf(synTree,"While\n"); break;
	    	case paramK:  fprintf(synTree,"Parametro: %s\n", tree->attr.name); break;
        case assignK: fprintf(synTree,"Atribuição\n"); break;
        case varK:    fprintf(synTree,"Variável: %s\n",tree->attr.name); break;
        case funcK:   fprintf(synTree,"Função %s\n", tree->attr.name); break;
	    	case callK:   fprintf(synTree,"Chamada de Função: %s \n", tree->attr.name); break;
	    	case returnK: fprintf(synTree,"Retorno"); break;
        case argK:    fprintf(synTree,"Argumento: %s\n", tree->attr.name); break;
        default:      fprintf(synTree,"Unknown ExpNode kind 1\n"); break;

      }
    }
    else if (tree->nodekind==expressionK){

      switch (tree->kind.exp) {
        case opK:         fprintf(synTree,"Op: ");
                          printToken(synTree, tree->attr.op,"\0");
                          break;
        case constK:      fprintf(synTree,"Const: %d\n",tree->attr.val);
                          break;
        case idK:         fprintf(synTree,"Id: %s\n",tree->attr.name);
                          break;
		    case vectK:       fprintf(synTree,"Vetor: %s\n",tree->attr.name);
                          break;
		    case vectIndexK:  fprintf(synTree,"Indíce: [%d]\n",tree->attr.val);
                          break;
        case typeK:       fprintf(synTree,"Type %s\n",tree->attr.name);
                          break;
        default:          fprintf(synTree,"Unknown ExpNode kind 2\n");
                          break;
      }
    }
    else 
      fprintf(synTree,"Unknown node kind 3\n");

    for (i = 0; i < MAXCHILDREN; i++){
      if(tree->child[i] != NULL)
        printTree(tree->child[i]);
    }
    
    tree = tree->sibling;
  }
  UNINDENT;
}