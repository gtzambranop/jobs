#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>
#include <stdio.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

#define TEST "tests/a.txt"

using namespace std;

map <string, string> mp_assig_op;
map <string, string> mp_bit_op;
map <string, string> mp_log_op;
map <string, string> mp_mat_op;
map <string, string> mp_puntuation;
map <string, string> mp_rel_op;
map <string, string> mp_reserved_w;
map <string, string> mp_special_s;

regex tk_num("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
regex tk_assig_op("(\\=|\\+=|\\-=|\\*=|\\/=|\\%=)");
regex tk_bit_op("(\\&|\\||\\^|\\~|\\<<|\\>>)");
regex tk_log_op("(\\&&|\\|\\||\\!)");
regex tk_mat_op("(\\/|\\+|\\-|\\*|\\%)");
regex tk_puntuation("(\\,|\\:|\\;|\\[|\\]|\\{|\\}|\\(|\\))");
regex tk_rel_op("(\\=\\=|\\!\\=|\\>|\\<|\\>\\=|\\<\\=)");
regex tk_special_w("(\\#)");
regex ignore_line("(\\/\\*|\\*\\/|\\/\\/)");
regex id("[a-zA-Z][a-zA-Z_0-9]*");

const char* path_data = "./data/";
const char* path_tests = "./tests/";

string* tokenize(string s, string del = " ") {
    string* tkns = new string[256];
    int start = 0;
    int end = s.find(del);
    int count = 0;

    while (end != -1) {
        tkns[count] =  s.substr(start, end - start);
        start = end + del.size();
        end = s.find(del, start);
        count++;
    }
    tkns[count] = s.substr(start, end - start);
    return tkns;
}

void populate_dictionary(char * name_file, map <string, string> &mp) {
    string text;
    string *tkns;

    ifstream fl(name_file);
    if(name_file[7] == '6')
    {
        while (getline (fl, text)) {
            tkns = tokenize(text, "\t");
            mp[tkns[0]] = "";
        }
    }else {
        while (getline (fl, text)) {
            tkns = tokenize(text, "\t");
            mp[tkns[0]] = tkns[1];
        }
    }
    fl.close();
}

void list_dir() {
    struct dirent *entry;
    DIR *dir = opendir(path_data);
    if (dir == NULL) {
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if(entry->d_name[0] != '.') {
            char* name;
            name = (char*)malloc(sizeof(char) * 256);
            strcat(name, path_data);
            strcat(name, entry->d_name);
            switch (name[7]) {
            case '0':
                populate_dictionary(name, mp_assig_op);
                break;

            case '1':
                populate_dictionary(name, mp_bit_op);
                break;

            case '2':
                populate_dictionary(name, mp_log_op);
                break;

            case '3':
                populate_dictionary(name, mp_mat_op);
                break;

            case '4':
                populate_dictionary(name, mp_puntuation);
                break;

            case '5':
                populate_dictionary(name, mp_rel_op);
                break;

            case '6':
                populate_dictionary(name, mp_reserved_w);
                break;

            case '7':
                populate_dictionary(name, mp_special_s);
                break;

            default:
                break;
            }
            free(name);
        }
    }

    closedir(dir);
}

void analyze(string fragment, int position){
    if(regex_match(&fragment[0], ignore_line)) {
        cout << "IGNORAR" << endl;
    }
}

int main(int argc, char const *argv[])
{
    string line;
    char* name_test_file = (char*)malloc(sizeof(char) * 256);
    strcat(name_test_file, path_tests);
    if(!argv[1]) {
        cout << "Execute as: ./main name_file_test.txt" << endl;
        return 0;
    }
    strcat(name_test_file, argv[1]);
    cout << name_test_file << endl;

    list_dir();
    cout << "PRUEBA" << endl;
    int b = mp_bit_op.count("&");
    cout << b << endl;

    /*
    ifstream fl(TEST);

    while (getline (fl, line)) {
        cout << line;
    }
    fl.close();
    /*
    string* c;

    string a = "Hi$%do$%you$%do$%!";
    c = tokenize(a, "$%");

    for (int i = 0; c[i] != ""; i++)
    {
        cout << c[i] << endl;
    }
    delete[] c;
    */

    /*
    string input;

    while(true)
    {
        cout<<"Enter the input: ";
        cin>>input;
        if(!cin) break;
        //Exit when the user inputs q
        if(input=="q")
            break;
        if(regex_match(input, tk_special_w))
            cout<<"Input match"<<endl;
        else
        cout<<"Invalid input : Imput not match"<<endl;
    }
    */



    return 0;
}
