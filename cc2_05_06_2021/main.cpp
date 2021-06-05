#include <iostream>
using namespace std;
//matris dinamica 2D con punteros 
int main(){
    int f = 4;
    int c = 5;
    int cm = 2;
    int **p = new int*[f];
    for(int **i=p;i<p+f;i++){
        *i = new int [c];
    }
    int aux = 1;
    for(int **i =p;i<p+f;i++){
        for(int *j=*i;j<*i+c;j++,aux+=1){
            *j = aux;
            cout<<*j<<"\t";
        }
        cout<<"\n";
    }

    for(int **i=p;i<p+f;i++){
        delete[] *i;
    }
    delete[] p;

    //matris dinamica 3D con punteros
    int ***m = new int** [cm];
    for( int ***i = m;i<m+cm;i++){
        *i = new int *[f];
        for(int **j = *i;j<*i+f;j++){
            *j = new int [c];
        }
    }
    cout<<"\n\nmatris3D: \n";
    aux = 2;
    for(int ***i = m;i<m+cm;i++){
        for(int **j = *i;j<*i+f;j++){
            for(int *k = *j; k<*j+c;k++,aux+=3){
                *k = aux;
            }
        }
    }
     for(int ***i = m;i<m+cm;i++){
        for(int **j = *i;j<*i+f;j++){
            for(int *k = *j; k<*j+c;k++){
                cout<<*k<<"\t";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

     for( int ***i = m;i<m+cm;i++){
        for(int **j = *i;j<*i+f;j++){
            delete[] *j ;
        }
        delete[] *i;
    }
    delete[] m;



    
    return 0;
}