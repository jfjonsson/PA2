#define PARSER_H

#include "Lexer.h"

class Parser {

public:
    // Constructor initializes lex to the parameter Lexer
    Parser (Lexer l) : lex(l) { }
    // Parser function initializes the compiler process
    void parse ();
private:
    Lexer lex;
    // The current Token
    Token tok;
    // The non-terminals of the grammar
    void statements ();
    void statement ();
    void expr ();
    void term ();
    void factor ();
    // Wrapper function for errors
    void syntax_error (string msg);
    //Wrapper function to get and check next Token
    void next ();
};
