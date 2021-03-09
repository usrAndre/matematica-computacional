#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double y(double x)  //a solucao y(t) da equacao
{
    return (1.0/4.0)*x-(3.0/16.0)+(19.0/16.0)*exp(4.0*x);
}

double f(double x,double y) //a funcao f(x,y)
{
    return 1-x+4*y;
}

void main(void)
{
    double xn,xn1,xmax; //variaveis xn e xn+1
    double yn, yn1; //variaveis yn e yn+1
    double y0,x0; //valores iniciais de y e x
    double h; //passo
    int n;

    x0 = 0.0;
    y0 = 1.0;
    xmax = 2.0;
    h = 0.01;
    xn = x0;
    yn = y0;
    n =0;

    while(xn<xmax)
    {
        printf(" %i %f %f %f \n ", n,xn,yn,y(xn)); //escreve os valores das variaveis
        yn1 = yn + h*f(xn,yn);
        xn1 = xn + h;
        n++; //incrementa n
        yn = yn1; //atribui yn1 a yn pra ser reutilizado
        xn = xn1; //atribui o xn1 a xn pra ser reutilizado
    }//fim while
    return 0;
}
