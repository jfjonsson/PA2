#include "Parser.h"
#include <stdio.h>
#include <iostream>

int main() {
    Lexer myLexer;
    Parser myParser(myLexer); 
    myParser.parse();

    return 0;
}
