//Nombre:
//Guia N°:
/*Ejercicio:
1) Una empresa vende 5 diferentes tipos de artículos en 3 sucursales. Por cada venta que realiza, se anotaron los siguientes datos:
- Nro. de artículo (1 a 5)
- Nro. de sucursal (1 a 3)
- Cantidad vendida
Este lote finaliza con un registro con nro. de artículo igual a cero. Puede haber más de un registro para el mismo artículo en la misma sucursal. Se desea determinar e informar:
a) Un listado con la cantidad de artículos vendidos en cada sucursal, con el siguiente formato:

            Artículo 1  Artículo 2  Artículo 3  Artículo 4  Artículo 5
Sucursal 1   xxxxx       xxxxx       xxxxx       xxxxx       xxxxx
Sucursal 2   xxxxx       xxxxx       xxxxx       xxxxx       xxxxx
Sucursal 3   xxxxx       xxxxx       xxxxx       xxxxx       xxxxx

b) Informar cual fue el nro. de artículo más vendido en total en cada una de las tres sucursales.

*/
#include <iostream>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

int aleatorio(int nmax,int nmin);
void cargarMatriz(int mat[3][5],int filas,int columnas);
void mostrarMatriz(int mat[3][5],int filas,int columnas);
void artMasVendidoxSucursal(int mat[3][5],int filas,int columnas);
int main(void){
    setlocale(LC_CTYPE,"Spanish");
    srand(time(NULL));

    const int filas=3, columnas=5;
    int mat[3][5]= {};
//    cargarMatriz(mat,filas,columnas);
//    mostrarMatriz(mat,filas,columnas);

    int nrosuc,nroart,cantv;
    cout<<"Ingrese el nro Articulo: ";
    cin>>nroart;

    while(nroart!=0){
        cout<<"Ingrese el nro de Sucursal: ";
        cin>>nrosuc;
        cout<<"Ingrese la cantidad vendida: ";
        cin>>cantv;
        cout<<endl;
        mat[nrosuc-1][nroart-1]+=cantv;

        cout<<"Ingrese el nro Articulo: ";
        cin>>nroart;
    }

    mostrarMatriz(mat,filas,columnas);

    artMasVendidoxSucursal(mat,filas,columnas);

	return 0;
}
///Informar cual fue el nro. de artículo más vendido en total en cada una de las tres sucursales.
void artMasVendidoxSucursal(int mat[3][5],int filas,int columnas){
    int maxven;
    for(int i=0;i<filas;i++){
        maxven = mat[i][0];
        int posartic = 0;
        for(int j=0;j<columnas;j++){
            if(mat[i][j] >= maxven && mat[i][j]!=0){
                maxven = mat[i][j];
                posartic = j + 1;
            }
        }
        if(posartic!=0){
        cout<<"En la sucursal #"<<i+1<< " el articulo #"<<posartic<<" fue el mas vendido."<<endl;
        }
        else{
            cout<<"En la sucursal #"<<i+1<< " no se vendieron articulos"<<endl;
        }
    }


}

int aleatorio(int nmax,int nmin){
    int num;
    num = (nmin + rand() % (nmax + 1 - nmin));
    return num;
}
void cargarMatriz(int mat[3][5],int filas,int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            mat[i][j] = aleatorio(2,2);
        }
    }
}
void mostrarMatriz(int mat[3][5],int filas,int columnas){
    cout<<endl;
    cout<<"\t    Artículo 1      Artículo 2      Artículo 3      Artículo 4      Artículo 5"<<endl;
    for(int i=0;i<filas;i++){
        cout<<"Sucursal #"<<i+1<<"\t";
        for(int j=0;j<columnas;j++){
            cout<<mat[i][j] << "\t\t";
        }
        cout<<endl;
    }
    cout<<endl;
}





