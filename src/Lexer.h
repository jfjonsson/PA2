#define LEXER_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Token.h"

class Lexer {
    char c;
    Token checkToken(char tok);
public:
    Lexer () : c('\0') { };
    Token nextToken();
};
