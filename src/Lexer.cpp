#include "Lexer.h"

Token Lexer::nextToken () {
    vector<char> token;
    if(c) {
        return checkToken(c);
    } else {
        do {
            scanf("%c", &c);
        } while (isspace(c));

        if(isdigit(c)) {
            do {
                token.push_back(c);
                scanf("%c", &c);
            } while (isdigit(c));
            
            if (isspace(c)) {
                c = '\0';
            } else if (isalpha(c)) { // Syntax error
                return Token("digit_error", Token::ERROR);
            }
            return Token(string(token.begin(), token.end()), Token::INT);
        } else if(isalpha(c)) {
            do {
                token.push_back(c);
                scanf("%c", &c);
            } while (isalpha(c));

            if (isspace(c)) {
                c = '\0';
            } else if (isdigit(c)) {
                return Token("alpa_error", Token::ERROR);
            }
            string tok(token.begin(), token.end());
            if(!tok.compare("end"))
                return Token(tok, Token::END);
            else if(!tok.compare("print"))
                return Token(tok, Token::PRINT);
            else
                return Token(tok, Token::ID);
        } else
           return checkToken(c);
    }
}

Token Lexer::checkToken(char tok) {
    c = '\0';
    if(tok == ';') {
        return Token(";", Token::SEMICOL);
    } else if(tok == '+') {
        return Token("+", Token::PLUS);
    } else if(tok == '-') {
        return Token("-", Token::MINUS);
    } else if(tok == '*') {
        return Token("*", Token::MULT);
    } else if(tok == ')') {
        return Token(")", Token::RPAREN);
    } else if(tok == '(') {
        return Token("(", Token::LPAREN);
    } else if(tok == '=') {
        return Token("=", Token::ASSIGN);
    } else {
        return Token("token_error", Token::ERROR);
    } 
}
