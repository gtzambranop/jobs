// my first program in C++
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void test(char* x, char *y){
    //int l = sizeof(y)/sizeof(*y);
    int l = sprintf(y, "%s", y);
    cout << l;

    for(int i = 0; i < l; i++){
        x[i] = y[i];
    }
}


// https://github.com/gtzambranop/UN_2020_2/blob/develop/ICS/codes/vigenere/vigenere.py
int main()
{
    ifstream fl;

    const int SIZE = 256;
    char str[SIZE];

    /*
    char c = 'A';
    int ascii = (int)c;
    cout << ascii;
    char d = (char) ascii;
    cout << d;
    cout<< "\n";

    char t[SIZE];
    char g[SIZE] = "kgfhgj";
    test(t,g);
    cout << t;
    */

    cout << sprintf("hola", "%s", "hola");
    /*
    fl.open("data_user.txt");
    cout << "Ingrese su usuario:";
    cin >> str;
    fl << str << "\n";
    fl << str << "\n";
    fl.close();
    */
    return 0;
}