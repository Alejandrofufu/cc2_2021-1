#include <iostream>
using namespace std;

void imprimir(int (*a)[3]){
    cout<<&a<<endl;// direccion de a
    cout<<a<<endl;// int * 
    cout<<a+1<<endl;
    cout<<*a<<endl;
}

int main(){
    int a[2][3]= {{1,2,3},{4,5,6}};

    cout<<&a;//int **
    cout<<a; // int **
    cout<<*a; // int * 
    cout<<**a ; // int 
    imprimir(a);

    return 0;
}
