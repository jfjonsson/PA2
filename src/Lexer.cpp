#include "Lexer.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>

Token Lexer::nextToken () {
    // Vector to construct tokens with multiple characters
    vector<char> token;
    if(c) {
        return checkToken(c);
    } else {
        // Ignore whitespace and get first char
        while (scanf("%c", &c) != EOF && isspace(c));

        // Check if alpha or digit
        if(isdigit(c)) {
            // Scan while only digits 
            do {
                token.push_back(c);
            } while (scanf("%c", &c) != EOF && isdigit(c));
            
            // If ended with space no need to hold last char
            if (isspace(c))
                c = '\0';

            return Token(string(token.begin(), token.end()), (isalpha(c)) ? Token::ERROR :Token::INT);
        } else if(isalpha(c)) {
            // Scan while only alpha
            do {
                token.push_back(c);
            } while (scanf("%c", &c) != EOF && isalpha(c));

            string tok(token.begin(), token.end());

            // If ended with space no need to hold last char
            if (isspace(c)) {
                c = '\0';
            } else if (isdigit(c)) { // Syntax error return invalid Token
                return Token(tok, Token::ERROR);
            }

            // Check if string is special token, (end or print)
            // else return as ID
            if(tok == "end")
                return Token(tok, Token::END);
            else if(tok == "print")
                return Token(tok, Token::PRINT);
            else
                return Token(tok, Token::ID);
        } else
           return checkToken(c);
    }
}

// Wrapper function that returns teh apropriate Token.
// Error Token if invalid
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
        return Token(string(&tok), Token::ERROR);
    } 
}
