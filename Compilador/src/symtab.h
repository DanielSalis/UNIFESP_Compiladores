#ifndef _SYMTAB_H_
#define _SYMTAB_H_

/* Procedure stInsert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void stInsert( char * name, int lineno, int loc, char* scope, char* typeID, char* typeData);

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup (char * name, char* scope );

char* statementFinderType(char* name, char* scope);

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing);

#endif
