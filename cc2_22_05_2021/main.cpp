#include <iostream>
using namespace std;
//repaso puntero a funcion
int sumar(int a, int b){
    return a+b;
}
int resta(int a, int b){
    return a-b;
}
int main(){
    int c;
    int (*p)(int,int);
    p = sumar;
    c = (*p)(4,5);
    cout<<c<<"\n";
    p = resta;
    c = (*p)(6,5);//equivalente a &resta
    cout<<c<<"\n";

    return 0;
}