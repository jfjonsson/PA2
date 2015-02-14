#include "Parser.h"

// Initialize the process
void Parser::parse () {
    next();
    statements();
}

// The starting non-terminals
void Parser::statements () {
    // Stop if Token is END
    if(tok.tcode == Token::END) {
        exit(0);
    }
    statement();
    
    // If statement is followed by a semicolon
    // we call statements recursively, 
    // else we have a syntax_error.
    if(tok.tcode != Token::SEMICOL) {
        syntax_error(tok.lexeme);
    }

    next();
    statements();
}

void Parser::statement () {
    // Following the statemnt grammar we check for
    // ID and PRINT else we have a syntax_error.
    if(tok.tcode == Token::ID) {
        printf("PUSH %s\n", tok.lexeme.c_str());
        next();
        // If the Token is ASSIGN call expr before printing 
        // the command, else we have a syntax_error
        if(tok.tcode == Token::ASSIGN) {
            next();
            expr();
            printf("ASSIGN\n");
        } else {
            syntax_error(tok.lexeme);
        }
    } else if(tok.tcode == Token::PRINT) {
        next();
        // If Token after PRINT is not ID we have a syntax_error
        if(tok.tcode == Token::ID) {
            printf("PUSH %s\n", tok.lexeme.c_str());
            printf("PRINT\n");
            next();
        } else {
            syntax_error(tok.lexeme);
        }
    } else {
        syntax_error(tok.lexeme);
    }
}

// Expr non-terminal starts by calling term
// then checks if it should handle the next Token
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

// Term non-terminal calls factor then checks 
// if it should handle the next Token
void Parser::term () {
    factor();
    if(tok.tcode == Token::MULT) {
        next();
        term();
        printf("MULT\n");
    }
}

// Factor non-terminal checks for INT and ID
// then if expr is in brackets and checks the
// syntax of bracket placement.
void Parser::factor () {
    if(tok.tcode == Token::INT || tok.tcode == Token::ID) {
        printf("PUSH %s\n", tok.lexeme.c_str());
    } else if (tok.tcode == Token::LPAREN) {
        next();
        expr();
        if(tok.tcode != Token::RPAREN) {
            syntax_error(tok.lexeme);
        }
    } else {
        syntax_error(tok.lexeme);
    }
    next();
}


// Recieves a lexeme for a Token which is 
// causing a syntax error (prints and exits).
void Parser::syntax_error (string msg) {
    printf("Syntax error for token: %s!\n", msg.c_str());
    exit(0);
}

// Next moves the net Token to tok variable
// if the Token isn't an ERROR Toekn, in which 
// case we call syntax_error.
void Parser::next () {
    tok = lex.nextToken();
    if(tok.tcode == Token::ERROR)
        syntax_error(tok.lexeme);
}
