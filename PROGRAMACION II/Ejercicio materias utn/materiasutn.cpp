//Nombre:
//Guia N°:
/*Ejercicio:
LAS AUTORIDADES DE LA CARRERA TUP DE LA UTN ESTÁN REALIZANDO UN
ANÁLISIS DE LOS CURSOS VIRTUALES DE LAS DISTINTAS
MATERIAS. POR CADA UNA DE LAS 20 MATERIAS DE LA CARRERA TIENE LA SIGUIENTE INFORMACIÓN
•
NÚMERO DE MATERIA (ENTRE 1 Y 20), NOMBRE, CANTIDAD DE ALUMNOS INSCRIPTOS, CANTIDAD DE PROFESORES
ADEMÁS POR CADA INGRESO DE LOS ESTUDIANTES AL AULA VIRTUAL SE REGISTRA LO SIGUIENTE:
•
LEGAJO, FECHA DE ACCESO (DÍA Y MES), NÚMERO DE LA MATERIA A LA  QUE INGRESO, CANTIDAD DE HORAS (NÚMERO REAL)
EL FIN DE LOS DATOS SE INDICA CON UN NÚMERO DE LEGAJO IGUAL A 0.
SE QUIERE RESPONDER LAS SIGUIENTES PREGUNTAS:
a)LAS MATERIAS QUE NO TUVIERON ACCESO DE ALUMNOS NUNCA
b)LA MATERIA QUE MÁS CANTIDAD DE HORAS REGISTRO DE ACCESO DE ALUMNOS
c)POR CADA MATERIA Y DÍA DE MARZO, LA CANTIDAD DE ACCESOS DE ALUMNOS A LAS AULAS VIRTUALES.
•
HACER UN PROGRAMA EN EL MARCO DE UN PROYECTO DE CODEBLOCK CON UN MENÚ CON OPCIONES PARA CARGAR LOS DATOS,
MOSTRAR CADA PUNTO Y SALIR DEL PROGRAMA.
*/
#include <iostream>
#include <locale.h>
#include <string>
using namespace std;
void cargarMaterias(string *vec,int tam);
void mostrarMaterias(string *vec,int tam);
void cargarIngresos(float *vec,int mat[][31],int cantmaterias);
void materiasSinacceso(float *vec_horas,string *nombre_materias,int cantmaterias);
void mayorHoras(float *vec_horas,string *nombre_materias,int cantmaterias);
void puntoC(int mat[][31],string *nombre_materias,int cantmaterias);

int main(void){
setlocale(LC_CTYPE,"Spanish");
    const int cantmaterias=10;
    string nombre_materias[cantmaterias];
    float vec_horas[cantmaterias] = {};
    int mat_C[cantmaterias][31]={};
    int op;
    do{
        system("cls");
        cout<<"1 - Cargar Materias"<<endl;
        cout<<"2 - Cargar Ingresos"<<endl;
        cout<<"3 - Materias SIN acceso"<<endl;
        cout<<"4 - Materia que mas cantidad de horas de acceeso registra"<<endl;
        cout<<"5 - Por cada materia y dia de marzo, cantidad de accesos al AV"<<endl;
        cout<<"6 - Mostrar Materias"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<endl<<"Ingrese la opcion que desea elegir: ";
        cin>>op;

        switch(op){
            case 1:
                cargarMaterias(nombre_materias,cantmaterias);
                break;
            case 2:
                cargarIngresos(vec_horas,mat_C,cantmaterias);
                break;
            case 3:
                materiasSinacceso(vec_horas,nombre_materias,cantmaterias);
                break;
            case 4:
                mayorHoras(vec_horas,nombre_materias,cantmaterias);
                break;
            case 5:
                puntoC(mat_C,nombre_materias,cantmaterias);
                break;
            case 6:
                mostrarMaterias(nombre_materias,cantmaterias);
                break;
            case 0:
                cout<<"Saliste."<<endl;
                break;
            default:
                cout<<"La opcion ingresada no es correcta."<<endl;
                system("pause");
                break;
        }


    }while(op != 0);


	return 0;
}
/// opcion 1: Cargar Materias ; NÚMERO DE MATERIA (ENTRE 1 Y 20), NOMBRE, CANTIDAD DE ALUMNOS INSCRIPTOS, CANTIDAD DE PROFESORES
void cargarMaterias(string *vec,int tam){
    system("cls");
    int nromat;
    string nombremat;
    for(int i=0;i<tam;i++){
        cout<<"Ingrese el numero de la materia: ";
        cin>>nromat;
        cout<<"Ingrese el nombre de la materia: ";
        cin>>nombremat;
        vec[nromat-1]=nombremat;
    }

}

/// opcion 2: Cargar Ingresos ; LEGAJO, FECHA DE ACCESO (DÍA Y MES), NÚMERO DE LA MATERIA A LA  QUE INGRESO, CANTIDAD DE HORAS (NÚMERO REAL)
void cargarIngresos(float *vec_horas,int mat[][31],int cantmaterias){
    system("cls");
    int leg,dia,mes,nromat;
    float horas;
    cout<<"Ingrese nro de legajo: ";
    cin>>leg;
    while(leg != 0){
        cout<<"Fecha de acceso (Dia): ";
        cin>>dia;
        cout<<"Fecha de acceso (Mes): ";
        cin>>mes;
        cout<<"Numero de materia a la que ingreso: ";
        cin>>nromat;
        cout<<"Cantidad de horas que ingreso: ";
        cin>>horas;
        vec_horas[nromat-1]+=horas;

        if(mes==3){
            mat[nromat-1][dia-1]++;
        }

        cout<<"Ingrese nro de legajo: ";
        cin>>leg;
    }
}
/// opcion 3 : Materias SIN acceso
void materiasSinacceso(float *vec_horas,string *nombre_materias,int cantmaterias){
    system("cls");
    cout<<"Materias que no tuvieron acceso de alumnos nunca:"<<endl;
    for(int i=0;i<cantmaterias;i++){
        if(vec_horas[i]==0){
            cout<<"Materia #"<<i+1<<": "<<nombre_materias[i]<<endl;
        }
    }
    system("pause");
}
///opcion 4 : Materia que mas cantidad de horas de acceeso registra.
void mayorHoras(float *vec_horas,string *nombre_materias,int cantmaterias){
    system("cls");
    float mayor = vec_horas[0];
    string mayormat = nombre_materias[0];
    for(int i=1;i<cantmaterias;i++){
        if(vec_horas[i]>mayor){
            mayor = vec_horas[i];
            mayormat = nombre_materias[i];
        }
    }
    cout<<"La materia que mas cantidad de horas registra de acceso de alumnos es: "<< mayormat<<endl;
    system("pause");
    }

/// opcion 5 : Por cada materia y dia de marzo, cantidad de accesos al AV.
void puntoC(int mat_C[][31],string *nombre_materias,int cantmaterias){
    system("cls");
    cout<<"Por cada materia y dia de marzo, cantidad de accesos al AV"<<endl;
    for(int i=0;i<cantmaterias;i++){
        cout<<"Materia #"<<i+1<<": "<<nombre_materias[i]<<"\t\t";
        for(int j=0;j<31;j++){
            if(mat_C[i][j]!=0){
                cout<<"Dia: "<<j+1<<": "<<mat_C[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
    system("pause");
}


/// opcion 6 : Mostrar Materias.
void mostrarMaterias(string *vec,int tam){
    system("cls");
    for(int i=0;i<tam;i++){
        cout<<"Materia #"<<i+1<<": "<<vec[i]<<endl;
    }
    system("pause");
}

