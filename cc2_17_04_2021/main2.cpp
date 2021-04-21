#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
//multiplicacion de matriz l
void variables(int &ai,int &aj,int &bi,int &bj){
    cout<<"ingrese el numero de filas de matris1: ";cin>>ai;
    cout<<"ingrese el numero de columnas de matris1: ";cin>>aj;
    cout<<"\ningrese el numero de filas de matris2: ";cin>>bi;
    cout<<"ingrese el numero de columnas de matris2: ";cin>>bj;
}
void numrand(int *arr,int sizeI,int sizeJ){
    int *pt = arr;
    for(int i = 0;i<sizeI*sizeJ;i++){
        *pt = 1+rand()%15;pt++;
    }
}
void imprArr(int *arr,int sizeI,int sizeJ){
    int *ptr = arr;
    for(int i =0;i<sizeI;i++){
        for(int j=0;j<sizeJ;j++,ptr++){
            cout<<*ptr<<"\t";///
        }
        cout<<endl;
    }
    cout<<endl;
}
void multiplicacion(int *matris1,int sizeIa,int sizeJa,int *matris2,int sizeIb,int sizeJb,int *matris3){
    int *m1 = matris1,*m2=matris2,*m3=matris3,*m2b=matris2,*m1b=matris1;
    for(int i=0;i<sizeIa;i++){
        for(int u = 0; u<sizeJb;u++){
            int suma =0;
            for(int j=0;j<sizeJa;j++){
                suma+=(*m1b)*(*m2b);m1b++;
                for(int i=0;i<sizeJb;i++){m2b++;}
            }*m3=suma;m3++;m1b = m1;m2++;m2b = m2;suma=0;
        }for(int i=0;i<sizeJa;i++){m1++;}m2=matris2;m2b=m2;m1b=m1;
    }

}

int main(){
    int ai,aj,bi,bj;
    variables(ai,aj,bi,bj);
    if(aj!=bi){
        cout<<"\t\t---error---\n";
        cout<<"\tNo se puede multiplicar esas matrices !!!";
    }
    else{
        int *a = new int [ai*aj];//[4][3]
        int *b = new int [bi*bj];//[3][2]
        int *c = new int [ai*bj]; //[4][2]
        srand(time(NULL));
        numrand(a,ai,aj);
        imprArr(a,ai,aj);
        numrand(b,bi,bj);
        imprArr(b,bi,bj);
        //multi
        multiplicacion(a,ai,aj,b,bi,bj,c);
        cout<<"multiplicacion: \n";
        imprArr(c,ai,bj);
        delete[] a;
        delete[] b;
        delete[] c;
    }

    return 0 ;
}