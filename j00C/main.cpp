#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#define TEST "tests/a.txt"

using namespace std;

regex tk_num("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
regex tk_assig_op("(\\=|\\+=|\\-=|\\*=|\\/=|\\%=)");
regex tk_bit_op("(\\&|\\||\\^|\\~|\\<<|\\>>)");
regex tk_log_op("(\\&&|\\|\\||\\!)");
regex tk_mat_op("(\\/|\\+|\\-|\\*|\\%)");
regex tk_rel_op("(\\=\\=|\\!\\=|\\>|\\<|\\>\\=|\\<\\=)");
regex tk_puntuation("(\\,|\\:|\\;|\\[|\\]|\\{|\\}|\\(|\\))");
regex ignore_line("(\\/\\*|\\*\\/|\\/\\/)");
regex id("[a-zA-Z][a-zA-Z_0-9]*");

int main () {
  string input;

  while(true)
  {
    cout<<"Enter the input: ";
    cin>>input;
    if(!cin) break;
    //Exit when the user inputs q
    if(input=="q")
        break;
    if(regex_match(input, tk_puntuation))
        cout<<"Input match"<<endl;
    else
    cout<<"Invalid input : Imput not match"<<endl;
  }

  /*
  string input;
  ifstream fl(TEST);

  while (getline (fl, text)) {
    cout << text;
  }
  fl.close();
  */

  return 0;
}
