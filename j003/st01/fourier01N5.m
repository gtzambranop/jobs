close all

iterations 	= 5;
period 		= 4;
amplitude 	= 1;
temporary 	= 0;                   
fourier 		= 0;
a0 			= 3/4; 

angularFrequency = (2 * pi) / period;    
xFinal = -2: 0.001 : 2;   
xOriginal = -2: 0.001 : 2;                          

for k = 1: iterations
    ak = ((2*((-1)^(k)-1))/(k*pi)^2);
    bk = (1/2)*(((3*(-1)^(k))+ 1)/(pi*k));
    
    temporary = temporary + (ak * cos(k*angularFrequency*xFinal) + bk * sin(k*angularFrequency*xFinal));
end

fourier = a0 + temporary;
funcionOriginal = (((xOriginal > -2) & (xOriginal < 0)).*(-xOriginal) + ((xOriginal > 0) & (xOriginal < 2)).*(1/2));


figure(1); clf(1)
hold on

plot(xOriginal, funcionOriginal, 'm')
plot(xFinal, fourier, 'g')

xlabel('x')
ylabel('y')
title('Fourier function with 5 iterations')
grid on
