#define LEXER_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Token.h"

class Lexer {
    char c;
    // Wrapper that checks sigle character tokens
    // ( '+', '-', '('... etc )
    Token checkToken(char tok);
public:
    // Initialize c as NULL
    Lexer () : c('\0') { };
    // Returns the next token, error token
    // if token was invalid
    Token nextToken();
};
