#include <iostream>
using namespace std;
//listas enlazadas

struct Nodo
{
    int data ;
    Nodo *next;
    Nodo(){
        data = NULL;
        next = NULL;
    }
    Nodo(int d){
        data = d;
        next = NULL;
    }
    ~Nodo();
};

struct Lista{
    Nodo* head;
    Nodo* end;
};



int main(){


    return 0;
}