#include <iostream>

using namespace std;

int main(){
    int tamaArreglo = 0,
        positivos   = 0,
        negativos   = 0,
        impares     = 0,
        pares       = 0,
        nulos       = 0,
        i           = 0;

    tamaArreglo = 30;

    int numeros[tamaArreglo];

    for(i = 0; i < tamaArreglo; i++){
        cout << "Digite el valor " << i + 1 <<": ";
        cin >> numeros[i];
        
        if(numeros[i] > 0){
            positivos ++;
        }else if(numeros[i] < 0){
            negativos ++;
        }

        if((numeros[i] % 2) == 0){
            pares ++;
        }
    }
    
    nulos = tamaArreglo - (positivos + negativos);
    impares = tamaArreglo - pares;

    cout << "\n\nLa cantidad de numeros positivos del arreglo son: " << positivos <<endl;
    cout << "La cantidad de numeros negativos del arreglo son: " << negativos <<endl;
    cout << "La cantidad de numeros nulos del arreglo son: " << nulos <<endl;
    cout << "La cantidad de numeros pares del arreglo son: " << pares <<endl;
    cout << "La cantidad de numeros impares del arreglo son: " << impares <<endl;
    
    cout << "\n\t\tARREGLO INGRESADO\n";
    for(i = 0; i < tamaArreglo; i++){
        cout << numeros[i] << "\t";
    }
    cout << "\n\n";    

    return 0;
}
