#include <iostream>
using namespace std;

int main (){
    //despues de la clase pasada seguimos con ejercicios de b[2][3]
    // b en la posicion 400 cuanto es b+1 == 412 
    int B[2][3];
    for(int i =0,aux=2;i<2;i++){
        for(int j = 0;j<3;j++,aux+=2){
            B[i][j]=aux;
        }
    }
    // pasamos al 3d
    int A[2][2][3];
    for(int i=0 ,aux=2;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<3;k++,aux+=2){
                A[i][j][k]=aux;
            }
        }
    }
    cout<<*(A+0)<<endl;//primer elemento i
    cout<<A[0][0]<<endl;//primer elemento
    cout<<*(A+0)+1<<endl;// primer elemento, segundo elemento(arr)
    cout<<A[0][1]<<endl;//primer elemento, segundo elemento(arr)
    cout<<&A[0][1][2]<<endl;// primer elemento,segundo elemento (arr),tercer elemento 
    cout<<(*(A+0)+1)+2<<endl;
    cout<<*(*(A+3)+1)-(*(*A+1))<<endl;// sale 72 byts pero bota la cantidad de enteros que los separa 72/4
    return 0;
}