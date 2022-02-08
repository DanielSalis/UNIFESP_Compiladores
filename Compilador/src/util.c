#include "globals.h"
#include "util.h"

void printToken(TokenType token, const char *tokenString)
{
  switch (token)
  {
  case IF:
    fprintf(listing, "Reserved Word: %s\n", tokenString);
    break;
  case ELSE:
    fprintf(listing, "Reserved Word: %s\n", tokenString);
    break;
  case INT:
    fprintf(listing, "Reserved Word: %s\n", tokenString);
    break;
  case RETURN:
    fprintf(listing, "Reserved Word: %s\n", tokenString);
    break;
  case VOID:
    fprintf(listing, "Reserved Word: %s\n", tokenString);
    break;
  case WHILE:
    fprintf(listing, "Reserved Word: %s\n", tokenString);
    break;
  case ASSIGN:
    fprintf(listing, "Symbol: =\n");
    break;
  case LESS_THAN:
    fprintf(listing, "<\n");
    break;
  case EQ:
    fprintf(listing, "==\n");
    break;
  case GREATER_THAN:
    fprintf(listing, ">\n");
    break;
  case LESS_THAN_EQUAL:
    fprintf(listing, "<=\n");
    break;
  case GREATER_THAN_EQUAL:
    fprintf(listing, ">=\n");
    break;
  case NOT_EQUAL:
    fprintf(listing, "!=\n");
    break;
  case OPEN_BRACKET:
    fprintf(listing, "[\n");
    break;
  case CLOSE_BRACKET:
    fprintf(listing, "]\n");
    break;
  case OPEN_KEYS:
    fprintf(listing, "{\n");
    break;
  case CLOSE_KEYS:
    fprintf(listing, "}\n");
    break;
  case OPEN_PARENTHESES:
    fprintf(listing, "(\n");
    break;
  case CLOSE_PARENTHESES:
    fprintf(listing, ")\n");
    break;
  case SEMICOLON:
    fprintf(listing, ";\n");
    break;
  case COMMA:
    fprintf(listing, ",\n");
    break;
  case SUM:
    fprintf(listing, "+\n");
    break;
  case SUBTRACT:
    fprintf(listing, "-\n");
    break;
  case MULTIPLY:
    fprintf(listing, "*\n");
    break;
  case DIVIDE:
    fprintf(listing, "/\n");
    break;
  case ENDFILE:
    fprintf(listing, "EOF\n");
    break;
  case NUM:
    fprintf(listing, "Number: %s\n", tokenString);
    break;
  case ID:
    fprintf(listing, "ID: %s\n", tokenString);
    break;
  case ERROR:
    fprintf(listing, "ERROR: %s\n", tokenString);
    break;
  default:
    fprintf(listing, "Unknown token: %d\n", token);
  }
}

void printTokenForError(TokenType token, const char *tokenString)
{
  switch (token)
  {
  case IF:
    fprintf(listing, "%s", tokenString);
    break;
  case ELSE:
    fprintf(listing, "%s", tokenString);
    break;
  case INT:
    fprintf(listing, "%s", tokenString);
    break;
  case RETURN:
    fprintf(listing, "%s", tokenString);
    break;
  case VOID:
    fprintf(listing, "%s", tokenString);
    break;
  case WHILE:
    fprintf(listing, "%s", tokenString);
    break;
  case ASSIGN:
    fprintf(listing, "=");
    break;
  case LESS_THAN:
    fprintf(listing, "<");
    break;
  case EQ:
    fprintf(listing, "==");
    break;
  case GREATER_THAN:
    fprintf(listing, ">");
    break;
  case LESS_THAN_EQUAL:
    fprintf(listing, "<=");
    break;
  case GREATER_THAN_EQUAL:
    fprintf(listing, ">=");
    break;
  case NOT_EQUAL:
    fprintf(listing, "!=");
    break;
  case OPEN_BRACKET:
    fprintf(listing, "[");
    break;
  case CLOSE_BRACKET:
    fprintf(listing, "]");
    break;
  case OPEN_KEYS:
    fprintf(listing, "{");
    break;
  case CLOSE_KEYS:
    fprintf(listing, "}");
    break;
  case OPEN_PARENTHESES:
    fprintf(listing, "(");
    break;
  case CLOSE_PARENTHESES:
    fprintf(listing, ")");
    break;
  case SEMICOLON:
    fprintf(listing, ";");
    break;
  case COMMA:
    fprintf(listing, ",");
    break;
  case SUM:
    fprintf(listing, "+");
    break;
  case SUBTRACT:
    fprintf(listing, "-");
    break;
  case MULTIPLY:
    fprintf(listing, "*");
    break;
  case DIVIDE:
    fprintf(listing, "/");
    break;
  case ENDFILE:
    fprintf(listing, "EOF");
    break;
  case NUM:
    fprintf(listing, "%s", tokenString);
    break;
  case ID:
    fprintf(listing, "%s", tokenString);
    break;
  case ERROR:
    fprintf(listing, "%s", tokenString);
    break;
  default:
    fprintf(listing, "%d", token);
  }
}

