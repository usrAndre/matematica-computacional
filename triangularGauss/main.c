#include <stdio.h>
#include <stdlib.h>

//Abaixo segue o método alternativo para o algoritmo de Gauss
//Calcula o determinante de uma matriz 2x2

int N;
float det(float a, float b, float c, float d)
{
    return (a*d)-(b*c);
}
//Faz a triangularizacao do sistema pelo metodo de Gauss
void metodoTriangDeGaussAlternativo()
{
    int i,j,k;
    for(k=0; k<(N-1); k++)
    {
        for(i=k+1; i<N; i++)
        {
            for(j=k+1; j<N; j++)
            {
                a[i][j] = det(a[k][k],a[i][k],a[k][j],a[i][j]);
                imprimeMatriz();
            }
            b[i]=det(a[k][k],a[i][k],b[k],b[i]);
            a[i][k]=0;
            imprimeMatriz();
        }
    }
}

int main()
{
//    leMatriz();
    N=3;
    a[0][0]=3;  a[0][1]=-2; a[0][2]=5;   b[0]=1111;
    a[1][0]=6;  a[1][1]=-9; a[1][2]=12;  b[1]=5111;
    a[2][0]=-5; a[2][1]=0;  a[2][2]=2;   b[2]=1111;
    metodoTriangDeGauss();
    retrosubstituicao();
    imprimeSolucao();
    getch();
    return 0;
}
