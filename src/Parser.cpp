#include "Parser.h"

void Parser::parse () {
    next();
    statements();
}

void Parser::statements () {
    if(tok.tcode == Token::END) {
        exit(0);
    }
    statement();
    if(tok.tcode != Token::SEMICOL) {
        syntax_error();
    } else {
        next();
    }
    statements();
}

void Parser::statement () {
    if(tok.tcode == Token::ID) {
        printf("PUSH %s\n", tok.lexeme.c_str());
        next();
        if(tok.tcode == Token::ASSIGN) {
            next();
            expr();
            printf("ASSIGN\n");
        } else {
            syntax_error();
        }
    } else if(tok.tcode == Token::PRINT) {
        next();
        if(tok.tcode == Token::ID) {
            printf("PUSH %s\n", tok.lexeme.c_str());
            printf("PRINT\n");
            next();
        } else {
            syntax_error();
        }
    } else {
        syntax_error();
    }
}

void Parser::expr () {
    term();
    if(tok.tcode == Token::PLUS) {
        next();
        expr();
        printf("ADD\n");
    } else if(tok.tcode == Token::MINUS) {
        next();
        expr();
        printf("SUB\n");
    }
}

void Parser::term () {
    factor();
    if(tok.tcode == Token::MULT) {
        next();
        term();
        printf("MULT\n");
    }
}

void Parser::factor () {
    if(tok.tcode == Token::INT || tok.tcode == Token::ID) {
        printf("PUSH %s\n", tok.lexeme.c_str());
    } else if (tok.tcode == Token::LPAREN) {
        next();
        expr();
        if(tok.tcode != Token::RPAREN) {
            syntax_error();
        }
    } else {
        syntax_error();
    }
    next();
}

void Parser::syntax_error () {
    printf("Syntax error!\n");
    exit(0);
}

void Parser::next () {
    tok = lex.nextToken();
    if(tok.tcode == Token::ERROR)
        syntax_error();
}
