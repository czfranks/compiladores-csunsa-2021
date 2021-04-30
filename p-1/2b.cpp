#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string filename = "./utils/pseudocodigo.txt";
    ifstream in(filename.c_str(), ios_base::in);
    char c;
    while(in.get(c)){
        cout << c;
    }
    cout << endl;
    return 0;
}
