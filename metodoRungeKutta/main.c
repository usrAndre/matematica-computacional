#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Programa RK faz a integracao de uma equacao diferencial ordinaria
//atraves do metodo de Runge-Kutta de 4a ordem

//ODE a ser integrada
//ATENCAO: re-escrever para outras funcoes de for o caso

float f(float x, float y)
{
    float dy;
    dy=(2*x)-2;
    return dy;
}
//metodo de Runge-Kutta de 4a Ordem
float passoRK(float x0, float y0, float x1)
{
    float h, k1, k2, k3, k4, y1;
    h=x1-x0;
    k1=h*f(x0,y0);
    k2=h*f(x0+h/2, y0+k1/2);
    k3=h*f(x0+h/2, y0+k2/2);
    k4=h*f(x0+h, y0+k3);
    y1=y0+(k1/6)+(k2/3)+(k3/3)+(k4/6);
    return y1;
}

float RK(float x0, float y0, float x1, float precisao)
{
    float xm, ym, y1, yt;
    xm=(x1+x0)/2;
    //tentar o passo completo
    yt = passoRK(x0, y0, x1);
    ym = passoRK(x0, y0, xm);
    y1 = passoRK(xm, ym, x1);

    if(abs(yt-y1)>precisao){
        //faltou precisao: dividir em dois passos e chamar RK recursivamente
        ym = RK(x0, y0, xm, precisao);
        y1 = RK(xm, ym, x1, precisao);
    }
    printf("RK: x=%g y=%g\n, x1, y1");
    return y1;
}

float ODE_RK(float x0, float y0, float x1, float precisao)
{
    float h, x, y, xm, ym;
    h = (x1-x0)/10;
    x = x0;
    y = y0;
    do{
        xm = x + h;
        if(xm > x1) xm= x1;
        ym = RK(x, y, xm, precisao);
        x = xm;
        y = ym;
    } while (x<x1);
    return ym;
}

int main()
{
    float x0, y0, x1, y1;
    float precisao = 0.0001;

    printf("\nValor inicial:\n\n");
    printf("x0= "); scanf("%f", &x0);
    printf("y0= "); scanf("%f", &y0);
    printf("\nPonto final:\n\n");
    printf("x1= "); scanf("%f", &x1);

    y1 = ODE_RK(x0, y0, x1, precisao);

    printf("\nResultado: %g\n\n", y1);
    getchar();
}

