#include <iostream>
#include "interpreter.h"
using namespace std;

int main(){
    while(true){
        string inputText = "";
        try{
            cout << "Calc > ";
            getline(cin, inputText);
        }catch(const exception& e){
            cout << e.what();
            break;
        }
        if (inputText == ""){
            continue;
        }

        Interpreter* interpreter = new Interpreter(inputText);
        int result = interpreter->expr();
        cout << "> " << result << endl;
    }
    return 0;
}
