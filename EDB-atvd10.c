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
int main(void){
    int v[cap] = {2,6,4,9,0};
    int i;
    printf("Vetor = [");
    for(i=0;i<cap;i++)
        printf("%d ",v[i]);
    printf("]");
    quick(v,0,cap);
    printf("\n\nVetor Ordenado= [");
    for(i=0;i<cap;i++)
        printf("%d ",v[i]);
    printf("]");
}
