%{
#ifdef PRINT
#define TOKEN(t) printf("TOKEN: " #t "\n");
#define NUMBER_VALUE(t) printf("NUMBER_VALUE: %s, TOKEN: " #t "\n", yytext);
#else
#define TOKEN(t) return(t);
#define NUMBER_VALUE(t) yylval.iVal = atoi(strdup(yytext)); return(t);


#include <string.h>
extern SYMTABNODEPTR symTab[SYMTABSIZE];
extern int currentSymTabSize;
int installId(char *);
#endif
%}
delim          [ \t\r\n]
ws             {delim}+

integer        [0-9]+

%%
{ws}           ;

"b"            TOKEN(BASES)
"-"            TOKEN(BETWEEN)
"^"            TOKEN(GIVEN)
"e"            TOKEN(EXPONENT_PARTICLE)
[0-9]+         NUMBER_VALUE(INTEGER_CONSTANT)
.              fprintf(stderr, "Error: unexpected symbol in lex: %s, %d\n", yytext, yytext[0]);
%%
#ifndef PRINT
SYMTABNODEPTR newSymTabNode()
{
    return ((SYMTABNODEPTR)malloc(sizeof(SYMTABNODE)));
}

int lookup(char *s)
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE];
    extern int currentSymTabSize;
    int i;

    for(i=0; i<currentSymTabSize; i++)
    {
        if(strncmp(s,symTab[i]->identifier,IDLENGTH) == 0)
        {
            return (i);
        }
    }
    return (-1);    
}

int installId(char *id) 
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE]; 
    extern int currentSymTabSize;
    int index;

    index = lookup(id);
    if (index >= 0)
    {
        return (index);
    }
    else if (currentSymTabSize >= SYMTABSIZE) 
          /* SYMTAB is full */
          return (NOTHING) ;
    else
    {
       symTab[currentSymTabSize] = newSymTabNode();

       strncpy(symTab[currentSymTabSize]->identifier,id,IDLENGTH);
       symTab[currentSymTabSize]->identifier[IDLENGTH-1] = '\0';
       symTab[currentSymTabSize]->contentType = -1;
       return(currentSymTabSize++);
    }
}
#endif