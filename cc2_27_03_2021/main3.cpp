#include <iostream>
using namespace std;
//aritmetica de punteros
int main(){
    int a = 5;
    int *p = &a;
    cout<< *(p+1);// contenido
    cout<< p+1;// memoria


    int A[5]={2,4,5,8,7};
    int*p;
    p=&A[0];
    cout<<"\n"<<p<<"\n";
    cout<<*p;

    p=A;
    cout<<"\n"<<*(p+1);
    cout<<"\n"<<*(p+2);

    int *p0 = A+1;
    int *p1 = A+2;
    cout<<"\n"<<p1 -p0; // 1 (int ) 4 bits
    int *p2 = A+3;
    cout<<p2 -p0; // 2(int) 8 bit

    return 0;
}