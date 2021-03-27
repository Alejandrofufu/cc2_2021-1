#include <iostream>
using namespace std;

int main(){
    char * titles[]={"aa","bb","cc"};
    char * bestbooks[3];
        bestbooks[0] = "bb";//redundancia, memoria mal usada 
    char ** bestbook[3];
    bestbook[0] =&titles[1];
    
    

    return 0;
}