#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include "token.h"
using namespace std;

class Interpreter {
public:
    Interpreter(string inputText);
    int expr();
private:
    static const string EOF_TYPE;
    static const string INTEGER_TYPE;
    static const string PLUS_TYPE;

    string text;
    int position;
    Token* currentToken;
    
    void error();
    Token* getNextToken();
    void eat(string tokenType);
};
#endif