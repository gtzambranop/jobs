close all

n 	= 5;
periodo 	= 4;
amplitud 	= 1;
tempSum 	= 0; 		%amacenara la sumatoria de la serie                   
f 		= 0;		% funcion de fourier
a0 	= 3/4; 	
i     = 0;		%para iterar la sumatoria

w = (2 * pi) / periodo;  

%intervalos de las variables de la funcion original y de fourier  
xa = -2: 0.005 : 2;   
xb = -2: 0.005 : 2;                          

%definicion de la funcion original
fOri = (((xb > -2) & (xb < 0)).*(-xb) + ((xb > 0) & (xb < 2)).*(1/2));

i = n;

for i = 1: n
  
	 % constantes
    ak = ((2*((-1)^(i)-1))/(i*pi)^2);
    bk = (1/2)*(((3*(-1)^(i))+ 1)/(pi*i));
    
    %sumatoria de fourier
    tempSum = tempSum + (ak * cos(i*w*xa) + bk * sin(i*w*xa));
    i = i -1;
end

%funcion final
f = a0 + tempSum;


figure(1); clf(1)
hold on %permite la graficacion de multiples funciones a la vez

set(gcf,'Color',[0.4,0.4,0.4, 0.4])
subplot(2,1, 1),plot(xb, fOri, 'k'), title('funcion Original'), xlabel('eje x'),ylabel('eje y'), box off, grid;
subplot(2,1, 2),plot(xa, f, 'm'), title('funcion fourier con n = 5'), xlabel('eje x'), ylabel('eje y'), box off, grid;

