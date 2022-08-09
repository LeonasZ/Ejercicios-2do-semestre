//Nombre:
//Guia N°:
/*Ejercicio:

*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void cargarVector(int vec[],int tam);
int aleatorio(int nmax, int nmin);
void mostrarVector (int vec[],int tam);
void valorMin (int vec[],int tam);
void valorMax (int vec[],int tam);
void cupoMin (int vec[],int tam);
void cupoMax (int vec[],int tam);
void perteneceVec(int vec[],int tam,int num);
void perteneceVecDistinta(int vec[],int tam,int num);
void repiteNro(int vec[],int tam,int num);
int main(void){
setlocale(LC_CTYPE,"Spanish");


const int tam = 10;
int vec[tam];
int num;
cargarVector(vec,tam);
mostrarVector(vec,tam);
valorMin(vec,tam);
valorMax(vec,tam);
cupoMin(vec,tam);
cupoMax(vec,tam);


cout<<"ingrese un numero para saber si es parte del vector: ";
cin>>num;

perteneceVec(vec,tam,num);

perteneceVecDistinta(vec,tam,num);

repiteNro(vec,tam,num);

	return 0;
}

void cargarVector(int vec[],int tam){
    srand(time(NULL));
    int num;
    for (int i = 0 ; i < tam ; i++){
        num = aleatorio(100,1);
        vec[i] = num;
    }
}

int aleatorio(int nmax, int nmin){
    int numerosvec;
    numerosvec = (nmin + rand() % (nmax + 1 - nmin));
    return numerosvec;
}

///consigna 1
void valorMin (int vec[],int tam){
    int nromin;
    nromin = vec[0];
    for (int i = 1 ; i < tam ; i++){
        if(vec[i] < nromin){
            nromin = vec[i];
        }
    }
    cout<<"El valor minimo del vector es : "<< nromin<<endl;
}

///consigna 2
void valorMax (int vec[],int tam){
    int nromax;
    nromax = vec[0];
    for (int i = 1 ; i < tam ; i++){
        if(vec[i] > nromax){
            nromax = vec[i];
        }
    }
    cout<<"El valor maximo del vector es : "<< nromax <<endl;
}

///consigna 3
void cupoMin (int vec[],int tam){
    int nromin,posmin;
    nromin = vec[0];
    for (int i = 1 ; i < tam ; i++){
        if(vec[i] < nromin){
            nromin = vec[i];
            posmin = i + 1;
        }
    }
    cout<<"La posicon del valor minimo del vector es : "<< posmin <<endl;
}

///consigna 4
void cupoMax (int vec[],int tam){
    int nromax,posmax;
    nromax = vec[0];
    for (int i = 1 ; i < tam ; i++){
        if(vec[i] > nromax){
            nromax = vec[i];
            posmax = i + 1;
        }
    }
    cout<<"La posicon del valor maximo del vector es : "<< posmax <<endl;
}
///consigna 5
void perteneceVec(int vec[],int tam,int num){
    bool esta=0;
    for(int i=0;i<tam;i++){
        if(num == vec[i]){
            esta=1;
        }
    }
    if(esta==1){
        cout<<"Si pertenece"<<endl;
    }
    else{
        cout<<"No pertenece"<<endl;
    }
}
///consigna 6
void perteneceVecDistinta(int vec[],int tam,int num){
    bool esta=0;
    int pos;
    for(int i=0;i<tam;i++){
        if(num == vec[i]){
            esta= 1 ;
            pos = i + 1;
        }
    }
    if(esta==1){
        cout<<"el num si esta, en la posicion: "<<pos<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
}
///consigna 7
void repiteNro(int vec[],int tam,int num){
    int cont=0;
    for(int i=0;i<tam;i++){
        if(vec[i] == num){
            cont++;
        }
    }
    if(cont>0){
    cout<<"El nro se repite "<< cont <<" veces en el vector."<<endl;
    }
    else{
        cout<<"El nro no se repite, ni se encuentra en el vector. "<<endl;
    }
}

void mostrarVector (int vec[],int tam){
    for (int i = 0 ; i < tam ; i++){
        cout<<vec[i]<<"\t ";
    }
    cout<<endl<<endl;
}
