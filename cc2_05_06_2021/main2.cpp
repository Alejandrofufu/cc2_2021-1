#include <iostream>
using namespace std;

void mostrarTablero(int **tablero_,int filas_,int columnas_){
    for(int **arrTablero = tablero_;arrTablero<tablero_+filas_;arrTablero++){
        for(int *piedrasArr = *arrTablero; piedrasArr<*arrTablero+columnas_;piedrasArr++){
            if(*piedrasArr == 1 || *piedrasArr == 2)
                cout<<"| "<<*piedrasArr;
            else{
                cout<<"| ";
            }
        }
        cout<<"\n";
    }
    cout<<endl;
}

// verificacion de figuritas 

//eliminacion de piedras si estan encerradas

void fichas(int **tablero_,int filas_,int columnas_,int piedra_){
    int **arrTablero = tablero_,*piedrasArr = *arrTablero,jfilas = 0,jcolumnas = 0;
    cout<<"\nescriba la pocicion de su ficha: ";
    cout<<"\nFilas :";cin>>jfilas;
    cout<<"columnas: ";cin>>jcolumnas;
    for(;arrTablero<=tablero_+jfilas;arrTablero++){
        for(; piedrasArr<*arrTablero+jcolumnas;){piedrasArr++;}
    }
    if(*piedrasArr == 1 || *piedrasArr == 2){
        cout<<"\nNo es posible colocar en esa posicion\n";
        fichas(tablero_,filas_,columnas_,piedra_);
    }
    else
        *piedrasArr = piedra_;
}

bool tableroLleno(int **tablero_,int filas_,int columnas_){
    int contador = 0,piedraA = 0;
    for(int **arrTablero = tablero_;arrTablero<tablero_+filas_;arrTablero++){
        for(int *piedrasArr = *arrTablero; piedrasArr<*arrTablero+columnas_;piedrasArr++){
            if(*piedrasArr == 1 || *piedrasArr == 2){
                contador +=1;
                if(*piedrasArr == 1)
                    piedraA+=1;
            }
        }
    }
    if(contador == filas_*columnas_){
        cout<<"--------game Over--------\n";
        cout<<(piedraA>(filas_*columnas_)-piedraA)?("ganador jugador 1 !!!"):("ganador jugador 2 !!!");
        return true;
    }
    return false;
}


// juego del "GO"
//blancas 1
//negras  2
int main(){
    int filas = 0,columnas = 0;
    cout<< "---------juego del Go------------";
    cout<<"\ncuantas filas tendra el tablero: ";cin>>filas;
    cout<<"cuantas columnnas tendra el tablero: ";cin>>columnas;
    bool gameOver = false;
    //separamos memoria
    int **tablero = new int *[filas];
    for(int **i= tablero;i<tablero+filas;i++){
        *i = new int[columnas];
    }
    int piedra = 1;cout<<endl;
    mostrarTablero(tablero,filas, columnas);// mostramos el tablero vacio
    
    while(!gameOver){
        cout<<"jugadro 1\n";
        fichas(tablero,filas,columnas,piedra);
        mostrarTablero(tablero,filas, columnas);
        piedra+=1;
        cout<<"jugador 2\n";
        fichas(tablero,filas,columnas,piedra);
        mostrarTablero(tablero,filas,columnas);
        piedra-=1;
        if(tableroLleno(tablero,filas,columnas))
            gameOver = true;
    }
    //liberamos memoria
    for(int **i = tablero;i<tablero+filas;i++){
        delete[] *i;
    }
    delete[] tablero;

    return 0;
}