#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


void numrand(int *arr,int size){
    int *pt = arr;
    for(int i = 0;i<size;i++){
        *pt = rand()%100;pt++;
    }
}
void imprArr(int *arr,int size){
    int *ptr = arr;
    cout<<"arr = ";
    for(int i =0;i<size;i++){
        cout<<*ptr<<"\t";ptr++;
    }cout<<endl;
}
int main(){
    int c[10];
    srand(time(NULL));
    numrand(c,10);
    imprArr(c,10);
    int *inicio=c,*ptr1=c,*ptr2=c,*pivote=c,*final=c;ptr2++,pivote++;
    for(int i=0;i<10;i++){final++;}
    for(;ptr2!=final;ptr1++,ptr2++,pivote++){
        if(*ptr1>*ptr2){
            for(int j=pivote-inicio;j>0;j--,ptr1--,ptr2--){
                if(*ptr1>*ptr2){
                    int aux = *ptr1;
                    *ptr1=*ptr2;
                    *ptr2=aux;
                }
            }
            ptr1 = pivote;ptr2=pivote;ptr1--;
        }
        //imprArr(c,10);
    }
    imprArr(c,10);
    return 0;
}