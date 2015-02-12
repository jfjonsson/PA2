#define PARSER_H

#include "Lexer.h"

class Parser {

public:
    Parser () { }
    Parser (Lexer l) : lex(l) { }
    void parse ();
private:
    Lexer lex;
};
