#include <iostream>
#include <string.h>
using namespace std;
//05/05/2021

int main(){
    char c[10];
    c[0] = 'c';
    c[1] = '+';
    c[2] = '+';
    c[3] = '\0';
    // char c[10] = "c++"; correto
    //no se puede c = "c++";
    int lent = strlen(c);
    char *ptrSize = c ;
    int cont = 0;
    for(;*ptrSize;ptrSize++){
        cont++;
    }
    char tac[10] = "asdsad";
    cout<< c<<"\n";
    cout<< lent<<"\n";// tamaño 
    cout<<cont<<"\n";// tamaño 
    cout<< sizeof(c)<<"\n";

    return 0;//ctr +l para limpiar el terminal
}