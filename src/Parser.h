#define PARSER_H

#include "Lexer.h"
#include <stdlib.h>
#include <stdio.h>

class Parser {

public:
    Parser () { }
    Parser (Lexer l) : lex(l) { }
    void parse ();
private:
    Lexer lex;
    Token tok;
    void statements ();
    void statement ();
    void expr ();
    void term ();
    void factor ();
    void syntax_error ();
    void next ();
};
