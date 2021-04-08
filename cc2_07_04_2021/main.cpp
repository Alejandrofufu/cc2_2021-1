#include <iostream>
using namespace std;
//punteros y arrays 
int main(){/*
    int a[5]={4,2,7,1,8};
    int * p = a;
    cout << a;// DM de a y la del 1 elemento a[0]
    cout<<"\n"<<*a;//4
    cout<<"\n"<<a[1];//2
    cout<<"\n"<<*(p+1);//2
    // a[i] = *(p+i) contenido
    // &a[i] = (p+i) direccion
    //
    //*/
    int B[2][3];
    for(int i =0,aux=2;i<2;i++){
        for(int j = 0;j<3;j++,aux+=2){
            B[i][j]=aux;
        }
    }
    //int (*ptf)[3] = B;//int *ptf = B; error
    for(int (*i)[3] =B;i<B+2;i++){
        for(int *j = *i;j<*(i+1);j++){
            cout<<*j<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n"<<*&B[1][1];// * Y & se nulan y no pasa nada 
    
    return 0;
}