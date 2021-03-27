#include <iostream>

using namespace std;

int main(){
  /*  int x,y;
    //int &a[]={x,y};//error   
    int *a[]={&x,&y}; //buena

    int *b;
    char *c;
    void *d;//general
    //c=a;//c //error
    d=(int*)b;
*/    //////////////////////////////////////}

    int x =5;
    int *p = &x;
    *p=6;
    int **pp = &p ;//puntero que apunta a otro puntero
    cout<<*(*pp);

    return 0;
}