#include <iostream>
using namespace std;
int suma(int a,int b){
    return a+b;
}
int resta(int a,int b){
    return a-b;
}
typedef int (*PF)(int,int);

int main(){

    PF PunteFuncion[2] = {suma,resta};
    return 0 ;
}