void aggScope(TreeNode *t, char *scope)
{
  int i;
  while (t != NULL)
  {
    for (i = 0; i < MAXCHILDREN; ++i)
    {
      t->attr.scope = scope;
      aggScope(t->child[i], scope);
    }
    t = t->sibling;
  }
}

TreeNode *newStmtNode(StatementKind kind)
{
  TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
  int i;
  if (t == NULL)
    fprintf(listing, "Out of memory error at line %d\n", lineno);
  else
  {
    for (i = 0; i < MAXCHILDREN; i++)
      t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = statementK;
    t->kind.stmt = kind;
    t->lineno = lineno;
    t->attr.scope = "global";
  }
  return t;
}

TreeNode *newExpNode(ExpressionIdentifier kind)
{
  TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
  int i;
  if (t == NULL)
    fprintf(listing, "Out of memory error at line %d\n", lineno);
  else
  {
    for (i = 0; i < MAXCHILDREN; i++)
      t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = expressionK;
    t->kind.exp = kind;
    t->lineno = lineno;
    t->type = VOID;
    t->attr.scope = "global";
  }
  return t;
}

char *copyString(char *s)
{
  int n;
  char *t;
  if (s == NULL)
    return NULL;
  n = strlen(s) + 1;
  t = malloc(n);
  if (t == NULL)
    fprintf(listing, "Out of memory error at line %d\n", lineno);
  else
    strcpy(t, s);
  return t;
}

static indentno = 0;

#define INDENT indentno += 2
#define UNINDENT indentno -= 2

static void printSpaces(void)
{
  int i;
  for (i = 0; i < indentno; i++)
    fprintf(listing, " ");
}

void printTree(TreeNode *tree)
{
  int i;
  INDENT;
  while (tree != NULL)
  {
    printSpaces();
    if (tree->nodekind == statementK)
    {
      switch (tree->kind.stmt)
      {
      case ifK:
        fprintf(listing, "If\n");
        break;
      case assignK:
        fprintf(listing, "Assign\n");
        break;
      case whileK:
        fprintf(listing, "While\n");
        break;
      case variableK:
        fprintf(listing, "Variable %s\n", tree->attr.name);
        break;
      case functionK:
        fprintf(listing, "Function %s\n", tree->attr.name);
        break;
      case callK:
        fprintf(listing, "Call to Function %s \n", tree->attr.name);
        break;
      case returnK:
        fprintf(listing, "Return\n");
        break;

      default:
        fprintf(listing, "Unknown ExpNode kind\n");
        break;
      }
    }
    else if (tree->nodekind == expressionK)
    {
      switch (tree->kind.exp)
      {
      case operationK:
        fprintf(listing, "Operation: ");
        printToken(tree->attr.op, "\0");
        break;
      case constantK:
        fprintf(listing, "Constant: %d\n", tree->attr.val);
        break;
      case idK:
        fprintf(listing, "Id: %s\n", tree->attr.name);
        break;
      case vectorK:
        fprintf(listing, "Vector: %s\n", tree->attr.name);
        break;
      case vectorIdK:
        fprintf(listing, "Index [%d]\n", tree->attr.val);
        break;
      case typeK:
        fprintf(listing, "Type %s\n", tree->attr.name);
        break;

      default:
        fprintf(listing, "Unknown ExpNode kind\n");
        break;
      }
    }
    else
      fprintf(listing, "Unknown node kind\n");
    for (i = 0; i < MAXCHILDREN; i++)
      printTree(tree->child[i]);
    tree = tree->sibling;
  }
  UNINDENT;
}
