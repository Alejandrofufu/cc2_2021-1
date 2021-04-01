#include <iostream>
using namespace std;


int main(){
    /*//3
    int x = 5;
    int *p = &x; //puntero apunta a direccion de x

    p = 0;
    p = nullptr; // maneras de poner nulo al putero
    //p = 1; // errro de tipo 

    //4
    int  x = 10;
    char y = 'F';
    int *a = &x; // puntero apunta a direccion de x 
    char * b = &y; // puntero apunta a direccion de y
    void *c;
    c = b;
    cout<<(*c)<<"\n";/// (int * (c) )
    int &z; // error
    //5

    const double &a {1};
    double & b {1};
    cout<<b << "\n";

    //6
    int x = 5;
    int *p1 = &x;
    int **p2 = &p1;
    int ***p3 = &p2;
    cout<< **p2;
    //14
*/
    float vector[] = {4.1,5.3,6.2};; 
    float * p = vector;

    float *q = &(*p);
    cout<<"\n"<<*q++;
    cout<<"\n"<<*q++;
    cout<<"\n"<<*q++;



    return 0 ;
}