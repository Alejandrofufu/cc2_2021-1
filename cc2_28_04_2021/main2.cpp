#include <iostream>
using namespace std;

int tam(char*arrT){
    int tam=0;
    for(;*arrT;tam++,arrT++){}
    return tam;
}

int main(){
    char c[10];
    c[0] = 'c';
    c[1] = '+';
    c[2] = '+';
    c[3] = '\0';
    
    cout<<tam(c)<<endl;
    cout<<c[0]<<endl;



    return 0;
}