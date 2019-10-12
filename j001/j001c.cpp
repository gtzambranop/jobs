#include <iostream>

using namespace std;

int main(){
    int tamaArreglo = 0,
        contador    = 0,
        mayor       = 0,
        i           = 0;

    tamaArreglo = 50;

    int numeros[tamaArreglo];

    for(i = 0; i < tamaArreglo; i++){
        cout << "Digite el valor " << i+1 <<": ";
        cin >> numeros[i];

        if(numeros[i] > mayor){
            mayor = numeros[i];
        }
    }

    for(i = 0; i < tamaArreglo; i++){
        if(mayor == numeros[i]){
            contador ++;            
        }
    }
    
    cout << "\n\nEl mayor numero del arreglo es: "<< mayor << "\n";
    if(contador == 1){
        cout << "El numero " << mayor << " se repite una vez en todo el arreglo " << endl;
    }else{
        cout << "El numero " << mayor << " se repite " << contador << " veces en todo el arreglo.\n"<< endl;
    }

    cout << "\n\t\tARREGLO INGRESADO\n";
    for(i = 0; i < tamaArreglo; i++){
        cout << numeros[i] <<"\t";
    }

    cout << "\n\n";

    return 0;
}
