#include <map>
#include <list>
#include <regex>
#include <string>
#include <stdio.h>
#include <fstream>
#include <dirent.h>
#include <iostream>
#include <sys/types.h>
#include <bits/stdc++.h>

using namespace std;

/*
map <string, string> test;
test["Hello"] = "hola";
cout << test["Hello"] << endl;
*/

map <string, string> mp_assig_op;
map <string, string> mp_bit_op;
map <string, string> mp_log_op;
map <string, string> mp_mat_op;
map <string, string> mp_puntuation;
map <string, string> mp_rel_op;
map <string, string> mp_reserved_w;
map <string, string> mp_special_s;

regex num("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
regex tk_assig_op("(\\=|\\+=|\\-=|\\*=|\\/=|\\%=|\\++|\\--)");
regex tk_bit_op("(\\&|\\||\\^|\\~|\\<<|\\>>)");
regex tk_log_op("(\\&&|\\|\\||\\!)");
regex tk_mat_op("(\\/|\\+|\\-|\\*|\\%)");
regex tk_puntuation("(\\,|\\:|\\;|\\[|\\]|\\{|\\}|\\(|\\))");
regex tk_rel_op("(\\=\\=|\\!\\=|\\>|\\<|\\>\\=|\\<\\=)");
regex tk_special_s("(\\#)");
regex ignore_line("(\\/\\*|\\*\\/|\\/\\/)");
regex id("[a-zA-Z][a-zA-Z_0-9]*");

const char* path_data = "./data/";
const char* path_tests = "./tests/";

// separate the words of a string by a delimiter and add the fragments to a list
list <string> tokenize(string s, string del = " ") {
    list <string> tokens;
    int start = 0;
    int end = s.find(del);
    int count = 0;

    while (end != -1) {
        tokens.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
        count++;
    }
    tokens.push_back(s.substr(start, end - start));
    return tokens;
}

// Create the maps based on the files in the data directory
void populate_dictionary(char * name_file, map <string, string> &mp) {
    string text;
    list <string> tokens;

    ifstream fl(name_file);
    if(name_file[7] == '6')
    {
        while (getline (fl, text)) {
            tokens = tokenize(text, "\t");
            mp[tokens.front()] = "reserved_w";
        }
    }else {
        while (getline (fl, text)) {
            tokens = tokenize(text, "\t");
            mp[tokens.front()] = tokens.back();
        }
    }
    fl.close();
}

// order to create the dictionaries
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

// print the tokens found in a table format
void register_token(string token_name, string token, int position[]){
    printf("%d \t %d \t %s \t\t %s\n", position[0], position[1], token_name.c_str(), token.c_str());
}

// filter each word of a line, in the different categories, be it tokens, +
// numbers or identifiers
void analyze(list <string> words, int position[]){
    string temp_word,
        token_name;
    int word_length = 0;

    if (!words.empty()) {
        temp_word = words.front();
        word_length = temp_word.length();
        /*
        if (regex_match(temp_word.substr(0, 1), tk_special_s)) {
            words.pop_front();
            words.push_front(temp_word.substr(1, word_length - 1));
            words.push_front(temp_word.substr(0, 1));
            temp_word = temp_word.substr(0, 1);
            word_length = 1;
            token_name = mp_special_s[temp_word];
        }
        */
        if (regex_match(temp_word, tk_special_s)){
            token_name = mp_special_s[temp_word];
        } else if (mp_reserved_w.count(temp_word) > 0){
            token_name = mp_reserved_w[temp_word];
        } else if (regex_match(temp_word, id)){
            token_name = "id\t";
        } else if (regex_match(temp_word, num)){
            token_name = "number";
        } else if (regex_match(temp_word, tk_assig_op)){
            token_name = mp_assig_op[temp_word];
        } else if (regex_match(temp_word, tk_bit_op)){
            token_name = mp_bit_op[temp_word];
        } else if (regex_match(temp_word, tk_log_op)){
            token_name = mp_log_op[temp_word];
        } else if (regex_match(temp_word, tk_puntuation)){
            token_name = mp_puntuation[temp_word];
        } else if (regex_match(temp_word, tk_rel_op)){
            token_name = mp_rel_op[temp_word];
        } else if (regex_match(temp_word, tk_mat_op)){
            token_name = mp_mat_op[temp_word];
        }
        if(!regex_match(temp_word, ignore_line)) {
            if (temp_word != "") {
                register_token(token_name, temp_word, position);
            }
            position[1] += word_length + 1;
            words.pop_front();
            analyze(words, position);
        }
    }
}

int main(int argc, char const *argv[])
{
    string line;
    list <string> words;
    char* name_test_file = (char*)malloc(sizeof(char) * 256);
    int position[2] = {1, 1};   // [line, column]

    // argv[1] = name test file
    if(!argv[1]) {
        cout << "Execute as: ./main name_file_test.txt" << endl;
        return 0;
    }

    strcat(name_test_file, path_tests);
    strcat(name_test_file, argv[1]);

    ifstream fl(name_test_file);

    list_dir();
    printf("\nLine \tColumn \tName Token \t\t Token\n\n");

    while (getline (fl, line)) {
        position[1] = 1;
        words = tokenize(line, " ");
        analyze(words, position);
        position[0] ++;
    }
    fl.close();
    return 0;
}
