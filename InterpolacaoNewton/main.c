#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 int menu(void);
 void lagrange(void);
 void newton(void);

 int retornaIndiceInicial(int numPtos,int grau,float pto,float *x,float *y);
 float retornaDiferencaDividida(int k, float pto,float *x,float *y );

 main(){
	 int opc,i,j;
	 /*do{ opc = menu();
		 switch(opc){
			 case 1: printf("\nFORMA DE LAGRANGE:\n\n");
				 lagrange();
				 break;
			 case 2: printf("\nFORMA DE NEWTON:\n\n");
				 newton();
				 break;
			 case 3: printf("Encerrando o programa.\n\n");
				 break;
				 default: printf("Opcao invalida.\n<Enter>" );
		 		fflush(stdin);
		 		getchar();
				break;
			 }*/
		float mod(float a){
			 float x;
			 x= a*a;
			 x=sqrt(x);
			 return x;
		 }
	/*void lagrange(void){
		 int n,i,j;
		 float *x,*f,xbarra,P,Pn,d,t,h;
		 printf("Entre com n: ");
		 scanf("%d",&n);
		 if(x!=NULL) free(x);
		 x = (float*)malloc(n*sizeof(float));
		 if(x==NULL) printf("Erro em alocacao (Definicoes).\n\n" );
		 if(f!=NULL) free(f);
		 f = (float*)malloc(n*sizeof(float));
		 if(f==NULL) printf("Erro em alocacao (Definicoes).\n\n" );
		 for(i=0;i<n;i++){ printf("Entre com xbarra: ");
		 scanf("%f",&xbarra);
	}*/
	}
	void newton(void){
		 int i,k,t,numPtos,teste,grau;
		 float p,h,u,r,m,termo,pto,*x,*y;
		 printf("Entre com o grau do polinomio: ");
		 scanf("%d",&grau);
		 printf("Entre com n: ");
		 scanf("%d",&numPtos);
		 if(x!=NULL)
            free(x);
		 x = (float*)malloc(numPtos*sizeof(float));
		 if(x==NULL)
            printf("Erro em alocacao (Definicoes).\n\n" );
		 if(y!=NULL)
            free(y);
		 y = (float*)malloc(numPtos*sizeof(float));
		 if(y==NULL)
            printf("Erro em alocacao (Definicoes).\n\n" );
		 for(i=0;i<numPtos;i++){
		    printf("Entre com o ponto: ");
            scanf("%f",&pto);
            k = retornaIndiceInicial(numPtos,grau, pto, x, y );
            termo = 1;
            p = y[k];
            if(numPtos>=grau){
                teste = numPtos;
            }
            else{
                teste=k+1;
            }
            r= retornaDiferencaDividida( k, pto, x, y );
		//printf("termo=%f e r=%f\n",termo,r);
            m=termo * r;
            p = p + m;
		 //}
            printf("O valor do polinomio no ponto dado e: %.2f", p);
                int retornaIndiceInicial(int numPtos,int grau,float pto,float *x,float *y){
                    int i;
                }
            }

            float retornaDiferencaDividida(int k, float pto,float *x,float *y ){
                float d,d1,d2,d3,s,s1;
                if (k!=0){
                    d=x[k] - pto;
                    d1= x[k] - x[k-1];
                    d2= pto - x[k-1];
                    d3= x[k] - x[k-1];
                    s=y[k-1]*(d/d1);
                    s1=y[k]*(d2/d3);
                    s=s+s1;
                    return s;
                }
        return y[k];
    }
}
