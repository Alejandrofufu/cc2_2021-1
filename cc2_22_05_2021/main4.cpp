#include <iostream>
#include <cmath>
using namespace std;

float circulo(){
    float a=0;
    cout<<"escribir el radio: ";cin>>a;
    return (3.141592)*a*a;
}
float cuadrado(){
    float a=0;
    cout<<"ingrese el lado: ";cin>>a;
    return a*a;
}
float triangulo(){
    float a=0,b=0,c=0;
    cout<<"ingrese un lado: ";cin>>a;
    cout<<"ingrese un segundo lado: ";cin>>b;
    cout<<"inglrese un tercer lado: ";cin>>c;
    float sp = (a+b+c)/2;
    return sqrt(sp*(sp-a)*(sp-b)*(sp-c));
}
float rectangulo(){
    float a=0,b=0;
    cout<<"ingrese largo: ";cin>>a;
    cout<<"ingrese ancho: ";cin>>b;
    return a*b;
}
void calcularArea(float (*pf)()){
    cout<<"el area es : "<<pf();
}

int main(){

    calcularArea(&triangulo);
    return 0;
}