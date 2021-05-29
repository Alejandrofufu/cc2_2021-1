#include <iostream>
using namespace std;
// reserva de memoria en 2D
int main (){
    int f = 4;
    int c = 5;
    //forma 1 
    int * A = new int [f*c];
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            *(A+i*c+j) = 10;
        }
    }
    delete[] A;

    int **p = new int*[10];
    for(int i=0;i<10;i++){
        p[i] = new int [5];
    }

    for(int i= 0;i<10;i++){
        delete[] p[i];
    }
    delete[] p;
    // reserva de memoria matris 3D
    cout<<"\n\n\n";
    int x=2,y=3,z=4,aux=1;

    int *a = new int [x*y*z];
    int *pt = a;
    for(int i=0;i<x;i++){
        for(int j = 0;j<y;j++){
            for(int k = 0;k<z;k++,aux+=1){
                *(a+i*(y*z)+(j*z)+k) = aux;
                cout<<*pt<<"\t";pt++;
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    delete[] a;
    return 0;
}