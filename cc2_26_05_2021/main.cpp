#include <iostream>
using namespace std;
//memoria dimamica con malloc calloc realloc 1D
int main(){
    int *p;
    cout<<"con malloc: \n";
    p = (int*)malloc(sizeof(int));// reservamos memoria 
    *p = 5; // heap
    free(p);//liberamos memoria
    p = (int *)malloc(5*sizeof(int));
    for(int i=0;i<5;i++){
        //p[i] = 10;
        cout<<p[i]<<"\t";
    }
    free(p);
    cout<<"\n\ncon calloc: \n";
    p = (int*)calloc(5,sizeof(int));
    for(int i =0;i<5;i++){
        cout<<p[i]<<"\t";
    }
    //free(p);
    cout<<"\n\ncon realloc (p,10*sizeof(int)) :\n";
    p = (int*)realloc(p,10*sizeof(int));// reasigna memoria 2
    for(int i = 5;i<10;i++){
        p[i]=20;
    }
    for(int i = 0;i<10;i++){
        cout<<p[i]<<"\t";
    }
    free(p);
    

    return 0;
}