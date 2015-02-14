#!/bin/bash
if [ $# -eq 0 ]
then
        echo "Missing argument!"
elif [ -n $1 ]
then 
    g++ -o S_interpreter Interpreter.cpp
    g++ -o L_compiler Compiler.cpp Parser.cpp Lexer.cpp
    ./L_compiler < $1 | ./S_interpreter
fi
