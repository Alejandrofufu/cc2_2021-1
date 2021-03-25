#include <iostream>
using namespace std;

int main(){
    /*
    int a = 64;
    cout<<sizeof(a);*/

    int a = 5,*p=&a;
    int &c=a;
    cout<<c;
    //int &c{a};
    int *&q = p;
    *q = 7;
    cout<<"\n"<<c;
    cout<<"\n"<<q+2;
    cout<<"\n"<<*(q+2);
    cout<<"\n"<<&(*(q+2));
    
    return 0;
}