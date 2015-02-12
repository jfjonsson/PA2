#include "Lexer.h"

int main() {
    Lexer lex;
    for (int i = 0; i < 5; i++) {
        Token tok = lex.nextToken();
        cout << "Lexeme: " << tok.lexeme << ", TokenCode: " << tok.tcode << endl;
    }
    return 0;
}
