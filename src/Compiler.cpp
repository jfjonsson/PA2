#include "Parser.h"

int main() {
    Lexer myLexer;
    Parser myParser(myLexer); 
    myParser.parse();

    return 0;
}
