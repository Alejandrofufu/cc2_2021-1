#include <iostream>
using namespace std;

class Operacion
{
    public:
    int suma(int a,int b){
        return a+b;
    }
    int multiplicacion(int a,int b){
        return a*b;
    }
    int pf(int a ,int b){
        cout<<"Metodo pf dentro de la case Operacion\n";
        return 0;
    }
    static int inverso (int a){
        return -a;
    } 
};

int calcular (int j,int k,Operacion* op,int (Operacion::*pf)(int,int)){
    //(*op).pf(j,k); // llamando al metodo pf de la clase
    return ((*op).*pf)(j,k);// el contenido del puntero pf que apunta a una intancia de Operacion
}
int calcular2 (int j,int k,Operacion* op,int (Operacion::*pf)(int,int)){
    return (op->*pf)(j,k);
}

typedef int (Operacion:: *tdf)(int, int );
int calcular3(int j,int k, Operacion* op, tdf pf){
    return (op->*pf)(j,k);
}

int calcular4(int j, int(*pf)(int)){// cuando es estatico 
    return pf(j);
}
int main(){
    Operacion op;
    //int (*pf)(int,int) = suma; en clase no es correcto
    //int (Operacion::*pf)(int ,int ) = &Operacion::suma;
    //int c = calcular(5,3,&op,Operacion::suma);  // normal 
    int c = calcular4(5,&Operacion:: inverso);
    cout<<c<<"\n";

    return 0;
}
