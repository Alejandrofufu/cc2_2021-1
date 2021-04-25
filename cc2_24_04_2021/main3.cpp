#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
// suma horaria de matrices
void numrand(int (*matr)[3][3],int size){
    if(size == 2)
        matr++;
    int (*arr)[3] = *matr;
    int *ptint = *arr;
    for(;arr<*(matr+1);arr++){
        for(;ptint<*(arr+1);ptint++){
            *ptint = 1+rand()%5;
        }
    }        
}
void imprArr(int (*matr)[3][3],int size){
    if(size == 2){
        matr ++;
    }
    if(size == 3){
        matr ++;matr ++;
    }
    int (*arr)[3] = *matr;
    int *ptint = *arr;
    for(;arr<*(matr+1);arr++){
        for(;ptint<*(arr+1);ptint++){
            cout<<*ptint<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
void sumahoraria (int (*matr)[3][3]){
    int (*m2A)[3]= *matr,(*m1B)[3]=*matr,(*m2B)[3]=*matr;
    int *m1 =*m2A;m2A++;m1B++;m1B++;m1B++;m1B++;m2B++;m2B++;m2B++;m2B++,m2B++;m1B--;
    int *m2 = *m1B;m1B++;m2B++;int *m3 = *m2B;m2B--;int (*centA)=*m2A;centA++;
    int *pA = m1,*pB = m2;int (*m3A)[3]=m2A;m3A++;int (*centB)=*m1B;centB++;
    for(int i=0;i<9;i++){
        int aux =1;bool cambio = true;int derecha=0,izq=0,up = 0,abajo=0;
        for(int j =0 ; j <4;j++){
            aux*= *m1 + *m2;
            if(m1){
                if(m1<*m2A){
                    m1++;
                    if(m1==*m2A){m1--;
                        for(int i=0;i<3;i++){m1++;}
                    }
                }
                else if(m1<*m3A && m1>*m2A){
                    if(m1 == centA){
                        m1++;j = 4;
                    }
                    else{
                        m1++; 
                        if(m1==*m3A){m1--;
                            for(int i=0;i<3;i++){m1++;}
                        }
                    }
                }

                else if(m1>*m3A){
                    m1--;
                }
                else if(m1 == *m3A || m1 == *m2A){
                    for(int i =0;i<3;i++){m1--;}
                }
                else{m1--;}
            }
            if(m2){
                if(i%2){//impar
                    if(cambio){
                        if(pB == *m1B){
                            derecha++;cambio = false;m2++;
                        }
                        else if(pB<*m1B){
                            abajo++;cambio = false;for(int i=0;i<3;i++){m2++;}
                        }
                        else if(pB<*m2B && pB>*m1B){
                            izq++;cambio = false;m2--;
                        }
                        else if(pB>*m2B){
                            up++;cambio = false;for(int i=0;i<3;i++){m2--;}
                        }
                    }
                    else{
                        if(derecha){
                            if(j<2){m2++;}
                            else{
                                for(int i=0;i<3;i++){m2++;}
                            }

                        }
                        else if(izq){
                            if(j<2){m2--;}
                            else{
                                for(int i =0;i<3;i++){m2--;}
                            }
                        }
                        else if(up){
                            if(j<2){for(int i=0;i<3;i++){m2--;}}
                            else{
                                m2++;
                            }
                            
                        }
                        else if(abajo){
                            if(j<2){for(int i=0;i<3;i++){m2++;}}
                            else{
                                m2--;
                            }
                        }
                    }
                }
                else{//par
                    if(cambio){
                        if(pB<*m1B){
                            m2++;
                            if(m2 == *m1B){
                                m2--;for(int i = 0;i<3;i++){m2++;}izq++;cambio = false;
                            }
                            else{abajo++;cambio = false;}
                        }
                        else if(pB== centB){
                            m2++;
                        }
                        else if(pB>=*m2B){
                            if(m2== *m2B){for(int i=0;i<3;i++){m2--;}derecha++;cambio= false;}
                            else{
                                m2--;up++;cambio = false;
                            }
                        }
                    }
                    else{
                        if(derecha){
                            m2++;
                        }
                        else if(izq){
                            m2--;
                        }
                        else if(up){
                            for(int i=0;i<3;i++){m2--;}
                        }
                        else if(abajo){
                            for(int i=0;i<3;i++){m2++;}
                        }

                    }

                }
                
            }
        }
        *m3=aux;m3++;pA++;pB++;m1=pA;m2 = pB;//cambio = false;
    }
}


int main(){
    int a [3][3][3];
    srand(time(NULL));
    cout<<"Matris A: \n";
    numrand(a,1);//A
    imprArr(a,1);
    cout<<"Matris B: \n";
    numrand(a,2);//B
    imprArr(a,2);
    cout<<"Suma horaria: \n";
    sumahoraria(a);
    imprArr(a,3);//C
    
    return 0;
}