//Nombre:
//Guia N°:
/*Ejercicio:
1. Hacer una función que reciba como parámetros una matriz de enteros de 10x10 y un número entero (entre 0 y 9), y devuelva el máximo de la fila indicada por el segundo parámetro.
2. Hacer una función que reciba como parámetros una matriz de enteros de 10x10 y un número entero (entre 0 y 9), y devuelva la posición que ocupa el máximo en la fila indicada por el segundo parámetro.
3. Hacer una función que reciba como parámetros una matriz de enteros de 10x10 y un número entero (entre 0 y 9), y devuelva la suma de todos los componentes de la columna indicada por el segundo parámetro.
4. Hacer una función que reciba como parámetros una matriz de enteros de 10x10 y un número entero (entre 0 y 9), y devuelva la cantidad de componentes positivos de la columna indicada por el segundo parámetro.
5. Hacer una función que reciba como parámetros una matriz de enteros de 10x10, y devuelva la suma de todos los componentes de la matriz.
*/
#include <iostream>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
int aleatorio(int nmax,int nmin);
void cargarMatriz(int mat[10][10],int tam);
void mostrarMatriz(int mat[10][10],int tam);
void filaMax(int mat[10][10],int tam, int nro);
void posMax(int mat[10][10],int tam, int nro);
void sumaColumna(int mat[10][10],int tam, int nro);
void cantPos(int mat[10][10],int tam, int nro);
void sumaMatriz(int mat[10][10],int tam);

    int main(void){
        setlocale(LC_CTYPE,"Spanish");
        srand(time(NULL));
        const int tam =10;
        int mat[10][10];
        int nro;
        cargarMatriz(mat,tam);
        mostrarMatriz(mat,tam);

        cout<<"Ingrese la fila en la que desea buscar el maximo valor (nro del 1 al 10): ";
        cin>>nro;

        filaMax(mat,tam,nro);
        posMax(mat,tam,nro);

        cout<<"Ingrese la columna en la que desea buscar el maximo valor (nro del 1 al 10): ";
        cin>>nro;
        sumaColumna(mat,tam,nro);

        cantPos(mat,tam,nro);

        sumaMatriz(mat,tam);

        return 0;
    }
    ///consigna 1: devuelva el máximo de la fila indicada por el segundo parámetro.
    void filaMax(int mat[10][10],int tam, int nro){
        int maxfila;
        maxfila = mat[nro-1][0];
        for(int i=0;i<tam;i++){
            if(mat[nro-1][i] > maxfila){
                maxfila = mat[nro-1][i];
            }
        }
        cout<<"El numero maximo de la fila #"<<nro<<" es el: "<<maxfila<<endl;
    }
    ///consigna 2: devuelva la posición que ocupa el máximo en la fila indicada por el segundo parámetro.
    void posMax(int mat[10][10],int tam, int nro){
        int maxfila,maxpos;
        maxfila = mat[nro-1][0];
        for(int i=0;i<tam;i++){
            if(mat[nro-1][i] > maxfila){
                maxfila = mat[nro-1][i];
                maxpos= i + 1;
            }
        }
        cout<<"El numero maximo de la fila #"<<nro<<" esta en la posicion: "<<maxpos<<endl;
    }
    ///consigna 3: devuelva la suma de todos los componentes de la columna indicada por el segundo parámetro.
    void sumaColumna(int mat[10][10],int tam, int nro){
        int sumatoria = 0;
        for(int i=0;i<10;i++){
            sumatoria += mat[i][nro-1];
        }
        cout<<"La sumatoria de la columna #"<<nro<<" es: "<<sumatoria<<endl;

    }
    ///consigna 4: devuelva la cantidad de componentes positivos de la columna indicada por el segundo parámetro.
    void cantPos(int mat[10][10],int tam, int nro){
        int i,cont=0;
        for(int i=0;i<10;i++){
            if(mat[i][nro-1] > 0){
                cont++;
            }
        }
        cout<<"La cantidad de elementos positivos de la columna #"<<nro<<" es: "<<cont<<endl;
    }
    ///consigna 5: devuelva la suma de todos los componentes de la matriz.
    void sumaMatriz(int mat[10][10],int tam){
        int sumatotal = 0;
        for(int i=0;i<tam;i++){
            for(int j=0;j<tam;j++){
                sumatotal += mat[i][j];
            }
        }
        cout<<"La sumatoria total de todos los elementos de la matriz es: "<<sumatotal<<endl;
    }

    int aleatorio(int nmax,int nmin){

        int num;
        num = (nmin + rand() % (nmax + 1 - nmin));
        return num;
    }
    void cargarMatriz(int mat[10][10],int tam){
        for(int i=0;i<tam;i++){
            for(int j=0;j<tam;j++){
                mat[i][j] = aleatorio(2,2);
            }
        }
    }
    void mostrarMatriz(int mat[10][10],int tam){
        for(int i=0;i<tam;i++){
            for(int j=0;j<tam;j++){
               cout<< mat[i][j]<< "  ";
            }
            cout<<endl;
        }
        cout<<endl;

    }
