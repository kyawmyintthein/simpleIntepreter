#include <string>
#include "interpreter.h"
#include "token.h"

using namespace std;

const string Interpreter::EOF_TYPE = "EOF";
const string Interpreter::INTEGER_TYPE = "INTEGER";
const string Interpreter::PLUS_TYPE = "PLUS";

Interpreter::Interpreter(string inputText){
    text = inputText;
    position = 0;
    currentToken = NULL;
};

int Interpreter::expr(){
    this->currentToken = this->getNextToken();
    Token* leftToken = this->currentToken;
    this->eat(INTEGER_TYPE);

    Token* opToken = this->currentToken;
    this->eat(PLUS_TYPE);

    Token* rightToken = this->currentToken;
    this->eat(INTEGER_TYPE);

    int leftTokenValue = (unsigned char) leftToken->value;
    int rightTokenValue = (unsigned char) rightToken->value;
    int result = leftTokenValue + rightTokenValue;
    return result;
};

void Interpreter::error(){
    throw std::invalid_argument("Error parsing input.");
};

void Interpreter::eat(string tokenType){
    if(this->currentToken->type == tokenType){
        this->currentToken = this->getNextToken();
    }else{
       printf("%s\n",this->currentToken->type.c_str());
        this->error();
    };
};

Token* Interpreter::getNextToken(){
    Token *token = NULL;
    string txt = this->text;
    if (this->position > txt.length() - 1){
        char val = '\0';
        token = new Token(EOF_TYPE, val);
        return token;
    };
    char currentChar = text[this->position];
    if (isdigit(currentChar)){
        token = new Token(INTEGER_TYPE, currentChar);
        this->position +=1;
        return token;
    }

    if (currentChar == '+'){
        token = new Token(PLUS_TYPE, currentChar);
        this->position +=1;
        return token;
    }
    this->error();
    return token;
};