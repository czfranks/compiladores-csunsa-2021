#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Token {
public:
    Token(){}
    Token(string value, int pos, string tipo){
        this->value = value;
        this->pos = pos;
        this->tipo = tipo;
    }

    string toString(){
       string s = "";
       s+="Token["+value+"]: pos = ";
       s+=to_string(pos);
       s+=", tipo = "+tipo;
       return s;
    }

private:
    string value;
    int pos;
    string tipo;
};

Token reconoceNumero(char *ptr, int& pos)
{
    string s = "";
    int p = pos;
    while('0'<=ptr[pos] && ptr[pos]<='9'){
        s+=string(1,ptr[pos]);
        ++pos;
    }
    return Token(s,p,"N");
}


Token reconoceVariable(char *ptr, int& pos)
{
    string s = "";
    int p = pos;
    while('a'<=ptr[pos] && ptr[pos]<='z' ||
          'A'<=ptr[pos] && ptr[pos]<='Z' ||
          '0'<=ptr[pos] && ptr[pos]<='9'){
        s+=string(1,ptr[pos]);
        ++pos;
    }
    return Token(s,p,"V");
}



vector<Token> analizadorLexico( char *linea )
{
    vector<Token> tokens;
    int pos = 0;
    while(true){
        char c = linea[pos];
        if('0'<=c && c<='9'){
            tokens.push_back( reconoceNumero(linea, pos) );
        }
        else if('a'<=c && c<='z' || 'A'<=c && c<='Z'){
            tokens.push_back( reconoceVariable(linea, pos) );
        }
        switch (c)
        {
            case '=':
                tokens.push_back( Token("=", pos++, "O") );
                break;
            case '+':
                tokens.push_back( Token("+", pos++, "O") );
                break;
            case '-':
                tokens.push_back( Token("-", pos++, "O") );
                break;
            case '*':
                tokens.push_back( Token("-", pos++, "O") );
                break;
            case '/':
                tokens.push_back( Token("-", pos++, "O") );
            case '\0':
                break;

            default:
                ++pos;
                break;
        }
        if(c == '\0')
            break;
        if(linea[pos] == '\0') 
            break;
    }
    return tokens;
}


int main(){

    Token a("variable",0,"V");
    cout << a.toString() << endl;

    const int SIZE = 10;
    const int MAX_STR = 100;
    char linea[SIZE][MAX_STR] = {"var1 x = 2 + 3+4\0",
                                 "1+2\0",
                                 "4*2-8\0",
                                 "600 / 5+3-0\0",
                                 "A=12\0",
                                 "variable1 = 14\0",
                                 "C = A + variable1\0",
                                 "var1 x = 2 + 3+4\0",
                                 "var1 = var2 + var3 * 3\0",
                                 "var1\0"};
    
    for (int i = 0; i < SIZE; i++)
    {
        vector<Token> tokens = analizadorLexico(linea[i]);
        printf("Expresion: %s\n", linea[i]);
        for (auto token : tokens)
        {
            cout << token.toString() << endl;
        }
        cout << string(10,'-') << endl;
    }
    
        
    

    return 0;
}