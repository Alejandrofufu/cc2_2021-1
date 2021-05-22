#include <iostream>
using namespace std;

void imprimir(){
    cout<<"Imprimir\n";
}
int *anadir(int *a,int *b){
    int c = (*a) + (*b);
    return &c;
}

int main(){
    int a = 3;
    int b = 4;
    int*c = anadir(&a,&b);
    //imprimir();
    cout<<*c <<"\n";
    return 0;
}