#define TOKEN_H

#include <string>
using namespace std;

class Token {
public:
    enum TokenCode { ID, ASSIGN, SEMICOL, INT, PLUS, 
        MINUS, MULT, LPAREN, RPAREN, PRINT, END, ERROR };
    Token() { };
    Token(string l, TokenCode t) : lexeme(l), tcode(t) { };
    string lexeme;
    TokenCode tcode;
};
