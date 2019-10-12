#include <iostream>

#define DIASPORMES 28
#define MESES 6
#define DIAS 7

using namespace std;

void temperaturasSemestre(float temperatura[][DIAS]);
void promedioSemana(float temperatura[][DIAS]);
void promedioMensual(float temperatura[][DIAS]);


void temperaturasSemestre(float temperatura[][DIAS]){
    int semanaTempBaja  = 0,
        semanaTempAlta  = 0,
        totalSemanas    = 0,
        diaTempBaja     = 0,
        diaTempAlta     = 0,
        i               = 0,
        j               = 0;

    float   temperaturaBaja = 0,
            temperaturaAlta = 0,
            tempDia         = 0;

    totalSemanas = MESES * 4;

    for(i = 0; i < totalSemanas; i++){
        for(j = 0; j < DIAS; j++){
            tempDia = temperatura[i][j];
            if(tempDia > temperaturaAlta){
                temperaturaAlta = tempDia;
                semanaTempAlta = i;
                diaTempAlta = j;
            }
            if(tempDia < temperaturaBaja){
                temperaturaBaja = tempDia;
                semanaTempBaja  = i;
                diaTempBaja = j;
            }
        }        
    }

    cout << "La temperatura mas alta fue el dia " << diaTempAlta << " de la semana: " << semanaTempAlta <<endl;
    cout << "La temperatura mas baja fue el dia " << diaTempBaja << " de la semana: " << semanaTempBaja <<endl;
}

void promedioSemana(float temperatura[][DIAS]){
    int semanaTempAlta  = 0,
        totalSemanas    = 0,
        i               = 0,
        j               = 0;

    float   promedioSemana  = 0,
            sumaTempSemana  = 0,
            promedioAlto    = 0;
    
    totalSemanas = MESES * 4;

    for(i = 0; i < totalSemanas; ){
        promedioSemana = 0;
        sumaTempSemana = 0;
        for(j = 0; i < DIAS){
            sumaTempSemana = SumaTempSemana + temperatura[i][j];
        }

        promedioSemana = sumaTempSemana / DIAS;

        if(promedioSemana > promedioAlto){
            promedioAlto = promedioSemana;
            semanaTempAlta = i;
        }
    }
    
    cout << "La semana que tuvo el promedio mas alto fue la: " << semanaTempAlta << endl;

}

void promedioMensual(float temperatura[][DIAS]){
    int totalSemanas    = 0,
        i               = 0,
        j               = 0;

    float   promedioSemana  = 0,
            sumaTempSemana  = 0;
    
    totalSemanas = MESES * 4;

    for(i = 0; i < totalSemanas; ){
        promedioSemana = 0;
        promedioSemana = sumaTempSemana / DIAS;

        cout << "El promedio de la temperatura de la semana " << i << " fue de: " << promedioSemana << endl;
    }
}

int main(){
    int semanaActual    = 0,
        totalSemanas    = 0,
        diasMes         = 0,
        i               = 0,
        j               = 0,
        k               = 0;
    
    totalSemanas =  MESES * 4;

    float temperatura[totalSemanas][DIAS];
    
    for(i = 0; i < MESES; i++){
        diasMes = DIASPORMES;
        for(j = 0; j < diasMes; j++, k++){
            if(k == DIAS){
                k = 0;
                semanaActual = semanaActual + 1;
            }
            cout << "Ingrese la temperatura del dia " << j + 1 << " del mes " << i + 1 << endl;    
            cout << "semana: "<<semanaActual<<" dia: " << k <<endl;
            cin >> temperatura[semanaActual][k]; 
        }
    }

}

