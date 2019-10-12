close all
clear; 
clc;

n 	= 10;
T 	= 4;
A 	= 1;
aux 	= 0; 		%amacenara la sumatoria de la serie                   
f 		= 0;		% funcion de fourier
a0 	= 3/4; 	
i     = 0;		%para iterar la sumatoria

w = (2 * pi) / T;  

%intervalos de las variables de la funcion original y de fourier  
x1 = -2: 0.005 : 2;   
x2 = -2: 0.005 : 2;                          

%definicion de la funcion original
f2 = (((x2 > -2) & (x2 < 0)).*(-x2) + ((x2 > 0) & (x2 < 2)).*(1/2));

i = n;

while i > 0
	 % creación de las constantes de la serie
    ak = ((2*((-1)^(i)-1))/(i*pi)^2);
    bk = (1/2)*(((3*(-1)^(i))+ 1)/(pi*i));
    
    %sumatoria
    aux = aux + (ak * cos(i*w*x1) + bk * sin(i*w*x1));
    i = i -1;
end

%creacion de la funcion final
f = a0 + aux;


figure(1); clf(1)
hold on %permite la graficacion de multiples funciones a la vez

subplot(2,1, 1),plot(x2, f2, 'b'), title('grafico Original'), xlabel('eje x'),ylabel('eje y'), grid;
subplot(2,1, 2),plot(x1, f, 'm'), title('grafico de f n = 10'), xlabel('eje x'), ylabel('eje y'), grid;

