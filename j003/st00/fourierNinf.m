close all
clear; 
clc;

cantidadDeIteraciones = 10000;
puntosEnIntervalo = linspace(-2, 2, 1000);
%definicion de las variables a usar
T = 4;                                 %periodo
w = (2 * pi) / T;                      %frecuencia angular
A = 1;                                 %amplitud
funcionAuxiliar = 0;                   
funcionFinal = 0;
a0 = 3/4;                                 

for k = 1: cantidadDeIteraciones       %sumatoria
    ak = ((2*((-1)^(k)-1))/(k*pi)^2);
    bk = (1/2)*(((3*(-1)^(k))+ 1)/(pi*k));
    
    %almacena la sumatoria sin el a0
    funcionAuxiliar = funcionAuxiliar + (ak * cos(k*w*puntosEnIntervalo) + bk * sin(k*w*puntosEnIntervalo));
end

funcionFinal = a0 + funcionAuxiliar;

x = linspace(-2, 2, 1000);              %cantidad de puntos en el intervalo -2, 2

funcionOriginal = (((x > -2) & (x < 0)).*(-x) + ((x > 0) & (x < 2)).*(1/2));


figure(1); clf(1)
hold on
plot(x, funcionOriginal, 'r')
plot(puntosEnIntervalo, funcionFinal, 'b')
xlabel('eje X')
ylabel('eje Y')
title('Funcion Fourier para un n = infinito')
grid on
