#include <iostream>
using namespace std;
//punteros a clases
class Clase{
public:
    int x;
    int y;
    Clase(int,int);
    void imprimir();
};

Clase::Clase(int a,int b){
    x=a;y=b;
}

void Clase::imprimir(){
    cout<<x<<endl;
}

int main(){
    Clase uno(6,10);
    Clase *dos = new Clase(88,89);
    dos->x = 100; // acceso a un atributo por punteros
    (*dos).x = 100; // lo mismo de arriba, son equivalentes
    (*dos).imprimir();
    dos->imprimir();

    delete dos;
    dos = & uno;// puntero p a punta a uno 
    dos->y=50; //----------------------
    // puntero a un mienbro dato entero 
    int Clase::*p;
    p = & Clase::y; // puntero p apunta a x
    cout << dos->*p<<endl;
    cout << uno.*p;
    //puntero a metodo
    void (Clase::*pn)();// puntero a metodo
    pn = & Clase::imprimir(); ////// error
    ((*dos).*pn)();
    (dos->*pn)();

    
    return 0;
}