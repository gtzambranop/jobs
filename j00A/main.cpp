#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 256;
char key[] = "RYUKSHINIGAMI";
char global[SIZE];

void clean(char* s)
{
    int temp;
    for (char* s2 = s; *s2; ++s2) {
        if (*s2 != ' ')
            temp = (int)*s;
            if((temp > 64) && (temp < 91))
                *s++ = *s2;
    }
    *s = 0;
}


int length(char *message)
{
    return sprintf(message, "%s", message);
}

void reset(char *s)
{
    int l = length(s);
    for(int i = 0; i < l; i++)
        s[i] = global[i];
}
void upper(char *message)
{
    int length_message = length(message);
    int i;
    for(i = 0; i < length_message; i++)
        message[i] = toupper(message[i]);
}

bool compare(char a[],char b[]){
    for(int i=0;a[i]!='\0';i++){
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

void my_crypto_method(char *result, char *message, bool encrypt)
{
    int length_message = length(message);
    int length_key = sprintf(key, "%s", key);
    char character_k,
        temporal;
    int ascii_k,
        ascii_m,
        auxiliar,
        i;

    upper(message);
    for(i = 0; i < length_message; i++)
    {
        character_k = key[i % length_key];
        ascii_k = (int)character_k;
        ascii_m = (int)message[i];
        if(encrypt){
            auxiliar = ascii_k + ascii_m;
        } else {
            auxiliar = 26 - ascii_k + ascii_m;
        }
        temporal= (auxiliar % 26) + 65;
        result[i] = (char)temporal;
    }
}

int menu(){
    int option;
    cout << "\n\t==========================================\n";
    cout << "\t\t\t Menú";
    cout << "\n\t==========================================\n";
    cout << "\n\t\t1. Crear usuario y Contraseña\n";
    cout << "\t\t2. Capturar 5 palabras\n";
    cout << "\t\t3. Mostrar las 5 palabras\n";
    cout << "\t\t4. Mostrar Usuario y Contraseña\n";
    cout << "\t\t5. Salir\n";
    cout << "\n\t==========================================\n";
    cout << "\n\tSeleccione una opción: ";
    cin >> option;
    return option;
}

void sign_up()
{
    char input[SIZE];
    char result[SIZE];
    ofstream fl;

    reset(input);
    reset(result);
    fl.open("data_user.txt");
    cout << "\tIngrese usuario: ";
    cin >> input;
    my_crypto_method(result, input, true);
    fl << result << "\n";
    reset(input);
    reset(result);
    cout << "\tIngrese contraseña: ";
    cin >> input;
    my_crypto_method(result, input, true);
    fl << result;
    fl.close();
}


bool sign_in()
{
    char input[SIZE];
    char message[SIZE];
    char result[SIZE];
    char options[2][SIZE] = {"\tIngrese su usuario: ",
                        "\tIngrese su contraseña: "};
    ifstream fl;

    fl.open("data_user.txt");
    for (int i = 1; i <= 2; i++){
        reset(input);
        reset(result);
        reset(message);
        fl.getline(message, SIZE);
        clean(message);
        my_crypto_method(result, message, false);
        cout << options[i-1];
        cin >> input;
        upper(input);
        if(compare(input, result) == false){
            cout << "Datos incorrectos.\n";
            return false;
        }
    }
    fl.close();
    return true;
}

void input_words()
{
    char input[SIZE];
    char result[SIZE];
    ofstream fl;
    int i;
    cout << "\n\t==========================================\n";
    cout << "\t\t Ingresar las 5 Palabras";
    cout << "\n\t==========================================\n";

    fl.open("words.txt");
    for(i = 0; i < 5; i++)
    {
        reset(input);
        reset(result);
        cout << "\tIngrese la palabra " << i + 1 << ": ";
        cin >> input;
        if(length(input) < 5){
            cout << "\tLa palabra tiene menos de 5 caracteres\n";
            break;
        }
        my_crypto_method(result, input, true);
        fl << result << "\n";
    }
    fl.close();
}

void read_file(char *fl_name, int lines)
{
    char message[SIZE];
    char result[SIZE];
    ifstream fl;

    fl.open(fl_name);
    for (int i = 1; i <= lines; i++){
        reset(message);
        reset(result);
        fl.getline(message, SIZE);
        clean(message);
        my_crypto_method(result, message, false);
        cout << "\t" << result << "\n";
    }
    fl.close();
}

int main()
{
    char words[] = "words.txt";
    char user[] = "data_user.txt";
    int option,
        i;

    do
    {
        option = menu();

        switch (option)
        {
            case 1:
                sign_up();
                break;
            case 2:
                if(sign_in())
                    input_words();
                break;
            case 3:
                if(sign_in())
                    read_file(words, 5);
                break;
            case 4:
                read_file(user, 2);
                break;
            case 5:
                cout << "\tAdiós :)\n";
                break;

            default:
                cout << "\tEntrada inválida\n";
                break;
        }
    }while(option < 5);
    return 0;
}