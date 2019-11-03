#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#define cap 5
int dividir(int v[],int esq,int dir){
    int i,aux,cont = esq;
    for(i = esq+1;i<=dir;i++){
        if(v[i]<v[esq]){
            cont++;
            aux = v[i];
            v[i] = v[cont];
            v[cont] = aux;
        }
    }
    aux = v[esq];
    v[esq] = v[cont];
    v[cont] = aux;
    return cont;
}
void quick(int v[],int esq,int dir){
    int pos;
    if(esq<dir){
        pos = dividir(v,esq,dir);
        quick(v,esq,pos-1);
        quick(v,pos+1,dir);
    }
}
int busca_b(int v[],int tam,int valor){
    int ini=0,fim=tam-1,meio;
    while(ini<=fim){
        meio=(ini+fim)/2;
        if(valor<v[meio]){
            fim = meio-1;
        }else if(valor>v[meio]){
                ini=meio+1;
                }else return meio;
    }
    return -1;
}
int main(void){
    setlocale(LC_ALL,"portuguese");
    int vetor[cap] ={2,5,1,6,7};
    int i;
    printf("Vetor = [");
    for(i=0;i<cap;i++)
        printf("%d ",vetor[i]);
    printf("]");
    quick(vetor,0,cap);
    printf("Vetor Ordenado= [");
    for(i=0;i<cap;i++)
        printf("%d ",vetor[i]);
    printf("]");
    int valor,b;
    printf("\n\nQual número buscará? ");
    scanf("%d",&valor);
    b = busca_b(vetor,cap,valor);
    if(b==-1)
        printf("\nValor não encontrado!\n\n");
    else
        printf("\nSe encontra no índice %d°\n\n",b);
}
