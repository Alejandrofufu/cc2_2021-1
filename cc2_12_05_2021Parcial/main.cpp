#include <iostream>
using namespace std;

void Sort(int *ar, int n)
{
    int writes = 0;
    int *inicio2 = ar;
    for (int cycle = 0; cycle <= n - 2; cycle++,inicio2++) {
        //int item = ar[cycle];
        int *item = ar;
        int piv = cycle;
        int *inicio = ar;inicio++;
        for (int i = cycle+1; i < n; i++){
            if (*inicio< *item){
                piv++;
                inicio++;
            }
            inicio++;
        }
        if (piv == cycle)
            continue;
        while (*item == *inicio){//Descarta repetidos
            piv += 1;inicio++;
        }
        if (piv != cycle) {//Encontró la posición del elemento
            swap(*item,*inicio);
            writes++;
        }
        while (piv != cycle) { //Hace lo mismo para el resto del array
            piv = cycle;
            inicio = inicio2;
            for (int i = cycle + 1; i < n; i++)
                if (*inicio2 < *item)
                    piv += 1;inicio++;
                    while (*item == *inicio)
                        piv += 1;inicio++;
            if (*item != *inicio) {
                swap(*item, *inicio);
                    writes++;
            }
        }
    }
}

int main()
{
 int ar[] = { 3, 6, 13, 19, 0, 11, 21, 4 };
 int n = sizeof(ar) / sizeof(ar[0]);
 Sort(ar, n);
 cout << "Después de ordenar : " << endl;
 for (int i = 0; i < n; i++)
 cout << ar[i] << " ";
 cout << endl;
 return 0;
}