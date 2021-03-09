#include <stdio.h>
#include <math.h>

//programa Newton Raphson versao recursiva

//--------funcao recursiva
float f(float x){
    float y;

    y = exp(x) + (x/2.0);
    return y;
}

//---------derivada da funcao
float derivf(float x){
    float y;

    y = exp(x) + 0.5;
    return y;
}

float NewtonRaphson(float x0, float precisao){
    float x1;

    x1 = x0 - (f(x0)/derivf(x0));
    if(fabs(x0-x1)>precisao)
        x1 = NewtonRaphson(x1, precisao);
    return x1;
}
int main(int argc, char argv[])
{
    float raiz;
    printf("raiz = %g\n", raiz);

    getchar();
    return 0;
}
