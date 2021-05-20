#include <iostream>
#include <cstdlib>

#define ROWS 5
#define COLUMS 5

using namespace std;

void print_data(int x[][COLUMS])
{
    int count_negative = 0,          // Contar la cantidad de valores negativos de la matriz
        count_zero = 0;              // Contar la cantidad de elementos en diagonal con valor cero
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMS; j++)
        {
            // Condición -> El elemento es negativo?
            if(x[i][j] < 0)
            {
                count_negative ++;
            }

            // Primera condición -> es una diagonal?
            // Segunda condición -> El valor de ese elemento es cero?
            if((i == j) && (x[i][j] == 0))
            {
                count_zero ++;
            }
        }
    }
    cout << "La cantidad de elementos negativos es: " << count_negative << endl;
    cout << "La cantidad de elementos en la diagonal con valor cero es de: " << count_zero << endl;
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
    print_data(x);

    return 0;
}
