#include <iostream>
using namespace std;

class Suma{
    int x;
    public:
    Suma(int a_){
            x=a_;
        }
        int operator()(int b){
            return x+b;
        }
};

template <class T>
class fib{// F(2) = F(1) + F(0);
    public:
    void operator()(int *p,T op){//{0,1},{1,1},{2,1},{1,5}
        *p = *(p+1);//*p continene el 2do valor
        *(p+1) = op(*p);// op tiene configurado el 1er valor
    }
};

int main(){
    int a[2] = {0,1};
    fib<Suma> f;

    for(int i=0;i<10;i++){
        cout<<*a<<" ";
        f(a,Suma(*a));
    }
}