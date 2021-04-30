#include <iostream>
#include <fstream>
#include <map>
#include <set>

using namespace std;

#define ENTERO 0
#define PALABRA 1
#define SIMBOLO 2
#define SEPARADOR 3

map<int, set<string> > vocablos;

int getState(char c)
{
    if ('0'<=c && c<='9') return ENTERO;
    if (('A'<=c && c<='Z')||('a'<=c && c<='z')) return PALABRA;
    if (c=='\t' || c=='\n' || c==' ') return SEPARADOR;
    return SIMBOLO;
}

void getVocablos(const string& filename)
{
    ifstream in(filename.c_str(), ios_base::in);
    char c;
    int state;
    string buffer;

    in.get(c);
    buffer = string(1,c);
    state = getState(c);
    while(in.get(c)){
        if(state != getState(c) || state == SIMBOLO)
        {
            vocablos[state].insert(buffer);
            buffer = string(1,c);
            state = getState(c);
        }
        else buffer.push_back(c);
    }
}

int main(){
    string filename = "./utils/plaintext.txt";
    getVocablos(filename);
    for(auto vocablo : vocablos)
    {   
        int state =  vocablo.first;
        if(state == SEPARADOR) continue;
        cout << (state==0? "Entero: " : (state==1? "Palabra: ": "Simbolo: "));
        for(auto token : vocablo.second)
        {
            cout << token << "  ";
        }
        cout << endl;
    }
    return 0;
}
