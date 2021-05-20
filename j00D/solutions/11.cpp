#include <iostream>
#include <cstdlib>

#define ROWS 5
#define COLUMS 5

using namespace std;

void verify(int x[][COLUMS])
{
    bool is_diagonal = true;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMS; j++)
        {
            // Primera condición: es un elemento de la diagonal hacia abajo?
            // Segunda condición: El elemento es diferente de cero?
            if((i > j) && (x[i][j] != 0))
            {
                is_diagonal = false; // -> No diagonal
                break;
            }
        }
    }
    if(is_diagonal)
    {
        cout << "La matriz ingresada es diagonal." << endl;
    } else {
        cout << "La matriz ingresada NO es diagonal." << endl;
    }
}

int main()
{
    int x[ROWS][COLUMS];
    int input;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMS; j++)
        {
            /*
            x[i][j] = rand() % 16 + (-5);   // valor aleatorio entre -5 y 5
            cout << "x[" << i << "][" << j << "] = " << x[i][j] << endl;
            */

            cout << "Ingrese el dato x[" << i+1 << "][" << j+1 << "]" << endl;
            cin >> input;
            x[i][j] = input;
        }
    }

    verify(x);

    return 0;
}
