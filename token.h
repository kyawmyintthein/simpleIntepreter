#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using namespace std;

class Token{
  public:
    Token(string type, char value);
    string type;
    char value;
};
#endif