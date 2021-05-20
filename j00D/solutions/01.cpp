#include <iostream>
#include <cstdlib>

#define ROWS 7
#define COLUMS 4

using namespace std;

void print_data(int x[][COLUMS]) {
    int max_w_week = 0,         // semana con mayor promedio
        max_d_week = 0,         // Semana del mes con mayor temperatura
        max_d_day = 0;          // Día del mes con mayor temperatura
    double weekly_average = 0,  // Promedio semanal
        max_average = 0,        // El mayor promedio registrado
        max_temp = 0,           // Máxima temperatura registrada
        aux = 0,                // Alamacena de forma temporal la temperatura en cada iteración
        sum = 0;                // Suma la temperatura registrada en una semana

    for (int j = 0; j < COLUMS; j++)
    {
        for (int i = 0; i < ROWS; i++)
        {
            aux = x[i][j];
            sum += aux;
            if (max_temp < aux)
            {
                max_temp = aux;
                max_d_week = j + 1;
                max_d_day = i + 1;
            }
        }
        weekly_average = sum / ROWS;    // Calcular promedio semanal
        sum = 0;    // Resetear memoria

        cout << "Promedio de la semana " << j+1 << " = " << weekly_average << endl;

        if (max_average < weekly_average)
        {
            max_average = weekly_average;
            max_w_week = j + 1;
        }
    }

    cout << "La temperatura más alta del mes anterio es:" << max_temp << endl;
    cout << "Fue registrada el día " << max_d_day << " de la semana " << max_d_week << endl;

    cout << "El promedio semanal más alto es " << max_average << endl;
    cout << "Fue en la semana " << max_w_week << endl;
}

int main()
{
    int x[ROWS][COLUMS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMS; j++)
        {
            x[i][j] = rand() % 101;     // In the range 0 to 100
            cout << "x[" << i+1 << "][" << j+1 << "] = " << x[i][j] << endl;
        }
    }

    print_data(x);

    return 0;
}
