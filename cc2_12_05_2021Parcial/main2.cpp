#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void numRand(int *arr,int size){
    for(int i =0;i<size;i++){
        *arr = rand()%2;arr++;
    }
}
void imprimir(int *arr,int sizeI,int sizeJ){
    for(int i = 0;i<sizeI;i++){
        for(int j =0;j<sizeJ;j++){
            cout<<*arr<<"\t";arr++;
        }
        cout<<"\n";
    }
}

void reducir (int *I,int*K,int dimI1,int dimI2,int dimK1,int dimK2){
    int ci = dimI1+1-dimI2,cj = dimK1+1-dimK2;
    int *inicio1 =I,*inicio2 =I,*inicio3=I,*inicio4 =I,*inicioB = K,aux=0;
    cout <<"\nci: "<<ci; cout <<"\ncj: "<<cj;cout<<"\n";
    for(int i= 0;i<ci;i++){
        for(int j = 0;j<cj;j++){
            for(int filas =0;filas<dimI2;filas++){
                for(int columnas = 0;columnas <dimK2;columnas++){
                    aux += (*inicio4)* (*inicioB);
                    inicio4++;inicioB++;
                }
                for(int i=0;i<dimK1;i++){inicio3++;}
                inicio4 = inicio3;
            }
            cout<<aux<<"\t";aux = 0;inicioB = K;
            inicio2++;inicio4 = inicio2;inicio3 = inicio2;
        }
        cout<<"\n";
        for(int i=0;i<dimK1;i++){inicio1++;}
        inicio2 = inicio1;inicio3 = inicio1;inicio4 = inicio1;
    }
} 
int main(){
    int ai = 7,aj=7,bi=3,bj=3;/*
    cout <<" escriba el tamaño de filas de la matris A: ";
    cin >>ai;
    cout<<"escriba el tamaño de columnas de la matris A";
    cin >>aj;*/
    //srand(time(NULL));
    //int *matrisA = new int [ai*aj];
    //numRand(matrisA,ai*aj);
    int matrisA[49]={
        0,1,1,1,0,0,0,
        0,0,1,1,1,0,0,
        0,0,0,1,1,1,0,
        0,0,0,1,1,0,0,
        0,0,1,1,0,0,0,
        0,1,1,0,0,0,0,
        1,1,0,0,0,0,0
    };
    imprimir(matrisA,ai,aj);cout<<"\n";/*
    cout <<" escriba el tamaño de filas de la matris B: ";
    cin >>bi;
    cout<<"escriba el tamaño de columnas de la matris B";
    cin >>bj;*/
    //int *matrisB = new int [bi*bj];
    //numRand(matrisB,bi*bj);
    int matrisB[9] = {
        1,0,1,0,1,0,1,0,1
    };
    imprimir(matrisB,bi,bj);
    cout<<"\nMatris C: \n";
    reducir(matrisA,matrisB,ai,bi,aj,bj);
    //delete[] matrisA;
    //delete[] matrisB;   

    return 0;
}