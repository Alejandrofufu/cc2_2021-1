#include <iostream>
using namespace std;

int main(){
    int c[3][2][2];//digamos que empieza en la direccion de memoria 800
    int (*p)[2][2]=c;// *p es una coleccion de matrices
                    // de [2][2]
    cout<<c[0]<<endl;
    cout<<*(c[0][1]+1); 
    cout<<*(c[1]+1);
    return 0;
}