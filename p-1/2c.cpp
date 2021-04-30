#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void print_file(const string& filename)
{
    ifstream in(filename.c_str(), ios_base::in);
    char c;
    cout << "\t\t[" << filename << "]" << endl;
    cout << string(10,'-') << endl;
    while(in.get(c)){
        cout << c;
    }
    cout << endl;
    cout << string(10,'-') << endl;
    in.close();
}

void cifrar(const string& file_input, const string& file_output, int k)
{
    ifstream in(file_input.c_str(), ios_base::in);
    ofstream out(file_output.c_str(), ios_base::out);
    char c;
    while(in.get(c)){
        c = (c + k)%256;
        out << c;
        
    }
    in.close();
    out.close();
}

void descifrar(const string& file_input, const string& file_output, int k)
{
    ifstream in(file_input.c_str(), ios_base::in);
    ofstream out(file_output.c_str(), ios_base::out);
    char c;
    while(in.get(c)){
        c = (c - k + 256)%256;
        out << c;
        
    }
    in.close();
    out.close();
}


int main(){
    string pseudocodigo = "./utils/pseudocodigo.txt";
    string codigo_cifrado = "./utils/codigo_cifrado.txt";
    string codigo_descifrado = "./utils/codigo_descifrado.txt";

    /* clave de cifrado Cesar */
    int k = 10;
    cifrar(pseudocodigo,codigo_cifrado, k);
    descifrar(codigo_cifrado, codigo_descifrado, k);

    print_file(pseudocodigo);
    print_file(codigo_cifrado);
    print_file(codigo_descifrado);

    return 0;
}
