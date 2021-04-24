#include <iostream>
using namespace std;
// punteros a funciones 


void imprimir(int *p){
    for(int i =0;i<5;i++){
        cout<<*(p+1)<<endl;
    }
}

int main(){
    int a[5]={10,20,30,40,50};
    int *p = a;
    cout<<&a[0];
    cout<<&a;
    cout<<*a;
    cout<<*a+1;


    imprimir(p);
    return 0;
}