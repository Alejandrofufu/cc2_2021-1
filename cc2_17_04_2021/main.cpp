#include <iostream>
using namespace std;
//seguimos con teoria, y punteros con argumetno en funcion

void Incremento(int *p){
    *p = (*p)+1;
}
int suma(int a[]){// a[] en realidad es int *a; entonces
    int i,s=0;
    int size = sizeof(a)/sizeof(a[0]);// a al ser puntero, sizeof(a) = 4 bits, sizeof(*(a)) es 4 entonces 4/4 = 1 ;
    for(i =0;i<size;i++)// no se puede calcular eso con punteros
        s+=a[i];
    return s;
}
int suma2(int a[],int size){
    int i,s = 0;
    for(i=0;i<size;i++)
        s+=a[i];
    return s;
}
int main(){
    int data[2][3];
    int (*apr)[3] = data;
    for(int i =0 ;i<2;i++){
    // que es q = (*apr + 3*i) es int 
    }
    //que es d= *(*(data[i]+j)+k);  es int
    // que es d = *(data[i][j]+k) ; es int
// punteros como argumento de funcion    
    int a = 10 ;
    Incremento(&a);
    cout<<a<<endl;

    int b[]={1,2,3,4,5};
    int c;
    c = suma(b);// no funca ;V
    c = suma2(b,5);// si funca 

// 2D
    int m1[3][5];
    //void print:mij(int m[][],int dint,int dint2){... m[i][j]--> *(*(m+i)+j)     ...}
    // da error el copilaro no permite m[][] pide un vaor como minimo
    
    return 0;
}

