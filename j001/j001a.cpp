#include <iostream>

using namespace std;

int main(){
    int calificacionSuperior    = 0,
        numeroReprobados        = 0,
        numeroAprobados         = 0,
        tamaArreglo             = 0,
        i                       = 0;
    
    float porcentajeReprobados  = 0,
          porcentajeAprobados   = 0,
          sumaCalificaciones    = 0,
          notaDeAprobacion      = 0,
          notaExcelencia        = 0,
          promedio              = 0;

    notaDeAprobacion    = 3.0;
    notaExcelencia      = 4.0; 
    tamaArreglo         = 11;

    float calificaciones[tamaArreglo];

    for(i = 0; i < tamaArreglo; i++){
        cout << "Digite la nota del alumno "<< i + 1 <<": ";
        cin >> calificaciones[i];

        sumaCalificaciones += calificaciones[i];

        if(calificaciones[i] >= notaDeAprobacion){
            numeroAprobados ++;
            if(calificaciones[i] > notaExcelencia){
                calificacionSuperior ++;
            }
        }
    }
   
    promedio = sumaCalificaciones / tamaArreglo;
    numeroReprobados = tamaArreglo - numeroAprobados;
    porcentajeAprobados = (numeroAprobados * 100) / tamaArreglo;
    porcentajeReprobados = 100 - porcentajeAprobados;
     
    cout << "\nEl promedio del grupo es de: "<< promedio <<endl;
    cout << "El numero de alumnos aprobados es: " << numeroAprobados <<endl;
    cout << "El numero de alumnos reprobados es: " << numeroReprobados <<endl;
    cout << "El porcentaje de alumnos aprobados es del: " << porcentajeAprobados << "%" << endl;
    cout << "El porcentaje de alumnos reprobados es del: " << porcentajeReprobados << "%" << endl;
    cout << "Los alumnos que tienen una nota superior a "<< notaExcelencia << " son: "<< calificacionSuperior << endl;
    
    cout << "\n\t\t CALIFICACIONES INGRESADAS\n" << endl;

    for(i = 0; i < tamaArreglo; i++){
        cout << calificaciones[i] << "\t";
    }
    cout << "\n\n";

    return 0;
}
