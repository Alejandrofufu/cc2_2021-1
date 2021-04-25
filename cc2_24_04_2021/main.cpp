#include <iostream>
using namespace std;
void imprimir (int p[5]){
    cout << p <<endl; // int * 
    cout<<&p;// direccion de p 
    cout<<sizeof(p);// 4 - 8
} 
int main(){
    int a[5] = {18,51,25,32,28};
    int *p = a;
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<*a<<endl;





    return 0;
}