
/*-------------------------------------------------------------------------
    Programa Integral
    Calcula integral definida entre dois pontos
    usando o metodo dos Trapezios
---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* funcao a ser integrada */
/* ATENCAO: re-escrever para outras funcoes se for o caso */
float f(float x)
{
    float y;

    y = 2 + 2*x - (x*x);

    return y;
}

/* faz a soma das areas */
float SomaAreas(float a, float b, float dx)
{
    float x, s;

    for (x=a+(dx/2), s=0.0; x<b; x+=dx)
        s+= f(x)*dx;
    return s;
}

float Integral(float a, float b, float precisao)
{
    float dx, s0, s1;

    dx = (b-a)/10;
    s0 = 0;
    do{
        printf("integrando: %f passos, dx=%f\n", (b-a)/dx, dx);
        s1 = s0;
        s0 = SomaAreas(a, b, dx);
        dx /= 2;
    }
    while (abs(s1-s0) > precisao);
    return s0;
}

int main()
{
    float a, b, m;

    printf("Digite os limites de integracao: \n\n");
    printf("a= ");
    scanf("%f", &a);
    printf("b= ");
    scanf("%f", &b);
    if (a>b){
            m=a;
            a=b;
            b=m;
    }
    printf("\nResultado: %g\n\n", Integral(a,b,0.0001));
    //getchar();
    return 0;
}
