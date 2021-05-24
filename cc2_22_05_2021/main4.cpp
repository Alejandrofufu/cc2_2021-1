#include <iostream>
#include <cmath>
using namespace std;

int circulo(int * inicio){
    cout<<"circulo:";
    float a=(float)*inicio;
    cout<<"\nEl radio: "<<a;
    cout<<"\nEl area es: "<<(3.141592)*a*a<<"\n\n";
    return 1;
}
int cuadrado(int * inicio){
    cout<<"cuadrado:";
    float a=(float)*inicio;
    cout<<"\nEl lado: "<<a;
    cout<<"\nEl area: "<<a*a<<"\n\n";
    return 1;
}
int triangulo(int * inicio){
    cout<<"Triangulo: ";
    float a=(float)*inicio;inicio++;
    float b=(float)*inicio;inicio++;
    float c=(float)*inicio;
    cout<<"\nPrimer lado lado: "<<a;
    cout<<"\nsegundo lado: "<<b;
    cout<<"\ntercer lado: "<<c;
    float sp = (a+b+c)/2;
    cout<<"\narea: "<<sqrt(sp*(sp-a)*(sp-b)*(sp-c))<<"\n\n";
    return 3;
}

int  rectangulo(int * inicio){
    cout<<"rectangulo: ";
    float a=*inicio;inicio++;float b=*inicio;
    cout<<"\nlargo: "<<a;
    cout<<"\nancho: "<<b;
    cout<<"\nArea: "<<a*b<<"\n\n";
    return 2;
}

void calcularArea(int (*pf[])(int *)){
    int r = 7,l = 10,t1 = 4,t2 = 5, t3 = 8,largoR = 2,anchoR = 6;
    int datos[] = {r,l,t1,t2,t3,largoR,anchoR};
    int *pdatos = datos;
    cout<<sizeof(datos)/sizeof(*pdatos);
    for(int i=0,j=0;i<sizeof(datos)/sizeof(pdatos);){
        i+=(*pf)(pdatos);
        for(;j<i;j++){pdatos++;}
        pf++;
    }   
}



int main(){
    int (*pF[])(int*) = {circulo,cuadrado,triangulo,rectangulo};
    calcularArea(pF);

    return 0;
}