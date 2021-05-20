#include <iostream>
#include <cstdlib>

#define ROWS 6
#define COLUMS 8

using namespace std;

void print_data(int x[][COLUMS]) {
    int row = 0,
        col = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMS; j++)
        {
            // Condición -> el elemento es negativo?
            if (x[i][j] < 0)
            {
                row = i + 1;
                col = j + 1;
                break;
            }
        }
    }
    cout << "El elemento negativo está en la fila: " << row;
    cout << " y la columna: " << col << endl;
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
            x[i][j] = rand() % 101;     // In the range 1 to 100
            cout << "x[" << i << "][" << j << "] = " << x[i][j] << endl;
            */

            cout << "Ingrese el dato x[" << i+1 << "][" << j+1 << "]" << endl;
            cin >> input;
            x[i][j] = input;
        }
    }

    print_data(x);

    return 0;
}
