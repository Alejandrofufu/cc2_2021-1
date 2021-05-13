#include <iostream>
using namespace std;
void f(){
    static char * c1 = "c++"; //  no  es global pero si es estatico 
    char c2[] = "c++ ";// no esta en global ni estatico sino en el stack 
    char c4[] = "c++ "; // variable dinamica  esta en stack , variable local csm
}

int main(){
    //variables locales
    char *s = "c++";// estatico 
    static char *j = "c++";// correcto 
    //s[0] = 'c'  esto no se puede csm 
    char c[] = "java";
    cout<<c[0]<<"\n"; // 'j' si se puede 



    return 0;
}