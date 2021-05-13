#include <iostream>
using namespace std;
//1. punteros a memoria dinamica
//1.1 punteris a funcion

int aumentar (int a){
    return a++;
} 

void A(){
    cout<< "A\n";
}
void B( void (*p)()){
    p();
}

void BubbleSort(int A[],int n){
    int i,j,temp;
    for(i= 0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(A[j]<A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}
int compararMayor(int a , int b){
    if(a>b)
        return 1;
    else
        return -1;
}
int compararMenor(int a,int b){
    if(a<b)
        return 1;
    else 
        return -1;
}
void BubbleSort2(int A[],int n, int (*pComp)(int,int)){
    int i,j,temp;
    for(i= 0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(pComp(A[j],A[j+1])>0){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(){
    int c;
    int (*p)(int);
    p = &aumentar;
    c=(*p)(4); // 5  
    //////////////////////
    void (*pt)() = A;
    B(pt);
    //////////////////////////////
    int A[] = {3,2,1,5,6,4};
    BubbleSort(A,6);
    for(int i=0;i<6;i++){cout<<"\t"<<A[i];}cout<<"\n";
    
    /////////////////////////////////////////
    BubbleSort2(A,6,compararMayor);
    for(int i=0;i<6;i++){cout<<"\t"<<A[i];}cout<<"\n";
    ///////////////////////////////////////////
    BubbleSort2(A,6,compararMenor);
    for(int i=0;i<6;i++){cout<<"\t"<<A[i];}cout<<"\n";
    return 0;
}